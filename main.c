/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:36 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/10 17:27:24 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libft.h"

int *menudisplay(char *input, int *page)
{
	char	**functions;
	i = 0;
	functions = "ft_atoi\nft_bzero\nft_calloc\nft_isalnum\n
	ft_isalpha\nft_isascii\nft_isdigit\nft_isprint\n
	ft_itoa\nft_memccpy\nft_memchr\nft_memcmp\n
	ft_memcpy\nft_memmove\nft_memset\nft_putchar_fd\n
	ft_putendl_fd\nft_putnbr_fd\nft_putstr_fd\nft_split\n
	ft_strchr\nft_strdup\nft_strjoin\nft_strlcat\nft_strlcpy\n
	ft_strlen\nft_strmapi\nft_strncmp\nft_strnstr\nft_strrchr\n
	ft_strtrim\nft_substr\nft_tolower\nft_toupper\n";
	while (i < 10 && functions)
	{
		if (functions != '\n')
			printf("%c\n", functions[0]);
		if (i == 9)
			printf("next - see next page\n");
			printf("exit - exit program\n");
			scanf("%s", input);
		if (input == "next" && page < 3)
			page++;
		if (input == "exit")
			exit(0);
		if (page == 0)
		{
			if (input == 0)
		}
			
		functions++;
	}
}

void test_ft_atoi()
{
	/*create a string and print it, then print the result of ft_atoi, if the
	result is the same as the atoi function, print "OK" in green, otherwise print "KO" in red.
	do more than 3 test*/
	
	char *str = "123456789";
	int result = ft_atoi(str);
	int result2 = atoi(str);
	printf("ft_atoi: %d\n", result);
	printf("atoi: %d\n", result2);
	if (result == result2)
		printf("\033[0;32mOK\n");
	else
		printf("\033[0;31mKO\n");
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
