section	.text
global	ft_read

ft_read:
	cmp rdx, 0
       	je _end_zero
	jl _err
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
_read_here:
	pop rsi
	pop rdx
	cmp eax, 0
	jne _err
	mov rax, 0
	syscall
	ret
_end_zero:
        mov rax, 0
        ret
_err:
        mov rax, -1
        ret

