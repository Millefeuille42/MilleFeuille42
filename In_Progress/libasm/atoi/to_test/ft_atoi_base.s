section .text
    global ft_atoi_base

ft_atoi_base:
	mov dl, 0
	jmp _str_ft_strlen

_str_ft_strlen:
	xor rcx, rcx
_str_loop:
	cmp rdi, 0
	je _error
	cmp BYTE [rdi + rcx], 0
	je _str_check
	add rcx, 1
	jmp _len_loop

_base_ft_strlen:
	xor rdx, rdx
_base_loop:
	cmp rsi, 0
	je _error
	cmp BYTE [rsi + rdx], 0
	je _base_check
	cmp BYTE [rsi + rdx], 9
	je _error
	cmp BYTE [rsi + rdx], 10
	je _error
	cmp BYTE [rsi + rdx], 11
	je _error
	cmp BYTE [rsi + rdx], 12
	je _error
	cmp BYTE [rsi + rdx], 13
	je _error
	cmp BYTE [rsi + rdx], 20
	je _error
	cmp BYTE [rsi + rdx], 43
	je _error
	cmp BYTE [rsi + rdx], 45
	je _error

	add rdx, 1
	jmp _len_loop

_str_check:
	cmp rcx, 0
	je _error
	sub rcx, 1
	jmp _base_ft_strlen
_base_check:
	cmp rdx, 0
	je _error

_skip_wp:
	xor rax, rax
_skip_loop:
	cmp BYTE [rsi + rax], 9
	jne _sign_check
	cmp BYTE [rsi + rax], 10
	jne _sign_check
	cmp BYTE [rsi + rax], 11
	jne _sign_check
	cmp BYTE [rsi + rax], 12
	jne _sign_check
	cmp BYTE [rsi + rax], 13
	jne _sign_check
	cmp BYTE [rsi + rax], 20
	jne _sign_check
	add rax, 1
	jmp _skip_loop

_sign_check:
	cmp BYTE [rsi + rax], 43
	jne _nbr
	je _pos
	jmp _check_neg
_pos:
	mov dl, 0
_sign_neg:
	cmp BYTE [rsi + rax], 45
	jne _nbr
	je _neg
	jmp _sign_next
_neg:
	mov dl, 1
_sign_next:
	add rax, 1
	jmp _sign_check

_nbr:
	mov r8d, rax
	xor rax, rax
_is_in_base:
	xor r9d, r9d
	mov bl, BYTE [rdi + r8d]
   	cmp bl, BYTE [rsi + r9d]
	je _base_to_dec
    	cmp BYTE [rdi + r8d], 0
    	je _end
    	cmp BYTE [rsi + r9d], 0
    	je _error
    	add r9d, 1
    	jmp _is_in_base

_base_to_dec:
	sub rcx, r8d
	push r8d
	push rsi
	xor r8d, r8d
	xor rsi, rsi
_power:
	cmp r8d, rcx
	jg _pow_end
	push r8d
	xor r8d, r8d
_pow_multiply:
	cmp r8d, rdx
	jg _pm_end
	add rsi, rdx
	add r8d, 1
	jmp _pow_multiply
_pm_end:
	pop r8d
	add r8d, 1
	jmp _power
_pow_end:
	xor r8d, r8d
_multiply_loop:
	cmp r8d, rsi
	jg _btd_end
	add rax, r9d
	add r8d, 1
	jmp _multiply_loop
_btd_end:
	pop rsi
	pop r8d
	add rcx, r8d
	jmp _is_in_base

_end:
	ret

_error:
	xor rax, rax
	ret
