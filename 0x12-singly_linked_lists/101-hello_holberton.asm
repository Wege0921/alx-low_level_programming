section .data
    hello db "Hello, Holberton", 0
    newline db 10, 0 ; Newline character

section .text
    global main
    extern printf

main:
    push rdi     ; Preserve registers
    push rsi
    push rdx

    mov rdi, hello ; Load string to print
    call printf ; Call printf

    mov rdi, newline ; Load newline character
    call printf ; Call printf

    pop rdx      ; Restore registers
    pop rsi
    pop rdi

    ret          ; Return from main

