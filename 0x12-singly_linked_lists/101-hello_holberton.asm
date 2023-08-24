; File: 101-hello_holberton.asm
; Auth: Enough B Mkhabela
; Desc: 64-bit assembly program that prints
; Hello, Holberton followed by a new line.

section .data
    hello db "Hello, Holberton", 0
    format db "%s", 10, 0 ; %s is the format specifier for a null-terminated string, 10 is the ASCII code for newline

section .text
    global main
    extern printf

main:
    ; Call printf with the format string and the address of the hello string
    mov rdi, format
    mov rsi, hello
    xor rax, rax ; Clear RAX to indicate we're using the cdecl calling convention
    call printf

    ; Exit the program
    mov rdi, 0
    call exit

exit:
    ; Call the exit system call
    mov rax, 60 ; syscall number for exit
    xor rdi, rdi ; exit status 0
    syscall
