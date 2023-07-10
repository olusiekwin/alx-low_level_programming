#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 *
 * Description: function that appends text at the end of a file
 *
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 exists. -1 does not exist
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	if (text_content)
		if (write(file_descriptor, text_content,
					strlen(text_content)) == (ssize_t) -1)
			return (-1);
	close(file_descriptor);
	return (1);
}
