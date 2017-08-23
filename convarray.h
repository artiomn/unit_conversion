/*
	convarray.h
*/

/*
 Чтобы добавить новые преобразования нужно:
  1. Создать файл _имя_.c, в котором записать функции преобразования (по примеру digits.c).
  2. Создать файл _имя_.h (по примеру digits.h).
  3. Написать в ЭТОМ файле #include "_имя_.h" (там где написано "Модули ф-ций преобразования").
  4. Добавить в ЭТОТ файл #define _определение_ _номер_ (например: #define DEC 0).
  5. Увеличить значение ALL (число элементов преобразования) на число новых элементов.
  6. Инициализировать новые элементы массиа carr.
  7. Добавить имена "опций" в массив code_names.
  8. Обновить Makefile.
*/

#ifndef CONVARRAY
#define CONVARRAY

//
// Модули функций преобразования
//

#include "digits.h"
#include "inches.h"
#include "meters.h"
#include "inch_to_metric.h"
#include "metric_to_inch.h"
#include "temp.h"
#include "text.h"

//
// Номера элементов преобразования
//

#define DEC	0
#define BIN	1
#define HEX	2
#define OCT	3
#define ROME	4
#define CELS	5
#define FARG	6
#define KALV	7
#define MKM	8
#define MM	9
#define CM	10
#define M	11
#define KM	12
#define INCH	13
#define FOOT	14
#define YARD	15
#define MILE	16
#define TXT_E	17
#define TXT_R	18

#define ALL 19		//Всего элементов преобразования

struct cstruc {
	double (*f_inp)();	//Ф-ция ввода
	double (*f_cnv)();	//Ф-ция преобраз-я
	void (*f_out)();	//Ф-ция вывода
};

/* Массив преобразований */
static struct cstruc carr[ALL][ALL] = { \
	[DEC][DEC] = {&atof, NULL, &printdbl }, [DEC][BIN] = {&atof, NULL, &printb }, \
	[DEC][HEX] = {&atof, NULL, &printh}, [DEC][OCT] = {&atof, NULL, &printo} , \
	[DEC][ROME] = {&atof, NULL, &printr}, [DEC][CELS] = NULL, \
	[DEC][FARG] = NULL, [DEC][MKM] = NULL, [DEC][MM] = NULL, [DEC][CM] = NULL, \
	[DEC][M] = NULL, [DEC][KM] = NULL, \
	[BIN][DEC] = {&btof, NULL, &printdbl},[BIN][BIN] = {&btof, NULL, &printb}, \
	[BIN][HEX] = {&btof, NULL, &printh}, [BIN][OCT] = {&btof, NULL, &printo}, \
	[BIN][ROME] = {&btof, NULL, &printr},[BIN][CELS] = NULL, \
	[BIN][FARG] = NULL, [BIN][MKM] = NULL, [BIN][MM] = NULL, [BIN][CM] = NULL, \
	[BIN][M] = NULL, [BIN][KM] = NULL, \
	[HEX][DEC] = {&htof, NULL, &printdbl}, [HEX][BIN] = {&htof, NULL, &printb}, \
	[HEX][HEX] = {&htof, NULL, &printh}, [HEX][OCT] = {&htof, NULL, &printo}, \
	[HEX][ROME] = {&htof, NULL, &printr}, [HEX][CELS] = NULL, \
	[HEX][FARG] = NULL, [HEX][MKM] = NULL, [HEX][MM] = NULL, [HEX][CM] = NULL, \
	[HEX][M] = NULL, [HEX][KM] = NULL, \
	[OCT][DEC] = {&otof, NULL, &printdbl}, [OCT][BIN] = {&otof, NULL, &printb}, \
	[OCT][HEX] = {&otof, NULL, &printh},[OCT][OCT] = {&otof, NULL, &printo}, \
	[OCT][ROME] = {&otof, NULL, &printr},[OCT][CELS] = NULL, \
	[OCT][FARG] = NULL, [OCT][MKM] = NULL, [OCT][MM] = NULL, [OCT][CM] = NULL, \
	[OCT][M] = NULL, [OCT][KM] = NULL, \
	[ROME][DEC] = {&rtof, NULL, &printdbl},[ROME][BIN] = {&rtof, NULL, &printb}, \
	[ROME][HEX] = {&rtof, NULL, &printh}, [ROME][OCT] = {&rtof, NULL, &printo}, \
	[ROME][ROME] = {&rtof, NULL, &printr}, [ROME][CELS] = NULL, \
	[ROME][FARG] = NULL, [ROME][MKM] = NULL, [ROME][MM] = NULL, [ROME][CM] = NULL, \
	[ROME][M] = NULL, [ROME][KM] = NULL, \
	[CELS][DEC] = NULL, [CELS][BIN] = NULL, \
	[CELS][HEX] = NULL, [CELS][OCT] = NULL, [CELS][ROME] = NULL, \
	[CELS][CELS] = {&atof, NULL, &printdbl}, [CELS][FARG] = {&atof, &cnv_celstofar, &printdbl}, \
	[CELS][KALV] = {&atof, &cnv_celstokalv, &printdbl}, \
	[CELS][MKM] = NULL, [CELS][MM] = NULL, [CELS][CM] = NULL, \
	[CELS][M] = NULL, [CELS][KM] = NULL, \
	[FARG][DEC] = NULL, [FARG][BIN] = NULL, \
	[FARG][HEX] = NULL, [FARG][OCT] = NULL, \
	[FARG][ROME] = NULL, [FARG][CELS] = {&atof, &cnv_fartocels, &printdbl}, \
	[FARG][FARG] = {&atof, NULL, &printdbl}, [FARG][KALV] = {&atof, &cnv_fartokalv, &printdbl}, \
	[FARG][MKM] = NULL, [FARG][MM] = NULL, [FARG][CM] = NULL, \
	[FARG][M] = NULL, [FARG][KM] = NULL, \
	[KALV][CELS] = {&atof, &cnv_kalvtocels, &printdbl}, \
	[KALV][FARG] = {&atof, &cnv_kalvtofar, &printdbl}, [KALV][KALV] = {&atof, NULL, &printdbl}, \
	[MKM][MKM] = {&atof, NULL, &printdbl}, [MKM][MM] = {&atof, &cnv_mkm_mm, &printdbl}, \
	[MKM][CM] = {&atof, &cnv_mkm_cm, &printdbl}, [MKM][M] = {&atof, &cnv_mkm_m, &printdbl}, \
	[MKM][KM] = {&atof, &cnv_mkm_km, &printdbl}, [MKM][INCH] = {&atof, &cnv_mkm_dm, &printdbl}, \
	[MKM][YARD] = {&atof, &cnv_mkm_yd, &printdbl}, \
	[MKM][FOOT] = {&atof, &cnv_mkm_ft, &printdbl}, [MKM][MILE] = {&atof, &cnv_mkm_ml, &printdbl}, \
	[MM][MKM] = {&atof, &cnv_mm_mkm, &printdbl}, [MM][MM] = {&atof, NULL, &printdbl}, \
	[MM][CM] = {&atof, &cnv_mm_cm, &printdbl}, [MM][M] = {&atof, &cnv_mm_m, &printdbl}, \
	[MM][KM] = {&atof, &cnv_mm_km, &printdbl}, [MM][INCH] = {&atof, &cnv_mm_dm, &printdbl}, \
	[MM][YARD] = {&atof, &cnv_mm_yd, &printdbl}, [MM][FOOT] = {&atof, &cnv_mm_ft, &printdbl}, \
	[MM][MILE] = {&atof, &cnv_mm_ml, &printdbl}, \
	[CM][MKM] = {&atof, &cnv_cm_mkm, &printdbl}, [CM][MM] = {&atof, &cnv_cm_mm, &printdbl}, \
	[CM][CM] = {&atof, NULL, &printdbl}, [CM][M] = {&atof, &cnv_cm_m, &printdbl}, \
	[CM][KM] = {&atof, &cnv_cm_km, &printdbl}, [CM][INCH] = {&atof, &cnv_cm_dm, &printdbl}, \
	[CM][YARD] = {&atof, &cnv_cm_yd, &printdbl}, [CM][FOOT] = {&atof, &cnv_cm_ft, &printdbl}, \
	[CM][MILE] = {&atof, &cnv_cm_ml, &printdbl}, \
	[M][MKM] = {&atof, &cnv_m_mkm, &printdbl}, [M][MM] = {&atof, cnv_m_mm, &printdbl}, \
	[M][CM] = {&atof, &cnv_m_cm, &printdbl}, [M][M] = {&atof, NULL, &printdbl}, \
	[M][KM] = {&atof, &cnv_m_km, &printdbl}, [M][INCH] = {&atof, &cnv_m_dm, &printdbl}, \
	[M][YARD] = {&atof, &cnv_m_yd, &printdbl}, [M][FOOT] = {&atof, &cnv_m_ft, &printdbl}, \
	[M][MILE] = {&atof, &cnv_m_ml, &printdbl}, \
	[KM][MKM] = {&atof, &cnv_km_mkm, &printdbl}, [KM][MM] = {&atof, &cnv_km_mm, &printdbl}, \
	[KM][CM] = {&atof, &cnv_km_cm, &printdbl}, [KM][M] = {&atof, &cnv_km_m, &printdbl}, \
	[KM][KM] = {&atof, NULL, &printdbl}, [KM][INCH] = {&atof, &cnv_km_dm, &printdbl}, \
	[KM][YARD] = {&atof, &cnv_km_yd, &printdbl}, [KM][FOOT] = {&atof, &cnv_km_ft, &printdbl}, \
	[KM][MILE] = {&atof, &cnv_km_ml, &printdbl}, \
	[INCH][INCH] = {&atof, NULL, &printdbl}, [INCH][YARD] = {&atof, &cnv_dm_yd, &printdbl}, \
	[INCH][FOOT] = {&atof, &cnv_dm_ft, &printdbl}, \
	[INCH][MILE] = {&atof, &cnv_dm_ml, &printdbl}, \
	[INCH][MKM] = {&atof, &cnv_dm_mkm, &printdbl}, \
	[INCH][MM] = {&atof, &cnv_dm_mm, &printdbl}, \
	[INCH][CM] = {&atof, &cnv_dm_cm, &printdbl}, \
	[INCH][M] = {&atof, &cnv_dm_m, &printdbl}, \
	[INCH][KM] = {&atof, &cnv_dm_km, &printdbl}, 
	[YARD][INCH] = {&atof, &cnv_yd_dm, &printdbl}, \
	[YARD][YARD] = {&atof, NULL, &printdbl}, \
	[YARD][FOOT] = {&atof, &cnv_yd_ft, &printdbl}, \
	[YARD][MILE] = {&atof, &cnv_yd_ml, &printdbl}, \
	[YARD][MKM] = {&atof, &cnv_yd_mkm, &printdbl}, \
	[YARD][MM] = {&atof, &cnv_yd_mm, &printdbl}, \
	[YARD][CM] = {&atof, &cnv_yd_cm, &printdbl}, \
	[YARD][M] = {&atof, &cnv_yd_m, &printdbl}, \
	[YARD][KM] = {&atof, &cnv_yd_km, &printdbl}, \
	[FOOT][INCH] = {&atof, &cnv_ft_dm, &printdbl}, \
	[FOOT][YARD] = {&atof, &cnv_ft_yd, &printdbl}, \
	[FOOT][FOOT] = {&atof, NULL, &printdbl}, \
	[FOOT][MILE] = {&atof, &cnv_ft_ml, &printdbl}, \
	[FOOT][MKM] = {&atof, &cnv_ft_mkm, &printdbl}, \
	[FOOT][MM] = {&atof, &cnv_ft_mm, &printdbl}, \
	[FOOT][CM] = {&atof, &cnv_ft_cm, &printdbl}, \
	[FOOT][M] = {&atof, &cnv_ft_m, &printdbl}, \
	[FOOT][KM] = {&atof, &cnv_ft_km, &printdbl}, \
	[MILE][INCH] = {&atof, &cnv_ml_dm, &printdbl}, \
	[MILE][YARD] = {&atof, &cnv_ml_yd, &printdbl}, \
	[MILE][FOOT] = {&atof, &cnv_ml_ft, &printdbl}, \
	[MILE][MILE] = {&atof, NULL, &printdbl}, \
	[MILE][MKM] = {&atof, &cnv_ml_mkm, &printdbl}, \
	[MILE][MM] = {&atof, &cnv_ml_mm, &printdbl}, \
	[MILE][CM] = {&atof, &cnv_ml_cm, &printdbl}, \
	[MILE][M] = {&atof, &cnv_ml_m, &printdbl}, \
	[MILE][KM] = {&atof, &cnv_ml_km, &printdbl}, \
	[TXT_E][TXT_E] = {&get_text, NULL, &out_text}, \
	[TXT_E][TXT_R] = {&get_text, &tlit_er, &out_text}, \
	[TXT_R][TXT_E] = {&get_text, &tlit_re, &out_text}, \
	[TXT_R][TXT_R] = {&get_text, NULL, &out_text} \
};

/* Массив "опций" */
static char* code_names[] = {[DEC] "dec", [BIN] "bin", [HEX] "hex", [OCT] "oct", \
[ROME] "rome", [CELS] "cels", [FARG] "farg", [KALV] "kalv", [MKM] "mkm", [MM] "mm", [CM] "cm", \
[M] "m", [KM] "km", [INCH] "inch", [YARD] "yard", [FOOT] "foot", [MILE] "mile", \
[TXT_E] "trer", [TXT_R] "trre", (char*) NULL };

#endif

/* EOF */

