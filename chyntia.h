#ifndef CHYNTIA_H
#define CHYNTIA_H
#include "hasbi.h"

typedef struct tNode *address;

void CreateEmpty(EditorState *L);
void openFile(char *filename, EditorState *state);
void deleteFile(char *filename);
void NewFile(EditorState *L);
void saveFile(EditorState *state);

typedef struct {
    address Head;
} List;

#endif