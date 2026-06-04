#ifndef HASBI_H
#define HASBI_H

#include "dzia.h"
typedef struct LineNode {
    Text lineContent;
    struct LineNode *prev;
    struct LineNode *next;
} LineNode;

typedef struct EditorState {
    LineNode *head;
    LineNode *tail; 
    int lineCount;
    char filename[256];        
} EditorState;

void initEditor(EditorState *state);
void addLine(EditorState *state, char *inputText);
void editor(EditorState *state);

#endif