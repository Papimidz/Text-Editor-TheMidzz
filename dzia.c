#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasbi.h"
#include "dzia.h"

void initText(Text* t) {
    t->head = NULL;
    t->tail = NULL;
}
void insertChar(Text* t, char c) {
    Node* newNode = (Node*) malloc(sizeof(Node));

  
    if (newNode == NULL) {
        printf("Error: gagal mengalokasikan memori.\n");
        return;
    }

    newNode->data = c;
    newNode->prev = t->tail;   
    newNode->next = NULL;      

  
    if (t->head == NULL) {
        t->head = newNode;
        t->tail = newNode;
    }
   
    else {
        t->tail->next = newNode; 
        t->tail = newNode;       
    }
}
void displayText(Text* t) {
    Node* curr = t->head;

    while (curr != NULL) {
        printf("%c", curr->data);
        curr = curr->next;
    }

    printf("\n");
}
void clearText(Text* t) {
    Node* curr = t->head;

    while (curr != NULL) {
        Node* temp = curr;    
        curr = curr->next;     
        free(temp);            
    }
    t->head = NULL;
    t->tail = NULL;
    t->filename[0] = '\0';
}

int isEmpty(Text* t) {
    return (t->head == NULL);
}

void findAndReplace(EditorState *state) {
    char kataLama[256], kataBaru[256], buffer[1024], temp[1024];
    LineNode *curr = state->head;
    int row = 1, count = 0;

    printf("\nfind: ");
    scanf(" %255[^\n]", kataLama);
    while(getchar() != '\n');

    printf("\n>> Hasil pencarian untuk '%s':\n", kataLama);
    while (curr != NULL) {
        getTextString(&(curr->lineContent), buffer);
        if (strstr(buffer, kataLama) != NULL) {
            printf("   - Ada di baris %d: %s\n", row, buffer);
            count++;
        }
        curr = curr->next;
        row++;
    }

    if (count == 0) {
        printf("   (Kata/Kalimat tidak ditemukan, replace dibatalkan)\n");
        return;
    }

    printf("\nreplace: ");
    scanf(" %255[^\n]", kataBaru);
    while(getchar() != '\n'); 

    curr = state->head; 
    int replacedCount = 0;
    
    while (curr != NULL) {
        getTextString(&(curr->lineContent), buffer);
        char *pos = strstr(buffer, kataLama);
        
        if (pos != NULL) {
            int index = pos - buffer;
            
            strncpy(temp, buffer, index);
            temp[index] = '\0';
            strcat(temp, kataBaru);
            strcat(temp, pos + strlen(kataLama));
            
            clearText(&(curr->lineContent));
            for(size_t i = 0; i < strlen(temp); i++) {
                insertChar(&(curr->lineContent), temp[i]);
            }
            replacedCount++;
        }
        curr = curr->next;
    }
    printf(">> Selesai! %d baris telah diperbarui.\n", replacedCount);
}