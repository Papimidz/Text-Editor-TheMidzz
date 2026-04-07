#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

void saveFile(const char *filename, char *buffer);
void openFile(const char *filename, char *buffer);
void deleteFile(const char *filename);

#endif