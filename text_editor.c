#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "text_editor.h"
#include "file_manager.h"

void editor(EditorState *state) {
    char line[100];
    char clipboard[100];

    while (1) {
        printf("\n=== EDITOR THE MIDZZ (%s) ===\n", strlen(state->filename) ? state->filename : "Untitled");
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        int i; 
        for (i = 0; i < state->lineCount; i++) {
            printf("%s\n", state->buffer[i]);
        }
        
        printf("\nKetik teks atau command:\n");
        printf("/save /copy /paste /cut /find /replace /close\n>> ");

        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0;

        if (line[0] == '/') {

            if (strncmp(line, "/save", 5) == 0) {
                if (strlen(state->filename) == 0) {
                    printf("Nama file: ");
                    scanf("%s", state->filename);
                    getchar();
                }
                saveFile(state);
                
                printf("Tekan Enter untuk lanjut...");
                getchar();
            }

            else if (strncmp(line, "/copy", 5) == 0) {
                if (state->lineCount > 0)
                    strcpy(clipboard, state->buffer[state->lineCount - 1]);
                printf("Copy baris terakhir\n");
            }

            else if (strncmp(line, "/paste", 6) == 0) {
                if (state->lineCount < MAX_LINES) {
                    strcpy(state->buffer[state->lineCount], clipboard);
                    (state->lineCount)++;
                }
            }

            else if (strncmp(line, "/cut", 4) == 0) {
                if (state->lineCount > 0) {
                    strcpy(clipboard, state->buffer[state->lineCount - 1]);
                    (state->lineCount)--;
                    printf("Cut baris terakhir\n");
                }
            }

            else if (strncmp(line, "/find", 5) == 0) {
                char word[50];
                printf("Cari: ");
                scanf("%s", word);
                getchar();

                int found = 0;
                for (int i = 0; i < state->lineCount; i++) {
                    if (strstr(state->buffer[i], word)) {
                        printf("Ditemukan di baris %d\n", i + 1);
                        found = 1;
                    }
                }
                if (!found) printf("Kata tidak ditemukan.\n");
       
                printf("Tekan Enter untuk lanjut...");
                getchar();
            }

            else if (strncmp(line, "/replace", 8) == 0) {
                char find[50], replace[50];
                printf("Find: ");
                scanf("%s", find);
                printf("Replace: ");
                scanf("%s", replace);
                getchar();

                for (int i = 0; i < state->lineCount; i++) {
                    if (strcmp(state->buffer[i], find) == 0) {
                        strcpy(state->buffer[i], replace);
                    }
                }
            }

            else if (strncmp(line, "/close", 6) == 0) {
                break;
            }

            else {
                printf("Command tidak dikenal\n");
                printf("Tekan Enter untuk lanjut...");
                getchar();
            }
        }

        else {
            if (state->lineCount < MAX_LINES) {
                strcpy(state->buffer[state->lineCount], line);
                (state->lineCount)++;
            }
        }
    }
}