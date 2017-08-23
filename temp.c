/*
	temp.c
*/

#include "temp.h"

double cnv_celstofar(const double cl) {
	return(((double)cl*9) / 5 + 32);
}

double cnv_celstokalv(const double cl) {
	return((double)(cl) + 273);
}

double cnv_fartocels(const double fr) {
	return((((double)fr - 32)*5) / 9);
}

double cnv_kalvtocels(const double kv) {
	return((double)(kv) - 273);
}

double cnv_kalvtofar(const double kv) {
	return((((double)kv - 273)*9) / 5 + 32); //Сначала в Цельсий, потом в Фаренгейт
}

double cnv_fartokalv (const double fr) {
	return(((((double)fr - 32)*5) / 9) + 273 ); //Сначала в Цельсий, потом в Кельвин
}

/* EOF */

