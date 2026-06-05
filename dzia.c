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
int getLength(Text* t) {
    int count = 0;
    Node* curr = t->head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    return count;
}
int isEmpty(Text* t) {
    return (t->head == NULL);
}

Node* getNodeAt(Text* t, int index) {
    int count = 0;
    Node* curr = t->head;

    while (curr != NULL) {
        if (count == index) {
            return curr;
        }
        count++;
        curr = curr->next;
    }

    return NULL; 
}

void findWord(EditorState *state, char *word) {
    LineNode *curr = state->head;
    char buffer[1024];
    int row = 1, found = 0;

    printf("\n>> Hasil pencarian untuk '%s':\n", word);
    while (curr != NULL) {
        getTextString(&(curr->lineContent), buffer);
        if (strstr(buffer, word) != NULL) {
            printf("   - Ada di baris %d: %s\n", row, buffer);
            found = 1;
        }
        curr = curr->next;
        row++;
    }
    if (found == 0) printf("   (Tidak ada hasil yang cocok)\n");
}

void replaceWord(EditorState *state, char *kataLama, char *kataBaru) {
    LineNode *curr = state->head;
    char buffer[1024], temp[1024];
    int count = 0;

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
            count++;
        }
        curr = curr->next;
    }
    printf(">> Selesai! %d baris telah diperbarui.\n", count);
}