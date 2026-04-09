#include <stdio.h>
#include <string.h>
#include "file_manager.h"


void saveFile(const char *filename, char buffer[][100], int lineCount) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Gagal save file\n");
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(fp, "%s\n", buffer[i]);
    }

    fclose(fp);
    printf("File disimpan\n");
}

void openFile(const char *filename, char buffer[][100], int *lineCount) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File tidak ditemukan\n");
        return;
    }

    *lineCount = 0;

    while (fgets(buffer[*lineCount], 100, fp)) {
        buffer[*lineCount][strcspn(buffer[*lineCount], "\n")] = 0;
        (*lineCount)++;
    }

    fclose(fp);
    printf("File dibuka\n");
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
        printf("File dihapus permanen\n");
    else
        printf("Gagal hapus file\n");
        printf("[FILE] File dihapus\n");
    else
        printf("[FILE] Gagal hapus\n");
}