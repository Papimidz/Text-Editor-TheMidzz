#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#define MAX_LINES 100
#define MAX_COL 100
typedef struct {
    char buffer[MAX_LINES][MAX_COL]; 
    int lineCount;
    char filename[100];
} EditorState;

void editor(EditorState *state);

#endif