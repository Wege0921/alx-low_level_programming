#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The text content to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, len;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

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

