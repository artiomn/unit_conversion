/*
	functions.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "convarray.h"

long int pow10(long int n) {
// Возвращает 10 в степени n (целое положительное)
	long int nm = 10;
	if (!n) return(1);
	while ((--n) > 0) nm *= 10;
	return(nm);
}

double pow_(double base, int power) {
// Возвращает base в степени power
	register int pw = myabs(power);
	register double f_base = 1;
	if (!power) return(1);
	if (pw % 2 != 0) pw--, f_base = base; // Если степень нечётная
	while (pw > 1) base *= base, pw /= 2; // a^k = (a^2)^(k/2), для сокращения числа операций
	f_base *= base;
	if (power < 0) f_base = 1/f_base;
	return(f_base);
	
}

char* reverse(char* n) {
// Переворачивает строку
	register int i, j;
	register char c;
	for (i = 0, j = strlen(n) - 1; i < j;i++, j--) {
		c = n[i];
		n[i] = n[j];
		n[j] = c;
	}
	return(n);
}

void err_ft(int err_num) {
// Выводит ошибку и выходит
	switch (err_num) {
		case 0: usage(); //При нормальной работе вызова usage() не происходит.
		break;
		case 1: fprintf(stderr, "Memory allocation error\n");
		break;
		case 2: fprintf(stderr, "Conversion error!\n");
		break;
		case 3: fprintf(stderr, "Convertion specified illegaly!\n");
			usage();
		break;
		case 4: fprintf(stderr, "Invalid option!\n");
			usage();
		break;
		case 5:
		break;
		default: fprintf(stderr, "Unknown error has occured!\n");
	}
	exit(EXIT_FAILURE);
}

void* xmalloc(size_t sz) {
// frontend к malloc
	register void *ptr = malloc(sz);
	if (ptr == 0) err_ft(1);
	return(ptr);
}

void usage() {
// Справка
	register int i = 0;
	while (code_names[i++] != NULL);
	// Выделение под размер массива+число элементов*2 (для каждой " ,")
	char *pstr = (char*)xmalloc(sizeof(code_names) + 2*i); 
	i = 0;
	while (code_names[i] != NULL) {
	// Создаёт строку с вариантами преобразования, взятыми из массива опций
		strcat(pstr, code_names[i++]);
		strcat(pstr, ", ");
	}
	pstr[strlen(pstr) - 2] = (char)NULL; //Последний ", "
	printf("Usage: %s [-f{from_units}] [-t{to_units}] [-q] [-v] [value_1 value_2 ... value_n]\n\
-h - this help\n-q - quiet\n-v - verbose (cancel -q)\n-V - version\n\
Supported convertion units: %s\n", \
	pin, pstr);
	free(pstr);
}

/* EOF */

