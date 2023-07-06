#ifndef MAIN_H
#define MAIN_H
#define total 1024
#include <stddef.h>
int _putchar(char c);
size_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void cp(int argc, char* argv[]);











#endif /* MAIN_H */
