global		_ft_strdup
extern		_ft_strlen
extern 		_malloc
extern		_ft_strcpy

section		.text
_ft_strdup:							; str = rdi
			call		_ft_strlen	; rax = ft_strlen(str)
			inc			rax			; rax + 1 for '\0'
			push		rdi			; save rdi 
			mov			rdi, rax	; rdi = rax
			call		_malloc		; rax = malloc(rdi) = new_str
			pop			rdi			; restore rdi
			cmp			rax, 0		; is malloc return 0 -> error
			jz			error
			mov			rsi, rdi	; rsi = rdi = str
			mov			rdi, rax	; rdi = rax = new_str
			call		_ft_strcpy	; ft_strcpy(new_str, str) -> return(rax = new_str)
			ret

error:
			ret
