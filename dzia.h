#ifndef dzia_H
#define dzia_H
#include "hasbi.h"

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    char filename[256];
} Text;

typedef struct Editorstate;

void initText(Text* t);
void insertChar(Text* t, char c);
void displayText(Text* t);
void clearText(Text* t);
int getLength(Text* t);
int isEmpty(Text* t);
Node* getNodeAt(Text* t, int index);
void replaceWord(EditorState *state, char *kataLama, char *kataBaru);
void findWord(EditorState *state, char *word);

#endif