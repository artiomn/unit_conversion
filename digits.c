/*
	digits.c
*/

#include <stdio.h>
#include "digits.h"
#include "functions.h"

double htof(const char* n) {
//Ввод Hex->Double
	register double nm = 0, nf = 0, sign = 1;
	if (*n == '-') {
		n++;
		sign = -1;
	}
	while (isxdigit(*n)) {
		if (isdigit(*n)) nm = 16*nm + *n - '0';
		else nm = 16*nm + tolower(*n) - 'a' + 10;
		n++;
	}
	if ('.' == *n++) {
	//Дробная часть
		register int i = 1;
		while (isxdigit(*n)) {
			if (isdigit(*n)) nf += (*n - '0')*pow_(16, -i);
			else nf += (tolower(*n) + 10 - 'a')*pow_(16, -i);
			i++, n++;
		}
		nm += nf;
	}
	return(sign*nm);
	
}

double btof(const char* n) {
//Ввод Bin->Double
	register double nm = 0, nf = 0, sign = 1;
	if (*n == '-') {
		n++;
		sign = -1;
	}
	while (*n == '1' || *n == '0') {
		nm = 2*nm + *n - '0';
		n++;
	}
	if ('.' == *n++) {
	//Дробная часть
		register int i = 1;
		while (*n == '1' || *n == '0') {
			nf += (*n - '0')*pow_(2, -i);
			n++, i++;
		}
		nm += nf;
	}
	return(sign*nm);
}

double otof(const char* n) {
//Ввод Oct->Double
	register double nm = 0, nf = 0, sign = 1;
	if (*n == '-') {
		n++;
		sign = -1;
	}
	while (*n >= '0' && *n <= '7') {
		nm = 8*nm + *n - '0';
		n++;
	}
	if ('.' == *n++) {
	//Дробная часть
		register int i = 1;
		while (*n >= '0' && *n <= '7') {
			nf += (*n - '0')*pow_(8, -i);
			n++, i++;
		}
		nm += nf;
	}
	return(sign*nm);

}

double rtof(const char* n) {
//Ввод Rome->int
	int isromedigit(char);
	double getrd(char);
	register long int nm = 0;
	register int ld, rd;
	// i = 1, v = 5, x = 10, l = 50, c = 100, m = 1000
	//В римских числах нет десятичных дробей
	while (isromedigit(*n)) {
		ld = getrd(*n); //левая
		if (isromedigit(*++n)) {
			//Есть пара
			rd = getrd(*n++); //правая
			if (rd <= ld) nm += ld + rd;
			else nm += rd - ld;
		}
		else
		{
			//Пара закончилась
			if (ld <= rd) nm += ld;
			else nm += ld - 2*rd; //rd уже была прибавлена
		}
	}
	return((double)nm);
}

//
// Функции вывода
//

void printdbl(const double nm) {
//Печать дробного
	printf(DBL_OUT_FMT, nm);
}

void printb(const double nm) {
//Bin
	char* btoa(double, char**);
	char *ar = 0;
	if (nm < 0) {
		btoa(-nm, &ar);
		printf("-%s%s", ar, NL_SYM);
	}
	else {
		btoa(nm, &ar);
		printf("%s%s", ar, NL_SYM);
	}
	free(ar);
}

void printh(const double nm) {
//Hex
	char* htoa(double, char**);
	char* ar = 0;
	if (nm < 0) {
		htoa(-nm, &ar);
		printf("-%s%s", ar, NL_SYM);
	}
	else {
		htoa(nm, &ar);
		printf("%s%s", ar, NL_SYM);
	}
	free(ar);
/*	register long int i = nm;
	nm < 0 ? printf("-%X\n", -i) : printf("%X\n", i); //Целая часть
*/
}

void printo(const double nm) {
//Oct
	char* otoa(double, char**);
	char* ar = 0;
	if (nm < 0) {
		otoa(-nm, &ar);
		printf("-%s%s", ar, NL_SYM);
	}
	else {
		otoa(nm, &ar);
		printf("%s%s", ar, NL_SYM);
	}
	free(ar);
}

void printr(const double nm) {
//Печать римского числа
	//Int в римские
	register int i, e;
	register long int n = nm;
	for (i = 0, e = n / 1000; i < e; i++) 
	#if SYM_SZ == 0
		putchar('M');
	#else
		putchar('m');
	#endif
	n %= 1000;
	if ((n / 100) == 9) 
	#if SYM_SZ == 0
		printf("CM");
	#else
		printf("cm");
	#endif
	else
	for (i = 0, e = n / 100; i < e; i++)
	#if SYM_SZ == 0
		printf("C");
	#else
		printf("c");
	#endif
	n %= 100;
	for (i = 0, e = n / 50; i < e; i++) 
	#if SYM_SZ == 0
		putchar('L');
	#else
		putchar('l');
	#endif
	n %= 50;
	if ((n / 10) == 4) 
	#if SYM_SZ == 0
		printf("XL");
	#else
		printf("xl");
	#endif
	else
	for (i = 0, e = n / 10; i < e; i++) 
	#if SYM_SZ == 0
		putchar('X');
	#else
		putchar('x');
	#endif
	n %= 10;
	switch (n) {
		case 0:
		case 1:
		case 2:
		case 3:
		#if SYM_SZ == 0
			for (i = 0; i != n; i++) putchar('I');
		#else
			for (i = 0; i != n; i++) putchar('i');
		#endif
		break;
		case 4:
		#if SYM_SZ == 0
			printf("IV");
		#else
			printf("iv");
		#endif
		break;
		case 5:
		#if SYM_SZ == 0
			putchar('V');
		#else
			putchar('v');
		#endif
		break;
		case 6:
		case 7:
		case 8:
		#if SYM_SZ == 0		
			putchar('V');
			for (i = 0; i != n - 5; i++) putchar('I');
		#else
			putchar('v');
			for (i = 0; i != n - 5; i++) putchar('i');
		#endif
		break;
		case 9:
		#if SYM_SZ == 0
			printf("IX");
		#else
			printf("ix");
		#endif
		break;
	}
	//В римских числах нет десятичных дробей
	fputs(NL_SYM, stdout);
}

//
// Служебные функции
//

double getrd(char c) {
//Получить значение цифры римского числа
	switch(c) {
		case 'i':
		case 'I':
			return(1);
		break;
		case 'v':
		case 'V':
			return(5);
		break;
		case 'x':
		case 'X':
			return(10);
		break;
		case 'l':
		case 'L':
			return(50);
		break;
		case 'c':
		case 'C':
			return(100);
		break;
		case 'm':
		case 'M':
			return(1000);
		break;
		default:
			return(-1);
		break;
	}
}

int isromedigit(char n) {
	n = tolower(n);
	if (n == 'c' || n == 'i' || n == 'l' || n == 'm' || n == 'v' || n == 'x') return(1);
	else return(0);
}

char* btoa(double n, char** a) {
//Двоичные в ASCII
	size_t a_sz = 0;
	FILE* buf_stream = (FILE*) open_memstream(a, &a_sz); // Работа через строковые потоки
	register long int nm = n; // Целая часть
	register double f = n - nm; // Дробная часть
	do {
	// Целая часть
		putc(nm%2 + '0', buf_stream);
	} while ((nm /= 2) > 0);
	putc((char) NULL, buf_stream); // Чтобы правильно сработала функция реверса
	fflush(buf_stream); // Сброс в строку для работы с ней
	reverse(*a); // Реверсирование
	#if OUT_PREC != 0 // Если точность равна 0, то с дробной частью не работаю
	if (f - (int) f > 0) {
	// Дробная часть, если есть
		fseek(buf_stream, strlen(*a), SEEK_SET); // На позицию NULL символа
		putc('.', buf_stream); // Вместо NULL символа
		register int i = 0;
		while ((f - (int)f > 0)
		#if OUT_PREC > 0
			&& i++ < OUT_PREC
		#endif
		)
		{
			f *= 2;
			putc((int)f + '0', buf_stream);
			f = f - (int)f;
		}
		putc((char) NULL, buf_stream);
	}
	#endif
	fclose(buf_stream);
	return(*a);
}

char* otoa(double n, char** a) {
//Восьмеричные в ASCII
	size_t a_sz = 0;
	FILE* buf_stream = (FILE*) open_memstream(a, &a_sz);
	register long int nm = n;
	register double f = n - nm;
	do {
	// Целая часть
		putc(nm%8 + '0', buf_stream);
	} while ((nm /= 8) > 0);
	putc((char) NULL, buf_stream);
	fflush(buf_stream);
	reverse(*a);
	#if OUT_PREC != 0
	if (f - (int) f > 0) {
	// Дробная часть, если есть
		fseek(buf_stream, strlen(*a), SEEK_SET);
		putc('.', buf_stream);
		register int i = 0;
		while ((f - (int)f > 0)
		#if OUT_PREC > 0
			&& i++ < OUT_PREC
		#endif
		)
		{
			f *= 8;
			putc((int)f + '0', buf_stream);
			f = f - (int)f;
		}
		fputc((char) NULL, buf_stream);
	}
	#endif
	fclose(buf_stream);
	return(*a);
}

char* htoa(double n, char** a) {
//Шеснадцатеричные в ASCII
	size_t a_sz = 0;
	FILE* buf_stream = (FILE*) open_memstream(a, &a_sz);
	register long int nm = n;
	register double f = n - nm;
	do {
	// Целая часть
		register int tmp;
		tmp = nm%16;
		if (tmp <= 9) putc(tmp + '0', buf_stream);
		#if SYM_SZ == 0
			else putc(tmp - 10 + 'A', buf_stream);
		#else
			else putc(tmp - 10 + 'a', buf_stream);
		#endif
	} while ((nm /= 16) > 0);
	putc((char) NULL, buf_stream);
	fflush(buf_stream);
	reverse(*a);
	#if OUT_PREC != 0
	if (f - (int)f > 0) {
	// Дробная часть, если есть
		fseek(buf_stream, strlen(*a), SEEK_SET);
		putc('.', buf_stream);
		register int i = 0;
		while ( (f - (int)f > 0)
		#if OUT_PREC > 0
			&& i++ < OUT_PREC
		#endif
		)
		{
			f *= 16;
			if ((int)f <= 9) putc((int)f + '0', buf_stream);
			#if SYM_SZ == 0
				else putc((int)f - 10 + 'A', buf_stream);
			#else
				else putc((int)f - 10 + 'a', buf_stream);
			#endif
			f = f - (int)f;
		}
		putc((char) NULL, buf_stream);
	}
	#endif
	fclose(buf_stream);
	return(*a);
}

/* EOF */

