#include <stdio.h>
#include <string.h>
#include "editor.h"

void saveFile(Editor *e, char *filename) {

    FILE *f = fopen(filename,"w");

    if(!f){
        printf("Gagal membuka file\n");
        return;
    }

    for(int i=0;i<e->line_count;i++){
        fputs(e->text[i],f);
    }

    fclose(f);
    printf("File berhasil disimpan\n");
}

void openFile(Editor *e, char *filename) {

    FILE *f = fopen(filename,"r");

    if(!f){
        printf("File tidak ditemukan\n");
        return;
    }

    e->line_count = 0;

    while(fgets(e->text[e->line_count],MAX_LENGTH,f)){
        e->line_count++;
    }

    fclose(f);
}