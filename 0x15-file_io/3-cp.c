#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <errno.h>


/**
 * cp - function that copies content of a file to another
 * @argc: number of arguments
 * @argv: data for the arguments
 *
 * Return: void
 */

void cp(int argc, char *argv[])
{
	char *file_from;
	char *file_to;
	int d_from;
	int d_to;
	ssize_t rbyte;
	ssize_t wbyte;
	char buffer[total];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	file_from = argv[1];
	file_to = argv[2];

	if (access(argv[2], F_OK) == 0)
	{
		if (truncate(argv[2], 0) == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't truncate file %s\n", file_to);
			exit(99);
		}
	}
	d_from = open(file_from, O_RDONLY);
	if (d_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	d_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (d_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant write to file %s\n", file_to);
		exit(99);
	}

	while ((rbyte = read(d_from, buffer, sizeof(buffer))) > 0)
	{
		wbyte = write(d_to, buffer, rbyte);
		if (wbyte == -1)
		{
			dprintf(STDERR_FILENO, "Error: cant write to file %s\n", file_to);
			exit(99);
		}
	}
	if ((ssize_t)rbyte == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant read file %s\n", file_from);
		exit(99);
	}
	if (close(d_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant close d_from %d\n", d_from);
			exit(100);
	}
	if (close(d_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: cant close d_to %d\n", d_to);
			exit(100);
	}
}
