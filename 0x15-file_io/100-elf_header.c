#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * 
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	unsigned char buffer[32];

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	bytes_read = read(fd, buffer, 32);
	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	if (bytes_read < 32)
	{
		dprintf(2, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}

	printf("ELF Header:\n");
	printf("\tMagic:\t\t");
	for (int i = 0; i < 16; i++)
		printf("%02x ", buffer[i]);
	printf("\n");

	printf("\tClass:\t\t\t\tELF%d\n", buffer[4] == 1 ? 32 : 64);
	printf("\tData:\t\t\t\t2's complement, %s endian\n", buffer[5] == 1 ? "little" : "big");
	printf("\tVersion:\t\t\t%d (current)\n", buffer[6]);
	printf("\tOS/ABI:\t\t\t\tUNIX - ");
	switch (buffer[7])
	{
	case 0:
		printf("System V\n");
		break;
	case 1:
		printf("HP-UX\n");
		break;
	case 2:
		printf("NetBSD\n");
		break;
	case 3:
		printf("Linux\n");
		break;
	case 4:
		printf("GNU Hurd\n");
		break;
	case 6:
		printf("Solaris\n");
		break;
	case 7:
		printf("AIX\n");
		break;
	case 8:
		printf("IRIX\n");
		break;
	case 9:
		printf("FreeBSD\n");
		break;
	case 10:
		printf("Tru64\n");
		break;
	case 11:
		printf("Novell Modesto\n");
		break;
	case 12:
		printf("OpenBSD\n");
		break;
	case 13:
		printf("OpenVMS\n");
		break;
	case 14:
		printf("NonStop Kernel\n");
		break;
	case 15:
		printf("AROS\n");
		break;
	case 16:
		printf("Fenix OS\n");
		break;
	case 17:
		printf("CloudABI\n");
		break;
	default:
		printf("<unknown: %d>\n", buffer[7]);
	}
	printf("\tABI Version:\t\t\t%d\n", buffer[8]);
	printf("\tType:\t\t\t\t");
	switch (*(unsigned short *)(buffer + 16))
	{
	case 0:
		printf("NONE (No file type)\n");
		break;
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %hu>\n", *(unsigned short *)(buffer + 16));
	}
	printf("\tEntry point address:\t0x");
	if (buffer[4] == 1)
	{
		for (int i = 0; i < 4; i++)
			printf("%02x", buffer[24 + i]);
	}
	else
	{
		for (int i = 0; i < 8; i++)
			printf("%02x", buffer[24 + i]);
	}
	printf("\n");

	close(fd);
	return (0);
}

