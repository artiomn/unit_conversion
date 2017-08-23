/*
	text.h
*/

#ifndef TEXT_H
#define TEXT_H
double get_text(const char*);	// Ввод текста

void out_text(double);		// Вывод текста

double tlit_re(double);		// Преобразование русского в латинский транслит
double tlit_er(double);		// Преобразование транслита в русский
#endif

/* EOF */

