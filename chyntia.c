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

void NewFile(EditorState *state){
    LineNode *P = state->head;
    LineNode *hapus;

    while (P != NULL){
        hapus = P;
        P = P->next;
        clearText(&(hapus->lineContent));
        free(hapus);
    }

    CreateEmpty(state);
    printf(">> File baru berhasil dibuat.\n");
}

void saveFile(EditorState *state) {
    FILE *file = fopen(state->filename, "w");
    if (file == NULL){
        printf("\nGagal menyimpan file %s!\n", state->filename);
        return;
    }
    

    LineNode *currLine - state->head;
    while (currLine != NULL){

        Node *currChar = currLine->lineContent.head;
        while (currchar != NULL){
            fputc(currChar->data, file);
            currChar = currChar->next;
        }

        if(currLine->next != NULL){
            fputc('\n', file;)
        }
        currLine = currLine->next;
    }

    fclose(file);
    printf("\n>> File \ "%s\" berhasil disimpan.\n", state->filename);
}



void openFile(char *filename, EditorState *state) {
    printf("\nFitur Open sedang dalam pengembangan.\n");
}

void deleteFile(char *filename) {
    printf("\nFitur Delete sedang dalam pengembangan.\n");
}