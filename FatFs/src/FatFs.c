/*
 ============================================================================
 Name        : FatFs.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ff.h"

char *diskio_filename;
FILE *diskio_file;

FRESULT scan_files(char *path /* Start node to be scanned (***also used as work area***) */
) {
	FRESULT res;
	DIR dir;
	UINT i;
	static FILINFO fno;

	res = f_opendir(&dir, path); /* Open the directory */
	if (res == FR_OK) {
		for (;;) {
			res = f_readdir(&dir, &fno); /* Read a directory item */
			if (res != FR_OK || fno.fname[0] == 0)
				break; /* Break on error or end of dir */
			if (fno.fattrib & AM_DIR) { /* It is a directory */
				i = strlen(path);
				sprintf(&path[i], "/%s", fno.fname);
				res = scan_files(path); /* Enter the directory */
				if (res != FR_OK)
					break;
				path[i] = 0;
			} else { /* It is a file. */
				printf("%s/%s\n", path, fno.fname);
			}
		}
		f_closedir(&dir);
	}

	return res;
}

void dump(unsigned char *p, int size) {
	int i, j;
	int cnt;

	for (i = 0, cnt = 0; i < 16 && cnt < size ; i++) {
		for (j = 0; j < 16 && cnt < size; j++) {
			printf("%02X ", *p);
			p++;
			cnt++;
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	FATFS fs;
	FRESULT res;
	char buff[256];
	FILE *fsrc;
	FIL fdest;
	size_t bytes, wbytes, total;
	char *in_filename;
	char *fatfs_filename;
	char *option;

	option = argv[1];
	diskio_filename = argv[2];
	in_filename = argv[3];

	if ((argc < 3) ||
		(argc == 3 && strcmp(option, "-d")) ||
		(argc >= 4 && strcmp(option, "-c") && strcmp(option, "-e"))
		) {
		printf("FatFs usage: FatFs.exe -c|-d|-e <file.img> <file>");
		return 1;
	}

	printf("FatFs option:%s image:%s file:%s\n", option, diskio_filename, in_filename);

	res = f_mount(&fs, "", 1);
	if (res) {
		printf("can't mount file-system: %s\n", diskio_filename);
		return 1;
	}

	if (!strcmp(option, "-c")) {

		fsrc = fopen(in_filename, "rb");
		if (!fsrc) {
			printf("can't read file: %s\n", in_filename);
			return 1;
		}

		fatfs_filename = in_filename + strlen(in_filename);

		while(fatfs_filename >= in_filename) {
			if (*fatfs_filename == '\\') {
				fatfs_filename++;
				break;
			}
			fatfs_filename--;
		}

		if (fatfs_filename < in_filename) {
			fatfs_filename = in_filename;
		}

		//printf("fatfs_filename:%s\n", fatfs_filename);

		res = f_open(&fdest, fatfs_filename, FA_CREATE_ALWAYS | FA_WRITE);
		//printf("f_open res:%d\n", res);

		if (res) {
			fclose(fsrc);
			printf("can't write file: %s\n", in_filename);
			return 1;
		}

		for (total = 0;;) {
			bytes = fread(buff, 1, sizeof(buff), fsrc);
			//printf("fread bytes:%d \n", bytes);
			//dump(buff, bytes);
			f_write((void *)&fdest, buff, bytes, &wbytes);
			total += bytes;
			if (bytes != sizeof(buff))
				break;
		}

		printf("copy file:%s bytes:%d\n", fatfs_filename, total);

		f_close(&fdest);
		fclose(fsrc);
	}

	if (!strcmp(option, "-e")) {

		fsrc = fopen(in_filename, "wb");
		if (!fsrc) {
			printf("can't write file: %s\n", in_filename);
			return 1;
		}

		fatfs_filename = in_filename + strlen(in_filename);

		while(fatfs_filename >= in_filename) {
			if (*fatfs_filename == '\\') {
				fatfs_filename++;
				break;
			}
			fatfs_filename--;
		}

		if (fatfs_filename < in_filename) {
			fatfs_filename = in_filename;
		}

		//printf("fatfs_filename:%s\n", fatfs_filename);

		res = f_open(&fdest, fatfs_filename, FA_READ);
		//printf("f_open res:%d\n", res);

		if (res) {
			fclose(fsrc);
			printf("can't read file: %s\n", in_filename);
			return 1;
		}

		for (total = 0;;) {
			f_read((void *)&fdest, buff, sizeof(buff), &wbytes);
			//printf("f_read bytes:%d \n", wbytes);
			//dump(buff, bytes);
			fwrite(buff, 1, wbytes, fsrc);
			total += wbytes;
			if (wbytes != sizeof(buff))
				break;
		}

		printf("copy file:%s bytes:%d\n", fatfs_filename, total);

		f_close(&fdest);
		fclose(fsrc);
	}

	if (!strcmp(option, "-d")) {

		if (res == FR_OK) {
			strcpy(buff, "/");
			res = scan_files(buff);
		}

	}

	fclose(diskio_file);

	return EXIT_SUCCESS;
}
