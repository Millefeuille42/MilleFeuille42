section .text
    global ft_strdup
    extern malloc

ft_strdup:
    xor rcx, rcx
_len:
    cmp BYTE [rdi + rcx], 0
    add rcx, 1
    je _start_malloc
    jmp _len
_start_malloc:
    add rcx, 1
    push rdi
    mov rsi, rdi
    mov rdi, rcx
    call malloc
    cmp rax, 0
    je _error
    xor rcx, rcx
_loop:
    cmp BYTE [rax + rcx], 0
    mov dl, BYTE [rax + rcx]
    mov BYTE [rsi + rcx], dl
    je _end
    add rcx, 1
    jmp _loop
_error:
    xor rax, rax
_end:
    ret
