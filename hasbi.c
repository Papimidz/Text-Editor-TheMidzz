#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasbi.h"
#include "chyntia.h"
#include "dzia.h"

char clipboard[1024] = "";

void getTextString(Text *t, char *buffer) {
    int i = 0;
    for (Node *curr = t->head; curr != NULL; curr = curr->next) 
        buffer[i++] = curr->data;
    buffer[i] = '\0';
}

LineNode* getLine(EditorState *state, int targetRow) {
    LineNode *curr = state->head;
    for (int count = 1; curr != NULL && count < targetRow; count++) 
        curr = curr->next;
    return curr;
}

void processClipboard(EditorState *state, int row, int isCut) {
    LineNode *target = getLine(state, row);
    if (!target) return (void)printf(">> [Error] Baris %d tidak ditemukan!\n", row);

    getTextString(&(target->lineContent), clipboard);
    printf(">> Baris %d berhasil di-%s ke clipboard!\n", row, isCut ? "cut" : "copy");

    if (isCut) {
        if (target->prev) target->prev->next = target->next; else state->head = target->next;
        if (target->next) target->next->prev = target->prev; else state->tail = target->prev;
        clearText(&(target->lineContent));
        free(target);
        state->lineCount--;
    }
}

void findWord(EditorState *state, char *word) {
    char buf[1024];
    int row = 1, found = 0;
    
    printf("\n>> Hasil pencarian untuk '%s':\n", word);
    for (LineNode *curr = state->head; curr != NULL; curr = curr->next, row++) {
        getTextString(&(curr->lineContent), buf);
        if (strstr(buf, word)) {
            printf("   - Baris %d: %s\n", row, buf);
            found = 1;
        }
    }
    if (!found) printf("   (Tidak ada hasil yang cocok)\n");
}

void replaceWord(EditorState *state, int targetRow, char *oldWord, char *newWord) {
    LineNode *t = getLine(state, targetRow);
    if (!t) return (void)printf(">> [Error] Baris %d tidak ditemukan!\n", targetRow);

    char buf[1024], temp[1024];
    getTextString(&(t->lineContent), buf);
    char *pos = strstr(buf, oldWord);
    
    if (pos) {
        sprintf(temp, "%.*s%s%s", (int)(pos - buf), buf, newWord, pos + strlen(oldWord));
        
        clearText(&(t->lineContent));
        for(size_t i = 0; temp[i] != '\0'; i++) insertChar(&(t->lineContent), temp[i]);
        printf(">> Selesai! Kata pada baris %d berhasil diperbarui.\n", targetRow);
    } else {
        printf(">> [Gagal] Kata '%s' tidak ditemukan di baris %d.\n", oldWord, targetRow);
    }
}

void initEditor(EditorState *state) {
    state->head = state->tail = NULL;
    state->lineCount = 0;
    state->filename[0] = '\0';
}

void addLine(EditorState *state, char *inputText) {
    LineNode *newNode = (LineNode*) malloc(sizeof(LineNode)); 
    initText(&(newNode->lineContent)); 
    
    for (size_t i = 0; inputText[i] != '\0'; i++) 
        insertChar(&(newNode->lineContent), inputText[i]);

    newNode->next = NULL;
    newNode->prev = state->tail;

    if (!state->head) state->head = newNode;
    else state->tail->next = newNode;
    
    state->tail = newNode;
    state->lineCount++;
}

void editor(EditorState *state) {
    char input[1024];
    
    while (1) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        printf("\n=== EDITOR THE MIDZZ [%s] ===\n", state->filename[0] ? state->filename : "Untitled");
        
        int row = 1;
        for (LineNode *curr = state->head; curr != NULL; curr = curr->next) {
            printf("%d | ", row++);
            displayText(&(curr->lineContent)); 
        }
        
        printf("\nMenu:\n[ Teks biasa -> Tambah baris ]\n[ Perintah -> /copy <baris>, /cut <baris>, /paste, /find <kata>, /replace, /save, /close ]\n>> ");
        
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;
        if (strlen(input) == 0) continue;

        if (input[0] == '/') {
            int argVal = 0;

            if (strcmp(input, "/close") == 0) break;
            
            else if (strcmp(input, "/save") == 0) {
                if (!state->filename[0]) {
                    printf("Nama file baru: ");
                    fgets(state->filename, sizeof(state->filename), stdin);
                    state->filename[strcspn(state->filename, "\n")] = 0;
                }
                saveFile(state);
            }
            else if (sscanf(input, "/copy %d", &argVal) == 1) processClipboard(state, argVal, 0);
            
            else if (sscanf(input, "/cut %d", &argVal) == 1) processClipboard(state, argVal, 1);
            
            else if (strcmp(input, "/paste") == 0) {
                if (clipboard[0]) { addLine(state, clipboard); printf(">> Paste berhasil!\n"); } 
                else printf(">> Clipboard kosong!\n");
            }
            else if (strncmp(input, "/find ", 6) == 0) findWord(state, input + 6);
            
            else if (strcmp(input, "/replace") == 0) {
                char oldP[1024], newP[1024], buf[50];
                printf("Baris yg diedit: "); argVal = atoi(fgets(buf, 50, stdin));
                printf("Kata lama: "); fgets(oldP, 1024, stdin); oldP[strcspn(oldP, "\n")] = 0;
                printf("Kata baru: "); fgets(newP, 1024, stdin); newP[strcspn(newP, "\n")] = 0;
                replaceWord(state, argVal, oldP, newP);
            }
            else printf(">> Perintah tidak dikenali!\n");

            printf("... Tekan Enter"); getchar();
        } 
        else {
            addLine(state, input);
        }
    }
}