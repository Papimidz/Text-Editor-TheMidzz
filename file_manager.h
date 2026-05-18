#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "text_editor.h"

typedef struct tNode *address;

typedef struct tNode {
    char info[256]
    address next;
} Node;

typedef struct {
    address Head;
} List;

void CreateEmpty(List *L);
void NewFile(List *L);


#endif