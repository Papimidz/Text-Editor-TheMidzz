#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H


void saveFile(const char *filename, char buffer[][100], int lineCount);
void openFile(const char *filename, char buffer[][100], int *lineCount);

void saveFile(const char *filename, char *buffer);
void openFile(const char *filename, char *buffer);
void deleteFile(const char *filename);

#endif