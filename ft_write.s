global		_ft_write

extern		___error

section		.text
_ft_write:
			push		rbx
			mov			rax, 0x2000004
			syscall
			jc			error
			pop			rbx
			ret

error:
			mov			rdx, rax
			call		___error
			mov			[rax], rdx
			mov			rax, -1
			pop			rbx
			ret
