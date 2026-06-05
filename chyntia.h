#ifndef CHYNTIA_H
#define CHYNTIA_H

#include "hasbi.h"

void CreateEmpty(EditorState *L);
void NewFile(EditorState *L);
void openFile(char *filename, EditorState *state);
void saveFile(EditorState *state);
void deleteFile(char *filename);

#endif