section .text
	global ft_is_space

ft_is_space:
	xor rax, rax
	cmp rdi, 9
	je _is
	cmp rdi, 10
	je _is
	cmp rdi, 11
	je _is
	cmp rdi, 12
	je _is
	cmp rdi, 13
	je _is
	cmp rdi, 32
	je _is
_not:
	mov rax, 0
	ret
_is:
	mov rax, 1
	ret
