#ifndef CHYNTIA_H
#define CHYNTIA_H

void CreateEmpty(EditorState *L);
void NewFile(EditorState *L);
void openFile(char *filename, EditorState *state);
void saveFile(EditorState *state);
void deleteFile(char *filename);
void CreateEmpty(List *L);
void NewFile(List *L);

#endif