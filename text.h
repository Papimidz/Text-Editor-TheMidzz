#ifndef TEXT_H
#define TEXT_H

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Text;

#endif