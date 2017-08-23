/*
	inches.c
*/

#include "inch_to_metric.h"

//To metric

double cnv_dm_mkm(const double n) {
	return(n*25400);
}

double cnv_dm_mm(const double n) {
	return(n*25.4);
}

double cnv_dm_cm(const double n) {
	return(n*2.54);
}

double cnv_dm_m(const double n) {
	return(n*0.0254);
}

double cnv_dm_km(const double n) {
	return(n*0.0000254);
}

double cnv_ft_mkm(const double n) {
	return(n*310000);
}

double cnv_ft_mm(const double n) {
	return(n*310);
}

double cnv_ft_cm(const double n) {
	return(n*31);
}

double cnv_ft_m(const double n) {
	return(n*0.31);
}

double cnv_ft_km(const double n) {
	return(n*0.00031);
}

double cnv_yd_mkm(const double n) {
	return(n*103333.3);
}

double cnv_yd_mm(const double n) {
	return(n*103.3333);
}

double cnv_yd_cm(const double n) {
	return(n*10.33333);
}

double cnv_yd_m(const double n) {
	return(n*0.1033333);
}

double cnv_yd_km(const double n) {
	return(n*0.0001033333);
}

double cnv_ml_mkm(const double n) {
	return(n*1610000000);
}


double cnv_ml_mm(const double n) {
	return(n*1610000);
}


double cnv_ml_cm(const double n) {
	return(n*161000);
}

double cnv_ml_m(const double n) {
	return(n*1610);
}


double cnv_ml_km(const double n) {
	return(n*1.61);
}

/* EOF */

