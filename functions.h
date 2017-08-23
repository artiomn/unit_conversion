/*
	functions.h
*/

#ifndef FUNCS_H
#define FUNCS_H

//
// ���������� ����� ������������
//

#include "config.h"

//
// ������� "�� �����"
//

#define sg(a) ((a) < 0 ? -1 : 1)	// ����
#define myabs(a) (a) < 0 ? -(a) : (a)	// abs() ��� �������� ������ ����

extern char* pin;				// ��� ���������
long int modi(const double, long int*, int*);	// 
long int pow10(long int);			// 10 � ������� n
double pow_(double base, int power);	// �������
char* reverse(char*);				// �������������� ������
void err_ft(int) __attribute__ ((noreturn));	// ����� ������ � ����� � EXIT_FAILURE
void* xmalloc(size_t);				// ������������� ������ � ���������
void usage();					// ����� �������

#endif

/* EOF */

