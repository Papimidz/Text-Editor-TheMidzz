#include <stdio.h>
#include <string.h>
#include "file_manager.h"
#include "text_editor.h"

void CreateEmpty(List *L){
    L->Head = NULL;
}

void NewFile(List *L){
    address P, delete;

    P = L->Head;

    while (P != NULL){
        hapus = P;
        P = P->next;
        free(delete);
    }

    CreateEmpty(L);
    printf(">> File baru berhasil dibuat.\n");
}