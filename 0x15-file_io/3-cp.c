#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_IO_stat(int stat, int fd, char *fName, char mode);
/**
 * main - copies the content from one file to another
 * @argc: counts arguments
 * @argv: pass arguments
 *
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int source_file, d, n_read = 1024, wrote, c_s_f, close_d;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	source_file = open(argv[1], O_RDONLY);
	check_IO_stat(source_file, -1, argv[1], 'O');
	d = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO_stat(d, -1, argv[2], 'W');
	while (n_read == 1024)
	{
		n_read = read(source_file, buffer, sizeof(buffer));
		if (n_read == -1)
			check_IO_stat(-1, -1, argv[1], 'O');
		wrote = write(d, buffer, n_read);
		if (wrote == -1)
			check_IO_stat(-1, -1, argv[2], 'W');
	}
	c_s_f = close(source_file);
	check_IO_stat(c_s_f, source_file, NULL, 'C');
	close_d = close(d);
	check_IO_stat(close_d, d, NULL, 'C');
	return (0);
}

/**
 * check_IO_stat - checks if possible to opened or closed file.
 * @stat:  descriptor of the file to be opened
 * @fName: The filename
 * @mode: close or open
 * @fd: file descriptor
 *
 * Return: void
 */
void check_IO_stat(int stat, int fd, char *fName, char mode)
{
	if (mode == 'C' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", fName);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fName);
		exit(99);
	}
}
