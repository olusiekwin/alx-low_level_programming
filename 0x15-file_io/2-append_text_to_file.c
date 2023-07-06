#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: pointer to the file
 * @text_content: string to be appended
 *
 * Return: 1 on sucess and -1 if not
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int d;
	int wbytes;
	int len;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		return (1);
	}

	if (access(filename, W_OK) == -1)
	{
		return (-1);
	}

	d = open(filename, O_WRONLY | O_APPEND);
	if (d == -1)
	{
		return (-1);
	}
	len = strlen(text_content);
	wbytes = write(d, text_content, len);
	if (wbytes == -1)
	{
		close(d);
		return (-1);
	}
	close(d);
	return (1);
}
