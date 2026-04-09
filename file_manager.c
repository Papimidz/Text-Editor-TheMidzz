#include <stdio.h>
#include <string.h>
#include "file_manager.h"

void saveFile(const char *filename, char *buffer) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("[FILE] Gagal save\n");
        return;
    }
    fprintf(fp, "%s", buffer);
    fclose(fp);
    printf("[FILE] File disimpan\n");
}

void openFile(const char *filename, char *buffer) {
    FILE *fp = fopen(filename, "r");
    char ch;

    if (!fp) {
        printf("[FILE] File tidak ada\n");
        return;
    }

    buffer[0] = '\0';
    while ((ch = fgetc(fp)) != EOF) {
        strncat(buffer, &ch, 1);
    }

    fclose(fp);
    printf("[FILE] File dibuka\n");
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0)
        printf("[FILE] File dihapus\n");
    else
        printf("[FILE] Gagal hapus\n");
}