/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:36 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/11 17:34:18 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menudisplay(char *input, int *page)
{
	char	*functions[] = 
	{"ft_atoi", "ft_bzero", "ft_calloc", "ft_isalnum",
	"ft_isalpha", "ft_isascii", "ft_isdigit", "ft_isprint",
	"ft_itoa", "ft_memccpy", "ft_memchr", "ft_memcmp", "ft_memcpy",
	"ft_memmove", "ft_memset", "ft_putchar_fd", "ft_putendl_fd",
	"ft_putnbr_fd", "ft_putstr_fd", "ft_split", "ft_strchr", "ft_strdup",
	"ft_strjoin", "ft_strlcat", "ft_strlcpy", "ft_strlen", "ft_strmapi",
	"ft_strncmp", "ft_strnstr", "ft_strrchr", "ft_strtrim", "ft_substr",
	"ft_tolower", "ft_toupper"};
	int		intedinput;
	int		i;
	int		j;
	int		invflag;
	
	i = 1;
	j = 10;
	if ((strcmp(input, "Starting") == 0))
		invflag = 0;
	else if ((strcmp(input, "next") == 0) && (*page < 3))
		(*page)++;
	else if ((strcmp(input, "prev") == 0) && (*page > 1))
		(*page)--;
	else if (strcmp(input, "exit") == 0)
		exit(0);
	else if (input[0] >= '0' && input[0] <= '9')
		intedinput = atoi(input);
	else
		invflag = 1;
	if (*page == 1)
		j = 0;
	else
		j *= *page;
	printf("\033[0;32m                          Page \033[0;37m%d:\n", *page);
	while (i < 10 && j < 34)
	{
		printf("%d - \033[0;32m%s\033[0;37m\n", i, functions[j]);
		j++;
		i++;
	}
	printf("\nnext - Next page\n");
	printf("prev - Previous page\n");
	printf("exit - Exit program\n\n");
	if (invflag == 1)
		printf("\033[0;31mSomething went wrong!!\nPerhaps invalid input or you're at the limit of the page!\033[0;37m\n\n");
	return (intedinput);
}

int ft_atoi_tester()
{
	printf("atoi it works!");
	return (1);
}

int ft_bzero_tester()
{
	printf("bzero it works!");
	return (1);
}

int main(void)
{
	char	*input;
	int		choice;
	int		page;
	
	page = 1;
	printf("\033[0;32m                Welcome to the Libft Tester!\n");
	printf("\033[0;32m              Please select a function to test\033[0;37m:\n");
	choice = menudisplay("Starting", &page);
	printf("\033[0;32m_>\033[0;37m");
	scanf("%s", input);
	printf("\n");
	while (1)
	{
		system("clear");
		choice = menudisplay(input, &page);
		printf("\nyour choice and current page is: %d, %d\n", choice, page);
		printf("\033[0;32m_>\033[0;37m");
		scanf("%s", input);
	}
	return (0);
}
