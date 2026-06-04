#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "hasbi.h"
#include "chyntia.h"
#include "dzia.h"

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
    printf("\n>> File \"%s\" berhasil disimpan.\n", state->filename);
}



void openFile(char *filename, EditorState *state) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n>> File \"%s\" tidak ditemukan. Gagal membuka file.\n", filename);
        return;
    }

    LineNode *P = state->head;
    LineNode *hapus;
    while (P != NULL){
        hapus = P;
        P = P->next;
        clearText(&(hapus->lineContent));
        free(hapus);
    }
    CreateEmpty(state);

    strcpy(state->filename, filename);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        
        addLine(state, buffer);
    }

    fclose(file);
    printf("\n>> File \"%s\" berhasil dimuat ke editor.\n", filename);
}

void deleteFile(char *filename) {
    if (remove(filename) == 0) { 
        printf("\n>> File \"%s\" berhasil dihapus dari sistem.\n", filename);
    } else {
        printf("\n>> Gagal menghapus file. Periksa kembali nama file Anda.\n");
    }
}