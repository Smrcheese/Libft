/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:36 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/12 00:06:12 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	menudisplay(char *input, int *page, int *start)
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
	char	*bonus[] = 
	{"ft_lstnew", "ft_lstadd_front", "ft_lstsize", "ft_lstlast",
		"ft_lstadd_back", "ft_lstdelone", "ft_lstclear", "ft_lstiter",
		"ft_lstmap"};
	int		intedinput;
	int		i;
	int		j;
	int		invflag;

	i = 1;
	j = 10;
	if ((strcmp(input, "next") == 0) && (*page < 4))
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
	printf("\033[0;32m                Welcome to the Libft Tester!\n");
	printf("\033[0;33m                     Made by sezequie\n");
	printf("\033[0;32m              Please select a function to test\033[0;37m:\n");
	printf("\033[0;32m                          Page \033[0;37m%d:\n", *page);
	while (i < 10 && j < 34)
	{
		printf("%d - \033[0;32m%s\033[0;37m\n", i, functions[j]);
		if (j == 33)
			printf("next page to see bonus!..\n");
		j++;
		i++;
	}
	if (*page == 4)
		printf("\033[0;34m                          Bonus!!\n\033[0;37m");
	while (*page == 4 && bonus[i])
	{
		printf("%d - \033[0;32m%s\033[0;37m\n", i, bonus[i]);
		i++;
	}
	if (*page < 4)
		printf("\nnext - Next page\n");
	if (*page > 1)
		printf("prev - Previous page\n");
	printf("exit - Exit program\n");
	if (invflag == 1 && *start == 0)
		printf("\033[0;31mInvalid input or end/start of program!\033[0;37m\n\n");
	*start = 0;
	invflag = 0;
	return (intedinput);
}

int	ft_atoi_tester(void)
{
	printf("\natoi it works!\n\n");
	return (1);
}

int	ft_bzero_tester(void)
{
	printf("\nbzero it works!\n\n");
	return (1);
}

int	ft_calloc_tester(void)
{
	printf("\ncalloc it works!\n\n");
	return (1);
}

int	ft_isalnum_tester(void)
{
	printf("\nisalnum it works!\n\n");
	return (1);
}

int	ft_isalpha_tester(void)
{
	printf("\nisalpha it works!");
	return (1);
}

int	main(void)
{
	char	*input;
	int		choice;
	int		page;
	int		start;

	start = 1;
	page = 1;
	while (1)
	{
		system("clear");
		choice = menudisplay(input, &page, &start);
		if (page == 1)
		{
			if (choice == 1)
				ft_atoi_tester();
			else if (choice == 2)
				ft_bzero_tester();
			else if (choice == 3)
				ft_calloc_tester();
			else if (choice == 4)
				ft_isalnum_tester();
			else if (choice == 5)
				ft_isalpha_tester();
		}
		printf("\033[0;32m_>\033[0;37m");
		scanf("%s", input);
	}
	return (0);
}
