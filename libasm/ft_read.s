section	.text
global	ft_read

ft_read:
	mov		rax, 0x2000003
	syscall
	ret