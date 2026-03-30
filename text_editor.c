#include <stdio.h>
#include <string.h>
#include "text_editor.h"

void copyText(char *buffer, char *clipboard) {
    strcpy(clipboard, buffer);
    printf("[TEXT EDITOR] Copy berhasil\n");
}

void pasteText(char *buffer, char *clipboard) {
    strcat(buffer, clipboard);
    printf("[TEXT EDITOR] Paste berhasil\n");
}

void cutText(char *buffer, char *clipboard) {
    strcpy(clipboard, buffer);
    buffer[0] = '\0';
    printf("[TEXT EDITOR] Cut berhasil min\n");
}