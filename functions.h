/*
	functions.h
*/

#ifndef FUNCS_H
#define FUNCS_H

//
// Включаемые файлы конфигурации
//

#include "config.h"

//
// Функции "на вынос"
//

#define sg(a) ((a) < 0 ? -1 : 1)	// Знак
#define myabs(a) (a) < 0 ? -(a) : (a)	// abs() для значения любого типа

extern char* pin;				// Имя программы
long int modi(const double, long int*, int*);	// 
long int pow10(long int);			// 10 в степени n
double pow_(double base, int power);	// Степень
char* reverse(char*);				// Переворачивает строку
void err_ft(int) __attribute__ ((noreturn));	// Вывод ошибки и выход с EXIT_FAILURE
void* xmalloc(size_t);				// Распределение памяти с проверкой
void usage();					// Вывод справки

#endif

/* EOF */

