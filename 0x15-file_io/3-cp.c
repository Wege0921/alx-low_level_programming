#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


/**
 * createBuffer - Create a character buffer for file operations.
 * @targetFile: The name of the target file for error messages.
 *
 * Return: A pointer to the newly allocated character buffer.
 *
 * This function allocates memory for a character buffer with a size of 1024
 * bytes and checks for successful allocation. If allocation fails, it prints
 * an error message to the standard error and exits with a status code of 99.
 *
 * Note: The caller is responsible for freeing the memory allocated by this
 * function when it's no longer needed.
 */
char *createBuffer(char *targetFile)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", targetFile);
		exit(99);
	}

	return (buffer);
}


/**
 * closeFile - Closes file descriptors.
 * @fileDescriptor: The file descriptor to be closed.
 */

void closeFile(int fileDescriptor)
{
	int result;

	result = close(fileDescriptor);
	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileDescriptor);
		exit(100);
	}
}


/**
 * main - Copies the contents of a file to another file.
 * @argumentCount: The number of arguments supplied to the program.
 * @arguments: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */


int main(int argumentCount, char *arguments[])
{
	int sourceFileDescriptor, targetFileDescriptor, bytesRead, bytesWritten;
	char *buffer;

	if (argumentCount != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = createBuffer(arguments[2]);
	sourceFileDescriptor = open(arguments[1], O_RDONLY);
	bytesRead = read(sourceFileDescriptor, buffer, 1024);
	targetFileDescriptor = open(arguments[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (sourceFileDescriptor == -1 || bytesRead == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arguments[1]);
			free(buffer);
			exit(98);
		}

		bytesWritten = write(targetFileDescriptor, buffer, bytesRead);
		if (targetFileDescriptor == -1 || bytesWritten == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arguments[2]);
			free(buffer);
			exit(99);
		}

		bytesRead = read(sourceFileDescriptor, buffer, 1024);
		targetFileDescriptor = open(arguments[2], O_WRONLY | O_APPEND);

	} while (bytesRead > 0);

	free(buffer);
	closeFile(sourceFileDescriptor);
	closeFile(targetFileDescriptor);
	return (0);
}



