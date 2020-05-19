section .text
    global ft_strdup
    extern malloc
    extern ft_strlen
    extern ft_strcpy

ft_strdup:
    push rdi
    call ft_strlen
_start_malloc:
    add rax, 1
    mov rdi, rax
    call malloc
    cmp rax, 0
    je _error
    pop rsi
    mov rdi, rax
    call ft_strcpy 
    jmp _end
_error:
    xor rax, rax
_end:
    ret
