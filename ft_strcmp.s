global		_ft_strcmp						; ft_strcmp(str1, str2)

section		.text
_ft_strcmp:
			mov			rax, 0
			mov			rcx, 0 ; i = 0

while:										; str1 = rdi, str2 = rsi
			mov			dl, byte[rsi + rcx] ; dl = *(str2 + i)
			mov			bl, byte[rdi + rcx] ; bl = *(str1 + i)
			cmp			dl, 0				; is dl == '\0' -> return
			jz			return
			cmp			bl, 0				; is bl == '\0' -> return
			jz			return
			cmp			dl, bl				; is dl == '\0' -> return
			jne			return
			inc			rcx					; i++
			jmp			while

return:
			movzx		rax, bl				; rax = bl
			movzx		rbx, dl				; rbx = dl
			sub			rax, rbx			; *(str1 + i) - *(str2 + i)
			ret
