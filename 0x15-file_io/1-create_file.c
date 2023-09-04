#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"


/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, len;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(file_descriptor);
		return (1);
	}

	for (len = 0; text_content[len] != '\0'; len++)
		;

	bytes_written = write(file_descriptor, text_content, len);

	if (bytes_written == -1 || bytes_written != len)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
