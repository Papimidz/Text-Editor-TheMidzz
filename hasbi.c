#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasbi.h"
#include "chyntia.h"
#include "dzia.h"

char clipboard[1024] = "";

void getTextString(Text *t, char *buffer) {
    Node *curr = t->head;
    int i = 0;
    while (curr != NULL) {
        buffer[i++] = curr->data;
        curr = curr->next;
    }
    buffer[i] = '\0';
}

LineNode* getLine(EditorState *state, int targetRow) {
    LineNode *curr = state->head;
    int count = 1;
    while (curr != NULL && count < targetRow) {
        curr = curr->next;
        count++;
    }
    return curr;
}

void copyLine(EditorState *state, int row) {
    LineNode *target = getLine(state, row); 
    if (target != NULL) {
        getTextString(&(target->lineContent), clipboard);
        printf(">> Baris %d berhasil disalin!\n", row);
    } else {
        printf(">> Baris tidak ditemukan!\n");
    }
}

void cutLine(EditorState *state, int row) {
    LineNode *target = getLine(state, row);
    if (target != NULL) {
        getTextString(&(target->lineContent), clipboard);

        if (target->prev != NULL) target->prev->next = target->next;
        else state->head = target->next; 

        if (target->next != NULL) target->next->prev = target->prev;
        else state->tail = target->prev; 

        clearText(&(target->lineContent));
        free(target);
        state->lineCount--;
        
        printf(">> Baris %d berhasil dipotong!\n", row);
    } else {
        printf(">> Baris tidak ditemukan!\n");
    }
}

void initEditor(EditorState *state) {
    state->head = NULL;
    state->tail = NULL;
    state->lineCount = 0;
    state->filename[0] = '\0';
}

void addLine(EditorState *state, char *inputText) {
    LineNode *newNode = (LineNode*) malloc(sizeof(LineNode)); 
    initText(&(newNode->lineContent)); 
    
    for (size_t i = 0; i < strlen(inputText); i++) {
        insertChar(&(newNode->lineContent), inputText[i]);
    }

    newNode->next = NULL;
    newNode->prev = state->tail;

    if (state->head == NULL) state->head = newNode;
    else state->tail->next = newNode;
    
    state->tail = newNode;
    state->lineCount++;
}

void editor(EditorState *state) {
    char input[256];
    
    while (1) {
        #ifdef _WIN32 
            system("cls"); 
        #else 
            system("clear"); 
        #endif

        printf("\n=== EDITOR THE MIDZZ [%s] ===\n", strlen(state->filename) ? state->filename : "Untitled");
        
        LineNode *currLine = state->head;
        int row = 1;
        while (currLine != NULL) {
            printf("%d | ", row++);
            displayText(&(currLine->lineContent)); 
            currLine = currLine->next;
        }
        
        printf("\nMenu: | /copy <baris> | /cut <baris> | /paste | /find <kata> | /replace <lama> <baru> | /save | /close\n>> ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        input[strcspn(input, "\n")] = 0;

        char cmd[50] = "", arg1[100] = "", arg2[100] = "";
        sscanf(input, "%s %s %s", cmd, arg1, arg2);

        int angkaBaris = 0;

        if (cmd[0] == '/') {
            if (strcmp(cmd, "/save") == 0) {
                if (strlen(state->filename) == 0) {
                    printf("Masukkan nama file baru: ");
                    scanf("%s", state->filename); getchar();
                }
                saveFile(state);
                printf("... Tekan Enter"); getchar();
            } 
            else if (strcmp(cmd, "/close") == 0) break;
            
            else if (strcmp(cmd, "/copy") == 0) {
                sscanf(arg1, "%d", &angkaBaris);
                copyLine(state, angkaBaris); 
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/cut") == 0) {
                sscanf(arg1, "%d", &angkaBaris);
                cutLine(state, angkaBaris);
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/paste") == 0) {
                if (strlen(clipboard) > 0) {
                    addLine(state, clipboard);
                    printf(">> Paste berhasil di akhir dokumen!\n");
                } else {
                    printf(">> Clipboard kosong!\n");
                }
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/find") == 0) {
                findWord(state, arg1);
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/replace") == 0) {
                replaceWord(state, arg1, arg2);
                printf("... Tekan Enter"); getchar();
            }
            else {
                printf(">> Perintah tidak dikenali!\n");
                printf("... Tekan Enter"); getchar();
            }
        } 
        else if (strlen(input) > 0) {
            addLine(state, input);
        }
    }
}