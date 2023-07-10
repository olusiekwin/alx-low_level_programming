#include "main.h"

/**
 * print_magic_number - Prints the ELF magic number.
 *
 * Description: This function takes a pointer to the e_ident
 * field of the ELF header as input, and prints the magic number
 * in hexadecimal format.
 *
 * @e_ident: Pointer to the ELF header e_ident field.
 *
 * Return: Void
 */
void print_magic_number(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i],
				i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - Prints the ELF header class.
 *
 * Description: This function takes a pointer to the e_ident
 * field of the ELF header as input, and prints the class of
 * the ELF file.
 *
 * @e_ident: Pointer to the ELF header e_ident field.
 *
 * Return: void
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * print_data - prints the encoding of the data
 *
 * @e: pointer to the ELF header struct
 *
 * Return: void
 */
void print_data(Elf64_Ehdr *e)
{
	printf("  Data:                              ");
	switch (e->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		case ELFDATANONE:
			printf("none\n");
			break;
		default:
			printf("<unknown: %x>\n", e->e_ident[EI_DATA]);
			break;
	}
}


/**
 * print_version - prints the ELF version
 *
 * @e: pointer to the ELF header struct
 *
 * Return: void
 */
void print_version(Elf64_Ehdr *e)
{
	printf("  Version:                           %d",
			e->e_version);
	if (e->e_version == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - prints the ELF OS/ABI
 *
 * @e: pointer to the ELF header struct
 *
 * Return: void
 */
void print_osabi(Elf64_Ehdr *e)
{
	char *osabi_str;

	switch (e->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			osabi_str = "UNIX - System V";
			break;
		case ELFOSABI_HPUX:
			osabi_str = "UNIX - HP-UX";
			break;
		case ELFOSABI_NETBSD:
			osabi_str = "UNIX - NetBSD";
			break;
		case ELFOSABI_LINUX:
			osabi_str = "UNIX - Linux";
			break;
		case ELFOSABI_SOLARIS:
			osabi_str = "UNIX - Solaris";
			break;
		case ELFOSABI_IRIX:
			osabi_str = "UNIX - IRIX";
			break;
		case ELFOSABI_FREEBSD:
			osabi_str = "UNIX - FreeBSD";
			break;
		case ELFOSABI_TRU64:
			osabi_str = "UNIX - TRU64";
			break;
		case ELFOSABI_ARM:
			osabi_str = "ARM";
			break;
		case ELFOSABI_STANDALONE:
			osabi_str = "Standalone application";
			break;
		default:
			printf("<unknown: %x>\n", e->e_ident[EI_OSABI]);
			break;
	}
	printf("  OS/ABI:                            %s\n",
			osabi_str);
}

/**
 * print_abiversion - prints the ABI version
 *
 * @file: the ELF file
 *
 * Return: void
 */
void print_abiversion(int file)
{
	unsigned char buffer[BUFFER_SIZE];
	Elf32_Ehdr *elf_header = (Elf32_Ehdr *) buffer;

	lseek(file, 0, SEEK_SET);
	if (read(file, elf_header, sizeof(*elf_header)) == -1)
	{
		fprintf(stderr, "read error\n");
		exit(98);
	}

	printf("  ABI Version:                       %d\n",
			elf_header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints ELF file type
 * @e_type: ELF file type
 *
 * Return: void
 */
void print_type(uint16_t e_type)
{
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
			break;
	}
}

/**
 * print_entry - Prints the entry point address of the ELF header
 *
 * @elf_header: A pointer to the ELF header
 *
 * Return: void
 */
void print_entry(void *elf_header)
{
	Elf32_Ehdr *header_32 = (Elf32_Ehdr *)elf_header;
	Elf64_Ehdr *header_64 = (Elf64_Ehdr *)elf_header;

	printf("  Entry point address:               0x");

	if (header_32->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%x\n", (unsigned int)header_32->e_entry);
	else if (header_32->e_ident[EI_CLASS] == ELFCLASS64)
		printf("%lx\n", (unsigned long)header_64->e_entry);
}

/**
 * print_all - prints all sections
 *
 * @ehdr: elf header
 * @fd: file descriptor
 *
 * Returns: void
 */
void print_all(Elf64_Ehdr *ehdr, int fd)
{
	print_magic_number(ehdr->e_ident);
	print_class(ehdr->e_ident);
	print_data(ehdr);
	print_version(ehdr);
	print_osabi(ehdr);
	print_abiversion(fd);
	print_type(ehdr->e_type);
	print_entry(ehdr);
}

/**
 * iself - function to check if is ELF
 *
 * @e_ident: A pointer to an array containing the ELF magic numbers
 *
 * Return: void
 */
void iself(unsigned char *e_ident)
{
	if (e_ident[0] != 127 &&
			e_ident[1] != 'E' &&
			e_ident[2] != 'L' &&
			e_ident[3] != 'F')
	{
		fprintf(stderr, "Error: Invalid ELF file\n");
		exit(98);
	}
}

/**
 * main - prints the ELF headers of a given file
 *
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: On success, returns 0. On failure, returns an error code.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: File %s failed to open\n", argv[1]);
		exit(98);
	}
	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
	{
		fprintf(stderr, "Error: Failed to read ELF header\n");
		close(fd);
		exit(98);
	}
	iself(ehdr.e_ident);
	print_all(&ehdr, fd);
	close(fd);
	return (0);
}
