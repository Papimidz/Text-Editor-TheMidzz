#ifndef dzia_H
#define dzia_H

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

typedef struct Editorstate EditorState;

void initText(Text* t);
void insertChar(Text* t, char c);
void displayText(Text* t);
void clearText(Text* t);
int isEmpty(Text* t);
void findAndReplace(EditorState *state);



#endif