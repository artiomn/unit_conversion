/*
	meters.c
*/

#include "meters.h"
double cnv_mkm_mm(const double n) {
//Микрометры в милиметры
	return(n/1000);
}

double cnv_mkm_cm(const double n) {
	return(n/10000);
}

double cnv_mkm_m(const double n) {
	return(n/1000000);
}

double cnv_mkm_km(const double n) {
	return(n/1000000000);
}

double cnv_mm_mkm(const double n) {
	return(n*1000);
}

double cnv_mm_cm(const double n) {
	return(n/10);
}

double cnv_mm_m(const double n) {
	return(n/1000);
}

double cnv_mm_km(const double n) {
	return(n/1000000);
}

double cnv_cm_mkm(const double n) {
	return(n*10000);
}

double cnv_cm_mm(const double n) {
	return(n*10);
}

double cnv_cm_m(const double n) {
	return(n/100);
}

double cnv_cm_km(const double n) {
	return(n/10000);
}

double cnv_m_mkm(const double n) {
	return(n*1000000);
}

double cnv_m_mm(const double n) {
	return(n*1000);
}

double cnv_m_cm(const double n) {
	return(n*100);
}

double cnv_m_km(const double n) {
	return(n/1000);
}

double cnv_km_mkm(const double n) {
	return(n*1000000000);
}

double cnv_km_mm(const double n) {
	return(n*1000000);
}

double cnv_km_cm(const double n) {
	return(n*100000);
}

double cnv_km_m(const double n) {
	return(n*1000);
}

/* EOF */

