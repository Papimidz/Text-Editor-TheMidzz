#ifndef EDITOR_H
#define EDITOR_H

#define MAX_LINES 100
#define MAX_LENGTH 256

typedef struct {
    char text[MAX_LINES][MAX_LENGTH];
    int line_count;
} Editor;

void initEditor(Editor *e);
void display(Editor *e);
void insertLine(Editor *e, char *line);
void deleteLine(Editor *e, int line);

void saveFile(Editor *e, char *filename);
void openFile(Editor *e, char *filename);

#endif