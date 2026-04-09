#include <stdio.h>
#include <string.h>
#include "file_manager.h"
#include "text_editor.h"

#define MAX_LINES 100
#define MAX_COL 100

int main() {
    char buffer[MAX_LINES][MAX_COL];
    int lineCount = 0;
    char filename[100] = "";
    int choice;

    do {
        printf("\n=== TEXT EDITOR THEMIDZZ ===\n");
        printf("1. New File\n");
        printf("2. Open File\n");
        printf("3. Delete File\n");
        printf("0. Exit\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                lineCount = 0;
                filename[0] = '\0';
                editor(buffer, &lineCount, filename);
                break;

            case 2:
                printf("Nama file: ");
                scanf("%s", filename);
                getchar();
                openFile(filename, buffer, &lineCount);
                editor(buffer, &lineCount, filename);
                break;
                
            case 3:
                printf("Nama file: ");
                scanf("%s", filename);
                getchar();
                deleteFile(filename);
                break;
        }

    } while (choice != 0);

    return 0;
}