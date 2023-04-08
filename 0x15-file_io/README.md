# Requirements
## General
+ Allowed editors: `vi, vim, emacs`
+ All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
+ All your files should end with a new line
+ A `README.md` file, at the root of the folder of the project is mandatory
+ Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`
+ You are not allowed to use global variables
+ No more than 5 functions per file
+ The only C standard library functions allowed are `malloc`, `free` and `exit`. Any use of functions like `printf, puts, calloc, realloc` etc… is forbidden
+ Allowed syscalls:`read, write, open, close`
+ You are allowed to use `_putchar`
+ You don’t have to push `_putchar.c`, we will use our file. If you do it won’t be taken into account
+ In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
+ The prototypes of all your functions and the prototype of the function `_putchar` should be included in your header file called `main.h`
+ Don’t forget to push your header file
+ All your header files should be include guarded
+ Tip: always prefer using symbolic constants `(POSIX)` vs numbers when it makes sense. For instance `read(STDIN_FILENO, ... vs read(0, ...`

## Header File :file_folder:

* [holberton.h](./holberton.h): Header file containing prototypes for all
functions written in the project.

| File                               | Prototype /Usage                                                    |
| ---------------------------------  | ------------------------------------------------------------------- |
| `0-read_textfile.c`                | `ssize_t read_textfile(const char *filename, size_t letters);`      |
| `1-create_file.c`                  | `int create_file(const char *filename, char *text_content);`        |
| `2-append_text_to_file.c`          | `int append_text_to_file(const char *filename, char *text_content);`|
| `3-cp.c`                           | `cp file_from file_to`                                              |
| `100-elf_header.c`                 | `elf_header elf_filename`                                           |
         
