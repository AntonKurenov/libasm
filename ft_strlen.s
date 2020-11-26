global		_ft_strlen

section		.text
_ft_strlen:
			xor		rax, rax

while:
			cmp		byte[rdi + rax], 0
			jz		return
			inc		rax
			jmp		while
	
return:
			ret
