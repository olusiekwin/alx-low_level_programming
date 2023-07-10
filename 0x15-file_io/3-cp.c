#include "main.h"
/**
 * close_handler - function to handle close errors
 *
 * Description: function to handle close errors
 *
 * @source_file: source file
 * @destination_file: destination_file
 *
 * Return: void
 */
void close_handler(int source_file, int destination_file)
{
	int code;

	code = close(source_file);
	if (code == FILE_ERROR)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
				source_file);
		exit(CANNOT_CLOSE);
	}
	code = close(destination_file);
	if (code == FILE_ERROR)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
				destination_file);
		exit(CANNOT_CLOSE);
	}
}

/**
 * error_handler - function to handle file errors
 *
 * Description: function to handle file errors
 *
 * @source_file: source_file
 * @destination_file: destination_file
 * @argument_values: arguments values
 *
 * Return: void
 */
void error_handler(int source_file, int destination_file,
		char *argument_values[])
{
	if (source_file == FILE_ERROR)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				argument_values[1]);
		exit(DOES_NOT_EXIST_OR_UNABLE_TO_READ);
	}
	if (destination_file == FILE_ERROR)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
				argument_values[2]);
		exit(CANNOT_CREATE_OR_WRITE);
	}
}

/**
 * main - program that copies the content of a file to another file.
 *
 * Description: program that copies the content of a file to another file.
 *
 * @argument_count: number of arguments.
 * @argument_values: arguments array.
 *
 * Return: 0 for sucess anything else is an error
 */
int main(int argument_count, char *argument_values[])
{
	int source_file, destination_file;
	char file_buffer[BUFFER_SIZE];
	ssize_t number_of_characters_read, number_of_characters_written;

	if (argument_count != ARGUMENT_COUNT_EXPECTED)
	{
		dprintf(STDERR_FILENO, "%s\n",
				"Usage: cp file_from file_to");
		exit(INVALID_NUMBER_OF_ARGUMENTS);
	}
	source_file = open(argument_values[1], O_RDONLY);
	destination_file = open(argument_values[2], O_CREAT | O_WRONLY
			| O_TRUNC | O_APPEND, 0664);
	error_handler(source_file, destination_file, argument_values);
	number_of_characters_read = BUFFER_SIZE;
	while (number_of_characters_read == BUFFER_SIZE)
	{
		number_of_characters_read = read(source_file,
				file_buffer, BUFFER_SIZE);
		if (number_of_characters_read == FILE_ERROR)
			error_handler(FILE_ERROR, 0, argument_values);
		number_of_characters_written = write(destination_file,
				file_buffer, number_of_characters_read);
		if (number_of_characters_written == FILE_ERROR)
			error_handler(0, FILE_ERROR, argument_values);
	}
	close_handler(source_file, destination_file);
	return (0);
}
