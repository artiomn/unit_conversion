/*
	inches.c
*/

#include "inches.h"

double cnv_dm_ft(const double n) {
//äÀÊÍÙ × ÆÕÔÙ
	return(n/12);
}

double cnv_dm_yd(const double n) {
	return(n/36);
}

double cnv_dm_ml(const double n) {
	return(n/63360);
}

double cnv_ft_dm(const double n) {
//æÕÔÙ × ÄÀÊÍÙ
	return(n*12);
}

double cnv_ft_yd(const double n) {
	return(n/3);
}

double cnv_ft_ml(const double n) {
	return(n/5280);
}

double cnv_yd_dm(const double n) {
//ñÒÄÙ × ÄÀÊÍÙ
	return(n*36);
}

double cnv_yd_ft(const double n) {
	return(n*3);
}

double cnv_yd_ml(const double n) {
	return(n/1760);
}

double cnv_ml_dm(const double n) {
//íÉÌÉ × ÄÀÊÍÙ
	return(n*63360);
}

double cnv_ml_ft(const double n) {
	return(n*5280);
}

double cnv_ml_yd(const double n) {
	return(n*1760);
}

/* EOF */

