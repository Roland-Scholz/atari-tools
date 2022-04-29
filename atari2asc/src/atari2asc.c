#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

#define PC_NEWLINE 10
#define ATARI_NEWLINE 155
#define ATARI_TAB 127
#define PC_TAB 9

static char s[4];
static char line[255];
static char buf[16384];

int readLine(FILE *f) {
	unsigned char c;
	int i;
	memset(line, 0, sizeof(line));

	for(i = 0;; i++) {
		c = fgetc(f);
		if (c == ATARI_NEWLINE) return true;
		if (c == 0xff) return false;
		line[i] = c;
	}
}

void replace(char *line, const char *before, const char* after, int *once) {
	char *start;
	int i;

	if (*once == 0 && (start = strstr(line, before))) {
		//printf(";%s\n", line);
		for (i = 0; after[i]; i++) {
			start[i] = after[i];
		}
		*once = 1;
		return;
	}
	return;
}

void doLine(int mainfile, int makefile) {

	unsigned char c, d;
	int len, i, once;
	char *start;

	len = strlen(line);

	if (!mainfile) {
		if (strstr(line, "clab.s")) {
			printf(";%s\n", line);
			return;
		}
		if (strstr(line, "zreg.s")) {
			printf(";%s\n", line);
			return;
		}
	}

	if (makefile) goto afterreplace;

	if ((start = strstr(line, ">bzpar,x"))) {
		*(start-1) = 0;
		for (int i = 0; line[i]; i++) {
			if (line[i] == ATARI_TAB) line[i] = PC_TAB;
		}
		printf("\tsep\t#$10\n");
		printf("%s\tbzpar,y\n", line);
		printf("\trep\t#$10\n");
		return;
	}

	if ((start = strstr(line, "bz80,x"))) {
		*(start-1) = 0;
		for (int i = 0; line[i]; i++) {
			if (line[i] == ATARI_TAB) line[i] = PC_TAB;
		}
		printf("%s(bz80),y\n", line);
		return;
	}

	if (strstr(line, "j0+2")) {
		printf(";%s\n", line);
		printf("\tasl\n");
		printf("\ttax\n");
		printf("\tjmp\t(zz_jumptab,x)\n");
		return;
	}
	if (strstr(line, "?j0")) {
		printf(";%s\n", line);
		return;
	}
	if (strstr(line, ".rs")) {
		printf(";%s\n", line);
		return;

	}
	if (strstr(line, ".rsset")) {
		printf(";%s\n", line);
		return;
	}
	if ((start = strstr(line, "?npi"))) {
		if (start == line) {
			printf("zz00?npi\n");
		}
	}

	once = 0;

	replace(line, "inx", "iny", &once);
	replace(line, "dex", "dey", &once);
	replace(line, "iny", "inx", &once);
	replace(line, "dey", "dex", &once);
	replace(line, "ldx", "ldy", &once);
	replace(line, "ldy", "ldx", &once);
	replace(line, "stx", "sty", &once);
	replace(line, "sty", "stx", &once);
	replace(line, "txy", "tyx", &once);
	replace(line, "tyx", "txy", &once);
	replace(line, "ctxa", "ctxa", &once);
	replace(line, "txa", "tya", &once);
	replace(line, "tax", "tay", &once);
	replace(line, "tay", "tax", &once);

afterreplace:

	for (i = 0; i < len; i++) {
		/*
		if (!strncmp(&line[i], "zz00?", 5)) {
			i += 5;
		}*/
		c = line[i];

		switch (c) {
		case ATARI_NEWLINE:
			c = PC_NEWLINE;
			break;
		case ATARI_TAB:
			c = PC_TAB;
			break;
		case '>':
			//printf("%s\n", s);
			if (!memcmp(s, "z80", 3) || !memcmp(s, "lib", 3) || !memcmp(s, "uff", 3)) {
				c = '\\';
			}
			break;
		case '.':
			s[0] = line[i + 1];
			s[1] = line[i + 2];
			i += 2;
			d = c;
			c = 0;
			if (s[0] == 'i' && s[1] == 'n') {
				printf(".include");
				break;
			}
			if (s[0] == 'o' && s[1] == 'r') {
				printf(";.org");
				break;
			}
			if (s[0] == 'a' && s[1] == 'b') {
				printf("longa	off");
				break;
			}
			if (s[0] == 'i' && s[1] == 'b') {
				printf("longi	off");
				break;
			}
			if (s[0] == 'a' && s[1] == 'w') {
				printf("longa	on");
				break;
			}
			if (s[0] == 'i' && s[1] == 'w') {
				printf("longi	on");
				break;
			}
			if (s[0] == 'b' && s[1] == 'y') {
				printf("DB");
				break;
			}
			if (s[0] == 'd' && s[1] == 's') {
				printf("DS");
				break;
			}
			if (s[0] == '8' && s[1] == '1') {
				printf(";.81");
				break;
			}
			if (s[0] == 'c' && s[1] == 'p') {
				printf(";.cp");
				break;
			}
			if (s[0] == 'p' && s[1] == 'r') {
				printf(";.pr");
				break;
			}
			if (s[0] == 'z' && s[1] == 'p') {
				printf(";.zp");
				break;
			}

			c = d;
			i -= 2;
			break;
		case '!':
			c = 0;
			break;
		default:
			break;
		}
		if (c) fputc(c, stdout);
		s[0] = s[1];
		s[1] = s[2];
		s[2] = c;
	}
	printf("\n");
}
int main(int argc, char **argv) {

	FILE *fi;
	char fname[255];
	long len;
	int mainfile, makefile;

	if (argc < 2) {
		strcpy(fname, "C:\\atarigit\\Z80EMU\\zz00.s");
		//fprintf(stderr, "Usage: atari2asc INPUT.LST\n");
		// return -1;
	}
	else {
		strcpy(fname, argv[1]);
	}

	makefile = 0;
	if (!strcmp(fname, "make.s")) {
		makefile = 1;
	}

	mainfile = 0;
	if (!strcmp(fname, "zz00.s")) {
		mainfile = 1;
	}


	memset(s, 0, sizeof(s));

	fi = fopen(fname, "r");

	printf("\tINCLIST	ON\n");

	while (readLine(fi)) {
		doLine(mainfile, makefile);
	}

	fclose(fi);

	if (mainfile) {
		fi = fopen("opcodes.txt", "r");
		len = fread(buf, 1, 16384, fi);
		buf[len] = 0;

		printf("%s", buf);
		fclose(fi);
	}
	return 0;
}
