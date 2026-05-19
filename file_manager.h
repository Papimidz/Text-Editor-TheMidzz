#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "text.h"

<<<<<<< HEAD
void CreateEmpty(EditorState *L);
void openFile(char *filename, EditorState *state);
void deleteFile(char *filename);
void NewFile(EditorState *L);
void saveFile(EditorState *state);
=======
typedef struct tNode {
    char info[256];
    address next;
} Node;
>>>>>>> eda6f48d513eb07e8dacb8fa6476dc7dc710c58e


#endif