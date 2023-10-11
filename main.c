/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:36 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/11 15:23:20 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libft.h"

int *menudisplay(char *input, int *page)
{
	char	**functions;
	int		*choiseindex;
	int		intedinput;
	int		i;
	int		j;
	
	i = 0;
	j = 10;
	functions = {"ft_atoi", "ft_bzero", "ft_calloc", "ft_isalnum",
	"ft_isalpha", "ft_isascii", "ft_isdigit", "ft_isprint",
	"ft_itoa", "ft_memccpy", "ft_memchr", "ft_memcmp", "ft_memcpy",
	"ft_memmove", "ft_memset", "ft_putchar_fd", "ft_putendl_fd",
	"ft_putnbr_fd", "ft_putstr_fd", "ft_split", "ft_strchr", "ft_strdup",
	"ft_strjoin", "ft_strlcat", "ft_strlcpy", "ft_strlen", "ft_strmapi",
	"ft_strncmp", "ft_strnstr", "ft_strrchr", "ft_strtrim", "ft_substr",
	"ft_tolower", "ft_toupper"};
	if (input == "next")
		page++;
	else if (input == "prev")
		page--;
	else if (input == "exit")
		exit(0);
	else if (input => "0" && input <= "9")
		intedinput = atoi(input);
	else
		printf("\033[0;31mInvalid input, please try again.\n");

	if (page == 0)
		j = 0;
	else
		j *= page;
	printf("\033[0;32mWelcome to the Libft Tester!\n");
	printf("\033[0;32mPlease select a function to test:\n");
	while (i < 10)
	{
		printf("%d - %s\n", j, functions[j]);
		j++;
		i++;
	}
	printf("next - Next page\n");
	printf("prev - Previous page\n");
	printf("exit - Exit program\n");
	choiseindex = [page,]
	return (choiseindex);
}

int main()
{
	char	*input;
	int		*choice;
	int		*page;
	
	page = 0;
	while (1)
	{
		menudisplay(input, page);
		input = scanf("\033[0;32m>%s", input);
	}
	return (0);
}
