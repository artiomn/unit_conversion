/*
	metric_to_inches.c
*/

#include "metric_to_inch.h"

//From metric

double cnv_mkm_dm(const double n) {
	return(n*0.000039);
}

double cnv_mkm_ft(const double n) {
	return(n*0.00000328);
}

double cnv_mkm_yd(const double n) {
	return(n*0.00000984);
}

double cnv_mkm_ml(const double n) {
	return(n*0.000000000062);
}

double cnv_mm_dm(const double n) {
	return(n*0.039);
}

double cnv_mm_ft(const double n) {
	return(n*0.00328);
}

double cnv_mm_yd(const double n) {
	return(0.00984);
}

double cnv_mm_ml(const double n) {
	return(n*0.00000062);
}

double cnv_cm_dm(const double n) {
	return(n*0.39); //
}

double cnv_cm_ft(const double n) {
	return(n*0.0328);
}

double cnv_cm_yd(const double n) {
	return(n*0.0984);
}

double cnv_cm_ml(const double n) {
	return(n*0.0000062);
}

double cnv_m_dm(const double n) {
	return(n*39);
}

double cnv_m_ft(const double n) {
	return(n*3.28);
}

double cnv_m_yd(const double n) {
	return(n*9.84);
}

double cnv_m_ml(const double n) {
	return(n*0.00062);
}

double cnv_km_dm(const double n) {
	return(n*39000);
}

double cnv_km_ft(const double n) {
	return(n*3280);
}

double cnv_km_yd(const double n) {
	return(n*9840);
}

double cnv_km_ml(const double n) {
	return(n*0.62);
}

/* EOF */

