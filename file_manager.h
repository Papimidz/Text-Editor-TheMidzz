#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "text.h"

void CreateEmpty(EditorState *L);
void openFile(char *filename, EditorState *state);
void deleteFile(char *filename);
void NewFile(EditorState *L);
void saveFile(EditorState *state);


#endif