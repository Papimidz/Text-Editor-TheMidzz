#include <stdio.h>
#include <string.h>
#include "file_manager.h"

void saveFile(const char *filename, char *buffer) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("[FILE] Gagal menyimpan file\n");
        return;
    }

    fprintf(fp, "%s", buffer);
    fclose(fp);

    printf("[FILE] File berhasil disimpan\n");
}

void openFile(const char *filename, char *buffer) {
    FILE *fp = fopen(filename, "r");
    char ch;

    if (fp == NULL) {
        printf("[FILE] File tidak ditemukan\n");
        return;
    }

    buffer[0] = '\0';

    while ((ch = fgetc(fp)) != EOF) {
        strncat(buffer, &ch, 1);
    }

    fclose(fp);

    printf("[FILE] File berhasil dibuka\n");
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0)
        printf("[FILE] File berhasil dihapus\n");
    else
        printf("[FILE] Gagal menghapus file\n");
}