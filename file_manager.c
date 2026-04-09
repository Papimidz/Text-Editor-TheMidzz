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
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0)
        printf("[FILE] File dihapus\n");
    else
        printf("Gagal hapus file\n");
}