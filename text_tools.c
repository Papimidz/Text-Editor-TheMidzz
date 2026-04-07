#include <stdio.h>
#include <string.h>
#include "text_tools.h"

void newFile(char *buffer) {
    buffer[0] = '\0';
    printf("[TOOLS] File baru\n");
}

void appendText(char *buffer) {
    char temp[500];
    printf("Tambah teks: ");
    fgets(temp, sizeof(temp), stdin);
    strcat(buffer, temp);
}

void findReplace(char *buffer) {
    char find[50], replace[50];
    char temp[1000];
    int i = 0;

    printf("Find: ");
    scanf("%s", find);
    printf("Replace: ");
    scanf("%s", replace);
    getchar();

    temp[0] = '\0';

    while (buffer[i] != '\0') {
        if (strncmp(&buffer[i], find, strlen(find)) == 0) {
            strcat(temp, replace);
            i += strlen(find);
        } else {
            strncat(temp, &buffer[i], 1);
            i++;
        }
    }

    strcpy(buffer, temp);
    printf("[TOOLS] Replace selesai\n");
}

void closeTab() {
    printf("[TOOLS] Close tab (simulasi)\n");
}