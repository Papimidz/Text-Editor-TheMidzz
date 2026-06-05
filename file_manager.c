#include <stdio.h>
#include <string.h>
#include "file_manager.h"
#include "text_editor.h"

void saveFile(EditorState *state) {
    FILE *fp = fopen(state->filename, "w");
    if (!fp) {
        printf("Gagal save file\n");
        return;
    }

    for (int i = 0; i < state->lineCount; i++) {
        fprintf(fp, "%s\n", state->buffer[i]);
    }

    fclose(fp);
    printf("File disimpan\n");
}

void openFile(char *inputFilename, EditorState *state) {
    FILE *fp = fopen(inputFilename, "r");
    if (!fp) {
        printf("File tidak ditemukan\n");
        return;
    }

    state->lineCount = 0;
    strcpy(state->filename, inputFilename);

    while (fgets(state->buffer[state->lineCount], MAX_COL, fp)) {
        state->buffer[state->lineCount][strcspn(state->buffer[state->lineCount], "\n")] = 0;
        (state->lineCount)++;
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