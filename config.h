/*
	config.h
*/

#ifndef CONFIG
#define CONFIG
#ifndef FUNCS_H
#error " Please, don't use "config.h" directly, include "functions.h", instead "config.h"! "
#endif

//////////////////////////////////////////////////
//						//
//		Файл конфигурации		//
//		Configuration file		//
//						//
//////////////////////////////////////////////////

//
// Конфигурация, задаваемая пользователем;	User configuration
//



#define DEF_FROM	DEC	// Откуда по умолчанию;	From by default
#define DEF_TO		HEX	// Куда по умолчанию;	To by dfeault

#define NL_SYM		"\n"	// Символ разделителя
				// Separating symbol

//
// Конфигурация вывода для digits.c;	Output configuration for digits.c
//

#define DBL_OUT_FMT	"%G\n"	// Формат вывода чисел с плавающей точкой
				// Output format for the floating point numbers

// Следующие параметры не относятся к функции printdbl() (выводит дес. числа с плав. точкой)
// Following parameters, don't affect to printdbl() function (output dec. numbers with fl. point)

#define SYM_SZ		0	// Регистр символов для вывода:	0 - нижний, 1 - верхний
				// Output symbols register:	0 - lowercase, 1 - uppercase
#define OUT_PREC	10	// Число знаков, выводимых после запятой (-1 - неограниченно)
				// Number of numerals after point (-1 - unlimited)

//
// Дополнительная кофигурация;	Additional configuration
//

#define PROG_VERSION	"0.1a"	// Версия;	Program version
#define READBUF_BUF_SZ BUFSIZ	// Длина буфера для функции, читающей строку в режиме фильтра
				// Buf. length for the function, which read string in filter mode

#endif

/* EOF */

