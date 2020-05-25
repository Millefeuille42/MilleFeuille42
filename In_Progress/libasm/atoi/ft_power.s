section .text
	global ft_power
	extern ft_multiply

ft_power:
	cmp rdi, 0
	je _zero
	cmp rsi, 0
	je _one
	cmp rsi, 2147483647
    jg _zero
   	cmp rsi, 1
	je _nb
	mov rax, rdi
	mov rcx, rsi
_loop:
	cmp rcx, 2
	jl _end
	mov rsi, rax
	push rcx
	call ft_multiply
	pop rcx
	sub rcx, 1
	jmp _loop
_end:
	ret
_zero:
	mov rax, 0
	ret
_one:
	mov rax, 1
	ret
_nb:
	mov rax, rdi
	ret
