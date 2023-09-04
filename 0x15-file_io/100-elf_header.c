#include "main.h"

void display_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void display_elf_header(const char *filename) {
    int fd;
    Elf64_Ehdr elf_header;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        display_error("Error opening file");
    }

    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        display_error("Error reading ELF header");
    }

    close(fd);

    /* Check if it's an ELF file */
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        display_error("Not an ELF file");
    }

    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header.e_ident[i]);
    }
    printf("\n");

    printf("Class: %s\n", (elf_header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("Data: %s\n", (elf_header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little-endian" : "2's complement, big-endian");
    printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", elf_header.e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("Type: %d\n", elf_header.e_type);
    printf("Entry point address: %lx\n", (unsigned long)elf_header.e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    const char *filename = argv[1];
    display_elf_header(filename);

    return 0;
}
