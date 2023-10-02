#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validateElfFile(unsigned char *magicNumbers);
void printElfMagicNumbers(unsigned char *magicNumbers);
void printElfClass(unsigned char *magicNumbers);
void printElfData(unsigned char *magicNumbers);
void printElfVersion(unsigned char *magicNumbers);
void printElfOsAbi(unsigned char *magicNumbers);
void printElfAbiVersion(unsigned char *magicNumbers);
void printElfType(unsigned int fileType, unsigned char *magicNumbers);
void printElfEntryPoint(unsigned long int entryPoint, unsigned char *magicNumbers);
void closeElfFile(int fileDescriptor);

/**
 * validateElfFile - Checks if a file is an ELF file.
 * @magicNumbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit with code 98.
 */
void validateElfFile(unsigned char *magicNumbers)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (magicNumbers[index] != 127 &&
            magicNumbers[index] != 'E' &&
            magicNumbers[index] != 'L' &&
            magicNumbers[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printElfMagicNumbers - Prints the magic numbers of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printElfMagicNumbers(unsigned char *magicNumbers)
{
    int index;

    printf(" Magic: ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", magicNumbers[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printElfClass - Prints the class of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF class.
 */
void printElfClass(unsigned char *magicNumbers)
{
    printf(" Class: ");

    switch (magicNumbers[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", magicNumbers[EI_CLASS]);
    }
}

/**
 * printElfData - Prints the data of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF class.
 */
void printElfData(unsigned char *magicNumbers)
{
    printf(" Data: ");

    switch (magicNumbers[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", magicNumbers[EI_CLASS]);
    }
}

/**
 * printElfVersion - Prints the version of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF version.
 */
void printElfVersion(unsigned char *magicNumbers)
{
    printf(" Version: %d",
           magicNumbers[EI_VERSION]);

    switch (magicNumbers[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * printElfOsAbi - Prints the OS/ABI of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF version.
 */
void printElfOsAbi(unsigned char *magicNumbers)
{
    printf(" OS/ABI: ");

    switch (magicNumbers[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", magicNumbers[EI_OSABI]);
    }
}

/**
 * printElfAbiVersion - Prints the ABI version of an ELF header.
 * @magicNumbers: A pointer to an array containing the ELF ABI version.
 */
void printElfAbiVersion(unsigned char *magicNumbers)
{
    printf(" ABI Version: %d\n",
           magicNumbers[EI_ABIVERSION]);
}

/**
 * printElfType - Prints the type of an ELF header.
 * @fileType: The ELF type.
 * @magicNumbers: A pointer to an array containing the ELF class.
 */
void printElfType(unsigned int fileType, unsigned char *magicNumbers)
{
    if (magicNumbers[EI_DATA] == ELFDATA2MSB)
        fileType >>= 8;

    printf(" Type: ");

    switch (fileType)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\
	}
}
