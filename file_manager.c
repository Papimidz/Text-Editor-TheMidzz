#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "text_editor.h"
#include "file_manager.h"
#include "text_engine.h"

void CreateEmpty(EditorState *state){
    initEditor(state); 
}

void NewFile(List *L){
    address P, delete;

    P = L->Head;
void NewFile(EditorState *state){
    LineNode *P = state->head;
    LineNode *hapus;

    while (P != NULL){
        hapus = P;
        P = P->next;
        free(delete);
        clearText(&(hapus->lineContent));
        free(hapus);
    }

    CreateEmpty(state);
    printf(">> File baru berhasil dibuat.\n");
}

void saveFile(EditorState *state) {
    printf("\nFitur Save Belum Selesai.\n");
}

void openFile(char *filename, EditorState *state) {
    printf("\nFitur Open sedang dalam pengembangan.\n");
}

void deleteFile(char *filename) {
    printf("\nFitur Delete sedang dalam pengembangan.\n");
}