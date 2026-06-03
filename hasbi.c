#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "hasbi.h"
#include "chyntia.h"
#include "dzia.h"

    // --- VARIABEL GLOBAL UNTUK FITUR ---
char clipboard[1024] = ""; // Untuk menampung teks yang di copy/cut

// --- FUNGSI BANTUAN (HELPER) BARU ---
// Membantu mengubah Doubly Linked List karakter menjadi string C standar
void getTextString(Text *t, char *buffer) {
    Node *curr = t->head;
    int i = 0;
    while (curr != NULL) {
        buffer[i++] = curr->data;
        curr = curr->next;
    }
    buffer[i] = '\0';
}

// Membantu mengambil pointer ke baris tertentu
LineNode* getLine(EditorState *state, int targetRow) {
    LineNode *curr = state->head;
    int count = 1;
    while (curr != NULL && count < targetRow) {
        curr = curr->next;
        count++;
    }
    return curr;
}

// --- FUNGSI FITUR BARU ---

void copyLine(EditorState *state, int row) {
    LineNode *target = getLine(state, row);
    if (target != NULL) {
        getTextString(&(target->lineContent), clipboard);
        printf(">> Baris %d berhasil disalin ke clipboard!\n", row);
    } else {
        printf(">> Baris tidak ditemukan!\n");
    }
}

void cutLine(EditorState *state, int row) {
    LineNode *target = getLine(state, row);
    if (target != NULL) {
        // 1. Salin teksnya dulu
        getTextString(&(target->lineContent), clipboard);

        // 2. Lepaskan node dari Doubly Linked List
        if (target->prev != NULL) target->prev->next = target->next;
        else state->head = target->next; 

        if (target->next != NULL) target->next->prev = target->prev;
        else state->tail = target->prev; 

        // 3. Bersihkan memori
        clearText(&(target->lineContent));
        free(target);
        state->lineCount--;
        
        printf(">> Baris %d berhasil di-cut ke clipboard!\n", row);
    } else {
        printf(">> Baris tidak ditemukan!\n");
    }
}

void findWord(EditorState *state, char *word) {
    LineNode *curr = state->head;
    char buffer[1024];
    int row = 1;
    int found = 0;

    printf("\n>> Hasil pencarian untuk '%s':\n", word);
    while (curr != NULL) {
        getTextString(&(curr->lineContent), buffer);
        if (strstr(buffer, word) != NULL) { // Mencari kata dalam string
            printf("   - Ditemukan di baris %d: %s\n", row, buffer);
            found = 1;
        }
        curr = curr->next;
        row++;
    }
    if (!found) printf("   (Tidak ada hasil yang cocok)\n");
}

void replaceWord(EditorState *state, char *oldWord, char *newWord) {
    LineNode *curr = state->head;
    char buffer[1024], temp[1024];
    int replacedCount = 0;

    while (curr != NULL) {
        getTextString(&(curr->lineContent), buffer);
        char *pos = strstr(buffer, oldWord);
        
        // Jika kata ditemukan dalam baris ini
        if (pos != NULL) {
            int index = pos - buffer;
            strncpy(temp, buffer, index); // Ambil teks sebelum kata yang diganti
            temp[index] = '\0';
            
            // Gabungkan: (Teks Sebelum) + (Kata Baru) + (Sisa Teks)
            sprintf(temp + index, "%s%s", newWord, pos + strlen(oldWord));
            
            // Hapus isi line yang lama, lalu masukkan teks baru per karakter
            clearText(&(curr->lineContent));
            for(size_t i = 0; i < strlen(temp); i++) {
                insertChar(&(curr->lineContent), temp[i]);
            }
            replacedCount++;
        }
        curr = curr->next;
    }
    printf(">> Selesai! %d baris telah diperbarui.\n", replacedCount);
}


// --- KODE ASLIMU (Sedikit Dimodifikasi di Bagian Input) ---

void initEditor(EditorState *state) {
    state->head = NULL;
    state->tail = NULL;
    state->lineCount = 0;
    state->filename[0] = '\0';
}

void addLine(EditorState *state, char *inputText) {
    LineNode *newNode = (LineNode*) malloc(sizeof(LineNode)); 
    
    initText(&(newNode->lineContent)); 
    
    for (size_t i = 0; i < strlen(inputText); i++) {
        insertChar(&(newNode->lineContent), inputText[i]);
    }

    newNode->next = NULL;
    newNode->prev = state->tail;

    if (state->head == NULL) {
        state->head = newNode;
    } else {
        state->tail->next = newNode;
    }
    state->tail = newNode;
    state->lineCount++;
}

void editor(EditorState *state) {
    char input[256];
    
    while (1) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n=== EDITOR THE MIDZZ [%s] ===\n", strlen(state->filename) ? state->filename : "Untitled");
        
        LineNode *currLine = state->head;
        int row = 1;
        while (currLine != NULL) {
            printf("%d | ", row++);
            displayText(&(currLine->lineContent)); 
            currLine = currLine->next;
        }
        
        printf("\nMenu:\n");
        printf("Teks biasa -> Tambah baris baru\n");
        printf("Perintah   -> /copy <baris>, /cut <baris>, /paste, /find <kata>, /replace <lama> <baru>, /save, /close\n");
        printf(">> ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        input[strcspn(input, "\n")] = 0;

        // Parsing Input
        char cmd[50] = "", arg1[100] = "", arg2[100] = "";
        sscanf(input, "%s %s %s", cmd, arg1, arg2);

        if (cmd[0] == '/') {
            if (strcmp(cmd, "/save") == 0) {
                if (strlen(state->filename) == 0) {
                    printf("Masukkan nama file baru: ");
                    scanf("%s", state->filename); getchar();
                }
                saveFile(state);
                printf("... Tekan Enter"); getchar();
            } 
            else if (strcmp(cmd, "/close") == 0) {
                break;
            }
            else if (strcmp(cmd, "/copy") == 0) {
                copyLine(state, atoi(arg1));
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/cut") == 0) {
                cutLine(state, atoi(arg1));
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/paste") == 0) {
                if (strlen(clipboard) > 0) {
                    addLine(state, clipboard);
                    printf(">> Paste berhasil di akhir baris!\n");
                } else {
                    printf(">> Clipboard kosong!\n");
                }
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/find") == 0) {
                findWord(state, arg1);
                printf("... Tekan Enter"); getchar();
            }
            else if (strcmp(cmd, "/replace") == 0) {
                replaceWord(state, arg1, arg2);
                printf("... Tekan Enter"); getchar();
            }
            else {
                printf(">> Perintah tidak dikenali!\n");
                printf("... Tekan Enter"); getchar();
            }
        } 
        else if (strlen(input) > 0) { // Jika bukan perintah dan tidak kosong
            addLine(state, input);
        }
    }
}