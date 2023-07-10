#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - short description
 *
 * Description: long description
 *
 * @filename: argument_1 description
 * @letters: argument_2 description
 *
 * Return: return description
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	size_t number_of_characters_printed;
	int character_to_print;
	FILE *file_stream;

	number_of_characters_printed = 0;

	if (filename == NULL)
		return (0);

	file_stream = fopen(filename, "r");

	if (file_stream == NULL)
		return (0);

	character_to_print = fgetc(file_stream);
	while (number_of_characters_printed <= letters)
	{
		if (number_of_characters_printed == letters || character_to_print == -1)
			break;
		if (write(STDOUT_FILENO, &character_to_print, 1) == -1)
			return (0);

		number_of_characters_printed++;
		character_to_print = fgetc(file_stream);
	}

	fclose(file_stream);
	return (number_of_characters_printed);
}
