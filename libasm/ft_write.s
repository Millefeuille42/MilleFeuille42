section .text
    global ft_write

ft_write:
	mov	rax, 0x2000004
	syscall
	ret
