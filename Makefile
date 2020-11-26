NAME = libasm

FUNC = ft_strlen.s \
	   ft_strcpy.s \
	   ft_strcmp.s \
	   ft_write.s \
	   ft_read.s \
	   ft_strdup.s 

OBJS = $(FUNC:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.s
	nasm -fmacho64 $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

