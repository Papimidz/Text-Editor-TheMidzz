#include <stdio.h>
#include <string.h>

void copyText(char *buffer, char *clipboard) {
    strcpy(clipboard, buffer);
    printf("Copy berhasil\n");
}

void pasteText(char *buffer, char *clipboard) {
    strcat(buffer, clipboard);
    printf("Paste berhasil\n");
}

void cutText(char *buffer, char *clipboard) {
    strcpy(clipboard, buffer);
    buffer[0] = '\0';
    printf("[TEXT EDITOR] Cut berhasil.\n");
}
