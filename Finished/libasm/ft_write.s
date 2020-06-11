section .text
    global ft_write
	extern __errno_location
ft_write:
	cmp rdx, 0
	jl _err
	je _end_zero
	cmp rdi, 0
	jl _err
	cmp rsi, 0
	je _err
_get_fd:
	push rdx
	push rsi
	xor rsi, rsi
	mov esi, 1
	mov rax, 72
	syscall
_write_here:
	pop rsi
	pop rdx
	cmp eax, 0
	jne _err
	mov rax, 1
	syscall
	ret
_end_zero:
	mov rax, 0
	ret
_err:
	mov rax, -1
    mov rcx, rax
    call __errno_location
    mov [rax], rcx
	mov rax, -1
	ret
