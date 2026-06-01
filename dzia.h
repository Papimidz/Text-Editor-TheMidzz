#ifndef TEXT_ENGINE_H
#define TEXT_ENGINE_H

#include "text.h"
#include "text_editor.h"

void initText(Text* t);
void insertChar(Text* t, char c);
void displayText(Text* t);
void clearText(Text* t);
int getLength(Text* t);
int isEmpty(Text* t);
Node* getNodeAt(Text* t, int index);

#endif