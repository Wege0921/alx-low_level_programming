#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * handle_error - Prints an error message to the standard
 *	error and exits the program.
 * @message: The error message to be printed.
 * @exit_code: The exit code to be used when terminating the program.
 *
 * This function prints the given error message to
 *	the standard error (file descriptor 2)
 * and then exits the program with the specified exit code.
 */

void handle_error(const char *message, int exit_code)
{
	dprintf(2, "%s\n", message);
	exit(exit_code);
}

/**
 * copy_file - Copies the contents of one file to another.
 * @source: The path to the source file to be copied.
 * @destination: The path to the destination file where
 *	the content will be copied.
 *
 * This function opens the source and destination files,
 *	reads the content from the source file, and writes it
 *	to the destination file in chunks. It uses a buffer
 * to efficiently copy the data.
 */

void copy_file(const char *source, const char *destination)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	fd_from = open(source, O_RDONLY);
	if (fd_from == -1)
	{
		handle_error("Error: Can't read from source file", 98);
	}

	fd_to = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		handle_error("Error: Can't write to destination file", 99);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			handle_error("Error: Can't write to destination file", 99);
		}
	}

	if (bytes_read == -1)
	{
		handle_error("Error: Can't read from source file", 98);
	}

	close(fd_from);
	close(fd_to);
}

/**
 * main - The main entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: 0 on success, and various exit codes on failure.
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		handle_error("Usage: cp file_from file_to", 97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

