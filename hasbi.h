#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "text.h"
void initEditor(EditorState *state);
void addLine(EditorState *state, char *inputText);
void editor(EditorState *state);

#endif