global		_ft_strcpy

section		.text
_ft_strcpy:
			mov			rax, rdi
			mov			rcx, 0

while:
			mov			dl, byte[rsi + rcx] ; dl = *(str1 + i)
			mov			byte[rdi + rcx], dl	; *(str2 + i) = dl
			cmp			dl, 0				; is dl == 0 -> return
			jz			return
			inc			rcx					; i++
			jmp			while

return:
			ret
