#include <stdio.h>
#include <string.h>
#include "file_manager.h"
#include "text_editor.h"
#include "text_tools.h"

#define MAX 1000

int main() {
    char buffer[MAX] = "";
    char clipboard[MAX] = "";
    char filename[100];
    int choice;

    do {
        printf("\nTEKS EDITOR THEMIDZZ\n");
        printf("ISI SEKARANG:\n%s\n", buffer);

        printf("\nMenu:\n");
        printf("1. New File\n");
        printf("2. Open File\n");
        printf("3. Save File\n");
        printf("4. Delete File\n");
        printf("5. Tambah Teks\n");
        printf("6. Copy\n");
        printf("7. Paste\n");
        printf("8. Cut\n");
        printf("9. Find & Replace\n");
        printf("10. Close Tab\n");
        printf("0. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                newFile(buffer);
                break;

            case 2:
                printf("Nama file: ");
                scanf("%s", filename);
                getchar();
                openFile(filename, buffer);
                break;

            case 3:
                printf("Nama file: ");
                scanf("%s", filename);
                getchar();
                saveFile(filename, buffer);
                break;

            case 4:
                printf("Nama file: ");
                scanf("%s", filename);
                getchar();
                deleteFile(filename);
                break;

            case 5:
                appendText(buffer);
                break;

            case 6:
                copyText(buffer, clipboard);
                break;

            case 7:
                pasteText(buffer, clipboard);
                break;

            case 8:
                cutText(buffer, clipboard);
                break;

            case 9:
                findReplace(buffer);
                break;

            case 10:
                closeTab();
                break;
        }

    } while (choice != 0);

    return 0;
}
