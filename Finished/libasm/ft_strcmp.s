section .text
    global ft_strcmp

ft_strcmp:
    xor rax, rax
_loop:
    mov dl, BYTE [rdi + rax]
    cmp dl, BYTE [rsi + rax]
    jl _inferior
    jg _superior
    cmp BYTE [rdi + rax], 0
    je _zero
    cmp BYTE [rsi + rax], 0
    je _zero
    add rax, 1
    jmp _loop
_superior:
    mov rax, 1
    ret
_inferior:
    mov rax, -1
    ret
_zero:
    mov rax, 0
    ret