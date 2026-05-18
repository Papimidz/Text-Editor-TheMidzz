#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "text_editor.h"
#include "file_manager.h"
#include "text_engine.h"

void initEditor(EditorState *state) {
    state->head = NULL;
    state->tail = NULL;
    state->lineCount = 0;
    state->filename[0] = '\0';
}

void addLine(EditorState *state, char *inputText) {
    LineNode *newNode = (LineNode*) malloc(sizeof(LineNode));
    
    initText(&(newNode->lineContent)); 
    
    for (int i = 0; i < strlen(inputText); i++) {
        insertChar(&(newNode->lineContent), inputText[i]);
    }

    newNode->next = NULL;
    newNode->prev = state->tail;

    if (state->head == NULL) {
        state->head = newNode;
    } else {
        state->tail->next = newNode;
    }
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
        
        printf("\n(Ketik teks untuk baris baru atau /save, /close)\n>> ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        input[strcspn(input, "\n")] = 0;

        if (input[0] == '/') {
            if (strcmp(input, "/save") == 0) {
                if (strlen(state->filename) == 0) {
                    printf("Masukkan nama file baru: ");
                    scanf("%s", state->filename); getchar();
                }
                saveFile(state);
                printf("..."); getchar(); //File tersimpan! Tekan Enter
            } 
            else if (strcmp(input, "/close") == 0) {
                break;
            }
        } 
        else {
            addLine(state, input);
        }
    }
}