#include "main.h"


/**
 * read_textfile - Reads and prints a text file to the POSIX standard output
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 if:
 * - The file could not be opened or read
 * - filename is NULL
 * - Write fails or does not write the expected amount of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, n_read;
	ssize_t n_written;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	n_read = read(fd, buf, letters);
	close(fd);
	if (n_read == -1)
	{
		free(buf);
		return (0);
	}

	n_written = write(STDOUT_FILENO, buf, n_read);
	free(buf);
	if (n_written != n_read)
		return (0);

	return (n_written);
}

