#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "text_editor.h"
#include "file_manager.h"

#define MAX_LINES 100
#define MAX_COL 100

void editor(char buffer[][100], int *lineCount, char *filename) {
    char line[100];
    char clipboard[100];

    while (1) {
        printf("\n=== EDITOR (%s) ===\n", strlen(filename) ? filename : "Untitled");
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

	int i; 
	for (i = 0; i < *lineCount; i++) {
    printf("%s\n", buffer[i]);
	}
        
        printf("\nKetik teks atau command:\n");
        printf("/save /copy /paste /cut /find /replace /close\n>> ");

        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0;

        if (line[0] == '/') {

            if (strncmp(line, "/save", 5) == 0) {
    			if (strlen(filename) == 0) {
        		printf("Nama file: ");
        		scanf("%s", filename);
        		getchar();
    }
    saveFile(filename, buffer, *lineCount);
}

            else if (strncmp(line, "/copy", 5) == 0) {
                if (*lineCount > 0)
                    strcpy(clipboard, buffer[*lineCount - 1]);
                printf("Copy baris terakhir\n");
            }

            else if (strncmp(line, "/paste", 6) == 0) {
                if (*lineCount < MAX_LINES) {
                    strcpy(buffer[*lineCount], clipboard);
                    (*lineCount)++;
                }
            }

            else if (strncmp(line, "/cut", 4) == 0) {
                if (*lineCount > 0) {
                    strcpy(clipboard, buffer[*lineCount - 1]);
                    (*lineCount)--;
                    printf("Cut baris terakhir\n");
                }
            }

            else if (strncmp(line, "/find", 5) == 0) {
                char word[50];
                printf("Cari: ");
                scanf("%s", word);
                getchar();

                for (int i = 0; i < *lineCount; i++) {
                    if (strstr(buffer[i], word)) {
                        printf("Ditemukan di baris %d\n", i + 1);
                    }
                }
            }

            else if (strncmp(line, "/replace", 8) == 0) {
                char find[50], replace[50];
                printf("Find: ");
                scanf("%s", find);
                printf("Replace: ");
                scanf("%s", replace);
                getchar();

                for (int i = 0; i < *lineCount; i++) {
                    if (strcmp(buffer[i], find) == 0) {
                        strcpy(buffer[i], replace);
                    }
                }
            }

            else if (strncmp(line, "/close", 6) == 0) {
                break;
            }

            else {
                printf("Command tidak dikenal\n");
            }
        }

        else {
            if (*lineCount < MAX_LINES) {
                strcpy(buffer[*lineCount], line);
                (*lineCount)++;
            }
        }
    }
}
