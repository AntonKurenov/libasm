global		_ft_read
extern		___error

section		.text
_ft_read:
			push		rbx
			mov			rax, 0x2000003	; read syscall
			syscall
			jc			error			; if error occur -> error
			pop			rbx
			ret

error:
			mov			rdx, rax		; rdx = rax
			call		___error
			mov			[rax], rdx		; *rax = rdx
			mov			rax, -1			; return rax = -1 if error
			pop			rbx
			ret
