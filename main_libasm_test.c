/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libasm_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:13:23 by elovegoo          #+#    #+#             */
/*   Updated: 2020/11/13 11:56:02 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void clear_buffer(char *buff, int size)
{
	int i = 0;
	while (i < size)
		buff[i++] = 0;
}

void	check_read()
{
	int		fd = open("Makefile", O_RDONLY);
	char	buff[101];
	int		ret = 1;

	printf("\n========== FT_READ =============\n");
	ret = read(fd, buff, 100);
	buff[ret] = '\0';
	printf("original read: ret = %d\n\n|%s|\n", ret, buff);
	close(fd);
	clear_buffer(buff, 101);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, buff, 100);
	buff[ret] = '\0';
	printf("\nft_read    : ret = %d\n\n|%s|\n", ret, buff);
	close(fd);
	clear_buffer(buff, 101);

	ret = read(20, buff, 100);
	buff[ret] = '\0';
	printf("original read: ret = %d\n|%s|\n", ret, buff);
	printf("original errno: %d\n", errno);
	printf("%s\n", strerror(errno));
	clear_buffer(buff, 101);
	ret = read(20, buff, 100);
	buff[ret] = '\0';
	printf("ft_read    : ret = %d\n|%s|\n", ret, buff);
	printf("libasm	 errno: %d\n", errno);
	printf("%s\n", strerror(errno));
	clear_buffer(buff, 101);
	printf("================================\n");

}

void	check_strcmp(char *long_str)
{
	char	*str1;
	char	*str2;

	printf("\n========== FT_STRCMP ===========\n");
	printf("\noriginal strcmp %d\n", strcmp("", ""));
	printf("my ft_strcmp    %d\n\n", ft_strcmp("", ""));
	printf("original strcmp %d\n", strcmp("123456", ""));
	printf("my ft_strcmp    %d\n\n", ft_strcmp("123456", ""));
	printf("original strcmp %d\n", strcmp("", "654321"));
 	printf("my ft_strcmp    %d\n\n", ft_strcmp("", "654321"));
	printf("original strcmp %d\n", strcmp("To be, or not to be",  "To be, or not to be"));
	printf("my ft_strcmp    %d\n\n", ft_strcmp("To be, or not to be",  "To be, or not to be"));
	
	str1 = ft_strdup("12345");
	str2 = ft_strdup("Hello");
	printf("original strcmp %d\n", strcmp(str1, str2));
 	printf("my ft_strcmp    %d\n", ft_strcmp(str1, str2));
	printf("================================\n");
}

void	check_write()
{
	char	str[] = "Hello World!";
	int 	fd;
	int 	ft_fd;

	printf("\n========== FT_WRITE ============\n");
	fd = open("write.txt", O_WRONLY | O_CREAT,  S_IREAD | S_IWRITE);
	ft_fd = open("ft_write.txt", O_WRONLY | O_CREAT,  S_IREAD | S_IWRITE);
	write(1, str, strlen(str));
	printf(" - stdout org\n");
	ft_write(1, str, strlen(str));
	printf(" - stdout my\n");
	write(fd, str, strlen(str));
	ft_write(ft_fd, str, strlen(str));
	printf(">>>> write file!\n");
	printf("error orig: %zd, %s\n", write(21, str, strlen(str)), strerror(errno));
	printf("errno orig = %d\n", errno);
	printf("error libasm : %zd, %s\n", ft_write(21, str, strlen(str)), strerror(errno));
	printf("errno libasm = %d\n", errno);
	close(fd);
	close(ft_fd);
	close (fd);
	printf("================================\n");
}

void	check_strdup(char *long_str)
{
	char *str1;
	char *str2;

	printf("\n========== FT_STRDUP ===========\n");
	str1 = strdup("");
	str2 = ft_strdup("");
	printf("\noriginal strdup |%s|\n", str1);
	printf("my ft_strdup    |%s|\n", str2);
	str1 = strdup("123456");
	str2 = ft_strdup("123456");
	printf("\noriginal strdup |%s|\n", str1);
	printf("my ft_strdup    |%s|\n", str2);
	str1 = strdup("To be, or not to be, that is the question");
	str2 = ft_strdup("To be, or not to be, that is the question");
	printf("\noriginal strdup |%s|\n", str1);
	printf("my ft_strdup    |%s|\n\n", str2);

	str1 = strdup(long_str);
	str2 = ft_strdup(long_str);
	printf("original strdup %zu\n", ft_strlen(str1));
	printf("my ft_strdup    %zu\n", strlen(str2));
	printf("================================\n");
}

void	check_strcpy(char *long_str)
{
	char	str[10];
	char	str3[600];

	printf("\n========== FT_STRCPY ===========\n");
	printf("\noriginal strcpy |%s|\n", strcpy(str, ""));
	printf("my ft_strcpy    |%s|\n", ft_strcpy(str, ""));

	printf("\noriginal strcpy |%s|\n", strcpy(str, "123456"));
	printf("my ft_strcpy    |%s|\n", ft_strcpy(str, "123456"));
	ft_strcpy(str3, long_str);
	printf("res of compare long_str and str3 = %d\n", ft_strcmp(long_str, str3));
	printf("================================\n");
}

void	check_strlen(char *long_str)
{
	printf("========== FT_STRLEN ===========\n");
	printf("\noriginal strlen %zu\n", strlen(""));
	printf("my ft_strlen    %zu\n\n", ft_strlen(""));

	printf("original strlen %zu\n", strlen("123456"));
	printf("my ft_strlen    %zu\n\n", ft_strlen("123456"));

	printf("original strlen %zu\n", strlen("To be, or not to be, that is the question"));
	printf("my ft_strlen    %zu\n\n", ft_strlen("To be, or not to be, that is the question"));

	printf("original strlen %zu\n", ft_strlen(long_str));
	printf("my ft_strlen    %zu\n", strlen(long_str));
	printf("================================\n");
}

int		main(void)
{
	char long_str[] = "An assembly (or assembler) language, often abbreviated \
			asm, is a low-level programming language for a computer, or other \
			programmable device, in which there is a very strong (but often \
			not one-to-one) correspondence between the language and the \
			architecture’s machine code instructions. Each assembly language \
			is specific to a particular computer architecture. In contrast, \
			most high-level programming languages are generally portable across\
			multiple architectures but require interpreting or compiling. \
			Assembly language may also be called symbolic machine code.";

	check_strlen(long_str);
	check_strdup(long_str);
	check_read();
	check_write();
	check_strcmp(long_str);
	check_strcpy(long_str);
	return(0);
}
