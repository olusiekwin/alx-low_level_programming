#ifndef HEADER_H
#define HEADER_H

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/**
 * Functions related to ELF header
*/
void verify_elf(unsigned char *e_ident);
void print_elf_magic(unsigned char *e_ident);
void print_elf_class(unsigned char *e_ident);
void print_elf_data(unsigned char *e_ident);
void print_elf_version(unsigned char *e_ident);
void print_elf_abi(unsigned char *e_ident);
void print_elf_osabi(unsigned char *e_ident);
void print_elf_type(unsigned int e_type, unsigned char *e_ident);
void print_elf_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);

#endif /* HEADER_H */

