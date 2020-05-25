section .text
	global ft_atoi_base
	extern ft_strlen
	extern ft_is_space
	extern ft_c_inset

ft_atoi_base:
	cmp rdi, 0
	je _error
	cmp BYTE [rsi + 1], 0
	je _error
	cmp rsi, 0
	je _error
	cmp BYTE [rsi + 0], 0
	je _error
	cmp BYTE [rsi + 1], 0
	je _error

_check_base:
	push rdi
	mov rdi, rsi
	pop rsi
	xor rcx, rcx
_check_base_loop:
	cmp BYTE [rdi + rcx], 0
	je _skip_ws
	add rdi, rcx
	call ft_is_space
	cmp rax, 0
	jne _error
	sub rdi, rcx
	cmp BYTE [rdi + rcx], 43
	je _error
	cmp BYTE [rdi + rcx], 45
	je _error
	add rcx, 1
	jmp _check_base_loop

_skip_ws:
	push rdi
	mov rdi, rsi
	pop rsi
	push rcx
	xor rcx, rcx
_skip_ws_loop:
	cmp BYTE [rdi + rcx], 0
	je _error
	add rdi, rcx
	call ft_is_space
	cmp rax, 0
    jne _check_sign
    sub rdi, rcx
    add rcx, 1
    jmp _skip_ws_loop

_check_sign:
	cmp BYTE [rdi + rcx], 43
	je _pos
	jmp _check_neg
_pos:
	mov rdx, 0
_check_neg:
	cmp BYTE [rdi + rcx], 45
	je _pos
	jne _iter_base
	add rcx, 1
	jmp _check_sign
_neg:
	mov rdx, 1

_iter_base:
	add rdi, rcx
	pop rcx
	push rdx
	push rcx
	xor rax, rax
_iter_base_re:
	xor rcx, rcx
_iter_base_loop:
	cmp BYTE [rsi + rcx], 0
	je _end
	cmp BYTe
	jne _end
_base_to_dec:
	;ret = ret + i * ft_p(base_len, pos)
	cmp BYTE [rdi + rcx],

	sub rdi, rcx
	add rcx, 1
	jmp _iter_base_loop
