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

typedef struct LineNode {
    Text lineContent;
    struct LineNode *prev;
    struct LineNode *next;
} LineNode;

typedef struct {
    LineNode *head;
    LineNode *tail;
    int lineCount;
    char filename[100];
} EditorState;

#endif