#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "text_editor.h"
#include "chyntia.h"
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

    // Bersihkan dulu memori editor dari teks lama sebelum membuka file baru
    LineNode *P = state->head;
    LineNode *hapus;
    while (P != NULL){
        hapus = P;
        P = P->next;
        clearText(&(hapus->lineContent));
        free(hapus);
    }
    CreateEmpty(state);

    // Salin nama file ke state
    strcpy(state->filename, filename);

    char buffer[1024];
    // Membaca file baris demi baris menggunakan fgets
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Hilangkan karakter newline '\n' di akhir string jika terbaca oleh fgets
        buffer[strcspn(buffer, "\n")] = 0;
        
        // Masukkan string baris ini ke dalam linked list lewat fungsi milik Orang 1 & 2
        addLine(state, buffer);
    }

    fclose(file);
    printf("\n>> File \"%s\" berhasil dimuat ke editor.\n", filename);
}

void deleteFile(char *filename) {
    printf("\nFitur Delete sedang dalam pengembangan.\n");
}