section .text
	global ft_c_inset

ft_c_inset:
	xor rax, rax
_loop:
    mov dl, BYTE [rdi]
	cmp dl, BYTE [rsi + rax]
	je _is
	cmp BYTE [rsi + rax], 0
	je _not
	add rax, 1
	jmp _loop
_is:
	mov rax, 1
	ret
_not:
	mov rax, 0
	ret
