/*
	uc.c - Main program
*/

/*
 Program for convertion between dec, oct, bin, hex, celsium, rome digits, meters & etc..
 Created by Bleeding(cl)2006.
 Syntax: uc [-f{from}] [-t{to}] [-q]
 -h - help.
 -q - quiet.
 -v - verbose.
 -V - version.
 To add a conversion see "convarray.h"
*/

//////////////////////////////////////////////////////////////////////////
//									//
//				License					//
//									//
//	This program created in EDUCATION PURPOSES ONLY.		//
//	You may hack, fuck and kick it.					//
//	Of course, if you like perversions in a sex ...			//
//									//
//	P.S. : Please, don't judge me very strictly. I'm beginner.	//
//	Bleeding.							//
//									//
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <libgen.h>
#include "convarray.h"
#include "functions.h"

char* pin; //��� ���������

main(int argc, char **argv, char **env) {
	register int from_c = DEF_FROM, to_c = DEF_TO,
	flmode = 1, //����� �������
	quiet = 0; //0 - ���������, 1 - ����, 2 - ��� ��������
	char buf[READBUF_BUF_SZ]; // ���� ����� ������ � ������ �������

	int convert(const int, const int, const char*); //"������"
	int get_type(const char*);
	int readbuf(char*, size_t);
	void exit_ft();

	atexit(exit_ft);
	pin = (char*) alloca(strlen(basename(*argv) + 1)); // ��� ��������� (extern)
	pin = basename(*argv);

	errno = 0;
	while (--argc > 0) {
	// ���� ��������� ����������
		argv++;
		if (**argv == '-' && !isdigit(*((*argv) + 1))) {
			// ��������
			(*argv)++;
			if (quiet != 1) quiet = 0;
		}
		else {
			// ��������
			flmode = 0; //� ���������� �������� - �������� ����� �������
			if (!quiet) {
				fprintf(stderr, "%s -> %s\n", code_names[from_c], code_names[to_c]);
				quiet = 2;
			}
			if (convert(from_c, to_c, *argv) == -1) err_ft(2);
			continue;
		}
		// �� ����� � '-' ������� - ��� ��������
		while (**argv != (char)NULL)
		switch(**argv) {
			case 'f': // ������
			(*argv)++;
			if ((from_c = get_type(*argv)) == -1) err_ft(3);
			**argv = (char)NULL;
			break;
			case 'h': // ������
			err_ft(0);
			break;
			case 't': // ����
			(*argv)++;
			if ((to_c = get_type(*argv)) == -1) err_ft(3);
			**argv = (char)NULL;
			break;
			case 'q': (*argv)++; quiet = 1;
			break;
			case 'v': (*argv)++; quiet = 0;
			break;
			case 'V': (*argv)++;
				printf("Version: " PROG_VERSION "\n");
				exit(1);
			break;
			default:
				fprintf(stderr, "-%c - ", **argv); // ����������� ��������
				err_ft(4);
		}
	}

	if (flmode) {
	//����� �������
		if (!quiet) fprintf(stderr, "%s -> %s\n", code_names[from_c], code_names[to_c]);
		while (readbuf(buf, READBUF_BUF_SZ) > -1) {
			if (strlen(buf) == 0) continue;
			if (convert(from_c, to_c, buf) == -1) err_ft(2);
		}
	}
}

//
// ��������� �������
//

int get_type(const char* p) {
//����� �������������� �� argv
	register int i = 0;
	while (code_names[i]&&strcmp(code_names[i], p)) {
		i++;
	}
	if (!(code_names[i])) return(-1);
	else return(i);
}

int convert(const int f, const int t, const char* c) {
//������ :-)
	register double num;
	if (carr[f][t].f_inp) {
		num = carr[f][t].f_inp(c); // ����
		if (carr[f][t].f_cnv != NULL) num = carr[f][t].f_cnv(num); // ��������������
		carr[f][t].f_out(num); // �����
	}
	else {
	// ���� �-��� ����� �� ������, �������������� ������������
		fprintf(stderr, "Convertion not defined...\n");
		/*num = dumbin(c);
		dumbout(num);*/
		return(0);
		//return(-1);
	}
	return(0);
}

int readbuf(char* buf, size_t b_sz) {
	// getline - ������� GNU���
	register char c;
	register int i = 0;
	while (((c = getchar()) != '\n') && (c != EOF) && (c != (char)NULL) && (i < b_sz)) {
		buf[i++] = c;
	}
	buf[i] = (char)NULL;
	if (c == EOF) return (-1);
	return(i);
}

// ����� �������... (��� ��� 20 17:32:31 MSD 2006)

void exit_ft() {

}

/* EOF */

