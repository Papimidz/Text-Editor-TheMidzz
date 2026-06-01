#ifndef dzia_H
#define dzia_H

#include "text.h"
#include "hasbi.h"

void initText(Text* t);
void insertChar(Text* t, char c);
void displayText(Text* t);
void clearText(Text* t);
int getLength(Text* t);
int isEmpty(Text* t);
Node* getNodeAt(Text* t, int index);

#endif