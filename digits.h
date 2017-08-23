/*
	digits.h
*/

#ifndef DIGITS
#define DIGITS

double htof(const char*);	// Hex -> Double
double btof(const char*);	// Bin -> Double
double otof(const char*);	// Oct -> Double
double rtof(const char*);	// Rome -> Double

void printdbl(const double);	// Печатает дробное в формате %G
void printb(const double); 	// Печатает двоичное
void printh(const double);	// Печатает шеснадцатеричное
void printo(const double);	// Печатает восьмеричное
void printr(const double);	// Печатает римское

#endif

/* EOF */

