section .text
    global ft_strcpy

ft_strcpy:
    xor rax, rax
    cmp rsi, 0
    je _end
_loop:
    cmp BYTE [rsi + rax], 0
    mov dl, BYTE [rsi + rax]
    mov BYTE [rdi + rax], dl
    je _end
    add rax, 1
    jmp _loop
_end:
    mov rax, rdi
    ret