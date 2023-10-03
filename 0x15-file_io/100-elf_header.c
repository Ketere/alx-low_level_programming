#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class: %d-bit\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);

    printf("Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" : "Unknown");

    printf("Version: %d\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);

    printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type: %d\n", header->e_type);

    printf("Entry point address: %lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error");
        return 98;
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        perror("Error");
        close(fd);
        return 98;
    }

    // Check if it's a valid ELF file
    if (header.e_ident[EI_MAG0] != ELFMAG0 || 
        header.e_ident[EI_MAG1] != ELFMAG1 || 
        header.e_ident[EI_MAG2] != ELFMAG2 || 
        header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        return 98;
    }

    print_elf_header_info(&header);

    close(fd);
    return 0;
}
