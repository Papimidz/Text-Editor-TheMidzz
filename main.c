#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hasbi.h"
#include "chyntia.h"
#include "dzia.h"

int main() {
    EditorState state;
    int choice;
    char tempFilename[100];

    CreateEmpty(&state);

    do {
        printf("\n|===== TEXT EDITOR THEMIDZZ =====|\n");
        printf("1. New File\n");
        printf("2. Open File\n");
        printf("3. Save File\n");
        printf("4. Delete File\n");
        printf("0. Exit\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                NewFile(&state);
                editor(&state);
                break;

            case 2:
                printf("Nama file: ");
                scanf("%s", tempFilename);
                getchar();
                openFile(tempFilename, &state);
                if (strlen(state.filename) > 0) {
                    editor(&state);
                }
                break;
                
            case 3:
                if (strlen(state.filename) == 0) {
                    printf("Masukkan nama file untuk menyimpan: ");
                    scanf("%s", state.filename);
                    getchar();
                }
                saveFile(&state);
                break;
            
            case 4:
                printf("Nama file yang akan dihapus: ");
                scanf("%s", tempFilename);
                getchar();
                deleteFile(tempFilename);
                break;
                
            case 0:
                printf("Menutup Text Editor. Sampai jumpa!\n");
                break;
            
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
                break;    
        }

    } while (choice != 0);

    return 0;
}