#include <stdio.h>
#include <string.h>
#include "editor.h"

void initEditor(Editor *e) {
    e->line_count = 0;
}

void display(Editor *e) {
    for(int i=0;i<e->line_count;i++){
        printf("%d: %s",i+1,e->text[i]);
    }
}

void insertLine(Editor *e, char *line) {
    if(e->line_count < MAX_LINES){
        strcpy(e->text[e->line_count],line);
        e->line_count++;
    }
}

void deleteLine(Editor *e, int line) {
    if(line < 0 || line >= e->line_count) return;

    for(int i=line;i<e->line_count-1;i++){
        strcpy(e->text[i],e->text[i+1]);
    }

    e->line_count--;
}