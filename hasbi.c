#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "hasbi.h"
#include "file_manager.h"
#include "dzia.h"

    void initEditor(EditorState *state) {
        state->head = NULL;
        state->tail = NULL;
        state->lineCount = 0;
        state->filename[0] = '\0';
    }

    void addLine(EditorState *state, char *inputText) {
    LineNode *newNode = (LineNode*) malloc(sizeof(LineNode));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori untuk baris baru.\n");
        return;
    }

    initText(&(newNode->lineContent)); 

    for (size_t i = 0; i < strlen(inputText); i++) {
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


