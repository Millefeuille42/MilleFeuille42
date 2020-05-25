section .text
	global ft_multiply

ft_multiply:
	xor rcx, rcx
	xor rax, rax
_loop:
	cmp rcx, rsi
	je _end
	add rax, rdi
	add rcx, 1
	jmp _loop
_end:
	ret
