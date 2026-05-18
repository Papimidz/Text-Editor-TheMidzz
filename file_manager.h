#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "text_editor.h"

<<<<<<< HEAD
void saveFile(EditorState *state);
void openFile(char *inputFilename, EditorState *state);
void deleteFile(const char *filename);
=======
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
>>>>>>> cc6f08eb492a966358f80bd0adeb2bbab670f148

#endif