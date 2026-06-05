#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasbi.h"
#include "chyntia.h"
#include "dzia.h"

void CreateEmpty(EditorState *state){
    initEditor(state); 
}

void NewFile(EditorState *state){
    LineNode *P = state->head;
    LineNode *hapus;

    while (P != NULL){
        hapus = P;
        P = P->next;
        free(hapus);
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

    LineNode *currLine = state->head;
    while (currLine != NULL){

        Node *currChar = currLine->lineContent.head;
        while (currChar != NULL){
            fputc(currChar->data, file);
            currChar = currChar->next;
        }

        if(currLine->next != NULL){
            fputc('\n', file);
        }
        currLine = currLine->next;
    }

    fclose(file);
    printf("\n>> File \"%s\" berhasil disimpan.\n", state->filename);
}