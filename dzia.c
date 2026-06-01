#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "text_editor.h"
#include "text_engine.h"

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