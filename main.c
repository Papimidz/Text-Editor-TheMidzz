#include <stdio.h>
#include <string.h>
#include "file_manager.h"
#include "text_editor.h"

int main() {
    EditorState state;
    int choice;
    char tempFilename[100];

    do {
        printf("\n===== TEXT EDITOR THEMIDZZ =====\n");
        printf("1. New File\n");
        printf("2. Open File\n");
        printf("3. Delete File\n");
        printf("0. Exit\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                state.lineCount = 0;
                state.filename[0] = '\0';
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
                printf("Nama file: ");
                scanf("%s", tempFilename);
                getchar();
                deleteFile(tempFilename);
                break;
        }

    } while (choice != 0);

    return 0;
}