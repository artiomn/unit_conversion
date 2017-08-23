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
//		���� ������������		//
//		Configuration file		//
//						//
//////////////////////////////////////////////////

//
// ������������, ���������� �������������;	User configuration
//



#define DEF_FROM	DEC	// ������ �� ���������;	From by default
#define DEF_TO		HEX	// ���� �� ���������;	To by dfeault

#define NL_SYM		"\n"	// ������ �����������
				// Separating symbol

//
// ������������ ������ ��� digits.c;	Output configuration for digits.c
//

#define DBL_OUT_FMT	"%G\n"	// ������ ������ ����� � ��������� ������
				// Output format for the floating point numbers

// ��������� ��������� �� ��������� � ������� printdbl() (������� ���. ����� � ����. ������)
// Following parameters, don't affect to printdbl() function (output dec. numbers with fl. point)

#define SYM_SZ		0	// ������� �������� ��� ������:	0 - ������, 1 - �������
				// Output symbols register:	0 - lowercase, 1 - uppercase
#define OUT_PREC	10	// ����� ������, ��������� ����� ������� (-1 - �������������)
				// Number of numerals after point (-1 - unlimited)

//
// �������������� �����������;	Additional configuration
//

#define PROG_VERSION	"0.1a"	// ������;	Program version
#define READBUF_BUF_SZ BUFSIZ	// ����� ������ ��� �������, �������� ������ � ������ �������
				// Buf. length for the function, which read string in filter mode

#endif

/* EOF */

