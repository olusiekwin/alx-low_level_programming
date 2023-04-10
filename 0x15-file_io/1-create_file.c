#include "main.h"


/**
 * create_file - creates a file and a string to it
 * @fName: pointer to created file name
 * @tContent: pointer to string written into the file.
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *fName, char *tContent)
{
	int fd, b, l = 0;



	if (fName == NULL)
		return (-1);

	if (tContent != NULL)
	{
		while (tContent[l] != '\0')
			l++;
	}

	fd = open(fName, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	b = write(fd, tContent, l);
	if (b == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
