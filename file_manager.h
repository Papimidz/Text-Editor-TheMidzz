#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "text_editor.h"

void saveFile(EditorState *state);
void openFile(char *inputFilename, EditorState *state);
void deleteFile(const char *filename);

#endif