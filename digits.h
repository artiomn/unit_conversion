/*
	digits.h
*/

#ifndef DIGITS
#define DIGITS

double htof(const char*);	// Hex -> Double
double btof(const char*);	// Bin -> Double
double otof(const char*);	// Oct -> Double
double rtof(const char*);	// Rome -> Double

void printdbl(const double);	// �������� ������� � ������� %G
void printb(const double); 	// �������� ��������
void printh(const double);	// �������� ����������������
void printo(const double);	// �������� ������������
void printr(const double);	// �������� �������

#endif

/* EOF */

