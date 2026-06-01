#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "text_editor.h"

typedef struct tNode *address;

void CreateEmpty(EditorState *L);
void openFile(char *filename, EditorState *state);
void deleteFile(char *filename);
void NewFile(EditorState *L);
void saveFile(EditorState *state);

typedef struct tNode {
    char info[256];
    address next;
} Node;

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