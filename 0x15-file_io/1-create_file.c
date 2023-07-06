#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * create_file - creates file
 * @filename: pointer to file
 * @text_content: pointer to content to be writer
 *
 * Return: bytes written
 */
int create_file(const char *filename, char *text_content)
{
	int d;
	size_t wbyte;
	size_t len;

	if (filename == NULL)
		return (-1);

	d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (d == -1)
		{
			return (-1);
		}
	if (text_content != NULL)
	{
		len = 0;
		while (text_content[len] != '\0')
		{
			len++;
		}
		wbyte = write(d, text_content, len);
	}
	close(d);
	if (wbyte == (size_t)-1)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
