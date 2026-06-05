#include <stdio.h>
#include <string.h>

int main() {
    EditorState state;
    int choice;
    char tempFilename[100];

    do {
        printf("====================================\n");
        printf("SIMULASI INSERT NON-BINARY TREE\n");
        printf("=====================================\n");
        printf("1. Tambah Node Baru\n");
        printf("2. Lihat Tabel Memori (Indeks, FS, NB, PR)\n");
        printf("0. Keluar");
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