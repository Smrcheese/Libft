/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:36 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/12 22:05:43 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int	ft_atoi_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic positive integer
	char *str1 = "12345";
	int expected1 = atoi(str1);
	int result1 = ft_atoi(str1);
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_atoi_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_atoi_tester: Test 1 failed\n");
		printf("  expected: %d\n", expected1);
		printf("  got:      %d\n", result1);
		tests_failed++;
	}

	// Test 2: Basic negative integer
	char *str2 = "-12345";
	int expected2 = atoi(str2);
	int result2 = ft_atoi(str2);
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_atoi_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_atoi_tester: Test 2 failed\n");
		printf("  expected: %d\n", expected2);
		printf("  got:      %d\n", result2);
		tests_failed++;
	}

	// Test 3: Leading whitespace
	char *str3 = "   12345";
	int expected3 = atoi(str3);
	int result3 = ft_atoi(str3);
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_atoi_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_atoi_tester: Test 3 failed\n");
		printf("  expected: %d\n", expected3);
		printf("  got:      %d\n", result3);
		tests_failed++;
	}

	// Test 4: Trailing whitespace
	char *str4 = "12345   ";
	int expected4 = atoi(str4);
	int result4 = ft_atoi(str4);
	if (result4 == expected4)
	{
		printf("\033[0;32m✓ ft_atoi_tester: Test 4 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_atoi_tester: Test 4 failed\n");
		printf("  expected: %d\n", expected4);
		printf("  got:      %d\n", result4);
		tests_failed++;
	}

	// Test 5: Invalid input
	char *str5 = "123abc";
	int expected5 = atoi(str5);
	int result5 = ft_atoi(str5);
	if (result5 == expected5)
	{
		printf("\033[0;32m✓ ft_atoi_tester: Test 5 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_atoi_tester: Test 5 failed\n");
		printf("  expected: %d\n", expected5);
		printf("  got:      %d\n", result5);
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_atoi_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_atoi_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int	ft_bzero_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Zero-length buffer
	char buf1[10] = "12345";
	bzero(buf1, (0));
	ft_bzero(buf1, 0);
	if (memcmp(buf1, "12345", 6) == 0)
	{
		printf("\033[0;32m✓ ft_bzero_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_bzero_tester: Test 1 failed\n");
		printf("  expected: \"12345\"\n");
		printf("  got:      \"%s\"\n", buf1);
		tests_failed++;
	}

	// Test 2: Large buffer
	char buf3[1000];
	memset(buf3, 'A', 1000);
	bzero(buf3, 1000);
	ft_bzero(buf3, 1000);
	if (memcmp(buf3, "\0\0\0\0\0\0\0\0\0\0", 10) == 0)
	{
		printf("\033[0;32m✓ ft_bzero_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_bzero_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_bzero_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_bzero_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int	ft_calloc_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Zero-length allocation
	void *ptr1 = calloc(0, 1);
	void *ft_ptr1 = ft_calloc(0, 1);
	if (memcmp(ptr1, ft_ptr1, 1) == 0)
	{
		printf("\033[0;32m✓ ft_calloc_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_calloc_tester: Test 1 failed\n");
		tests_failed++;
	}
	free(ptr1);
	free(ft_ptr1);

	// Test 2: Non-zero-length allocation
	void *ptr2 = calloc(5, sizeof(int));
	void *ft_ptr2 = ft_calloc(5, sizeof(int));
	if (memcmp(ptr2, ft_ptr2, 5 * sizeof(int)) == 0)
	{
		printf("\033[0;32m✓ ft_calloc_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_calloc_tester: Test 2 failed\n");
		tests_failed++;
	}
	free(ptr2);
	free(ft_ptr2);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_calloc_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_calloc_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int	ft_isalnum_tester(void)
{
	printf("alo isalnum");
}

int	ft_isalpha_tester(void)
{
	printf("alo isalpha");
}

int	ft_isascii_tester(void)
{
	printf("alo isascii");
}

int	ft_isdigit_tester(void)
{
	printf("alo isdigit");
}

int	ft_isprint_tester(void)
{
	printf("alo isprint");
}

int ft_itoa_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Positive number
	int n1 = 12345;
	char *expected1 = "12345";
	char *result1 = ft_itoa(n1);
	if (strcmp(result1, expected1) == 0)
	{
		printf("\033[0;32m✓ ft_itoa_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_itoa_tester: Test 1 failed\n");
		printf("  expected: \"%s\"\n", expected1);
		printf("  got:      \"%s\"\n", result1);
		tests_failed++;
	}
	free(result1);

	// Test 2: Negative number
	int n2 = -12345;
	char *expected2 = "-12345";
	char *result2 = ft_itoa(n2);
	if (strcmp(result2, expected2) == 0)
	{
		printf("\033[0;32m✓ ft_itoa_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_itoa_tester: Test 2 failed\n");
		printf("  expected: \"%s\"\n", expected2);
		printf("  got:      \"%s\"\n", result2);
		tests_failed++;
	}
	free(result2);

	// Test 3: Zero
	int n3 = 0;
	char *expected3 = "0";
	char *result3 = ft_itoa(n3);
	if (strcmp(result3, expected3) == 0)
	{
		printf("\033[0;32m✓ ft_itoa_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_itoa_tester: Test 3 failed\n");
		printf("  expected: \"%s\"\n", expected3);
		printf("  got:      \"%s\"\n", result3);
		tests_failed++;
	}
	free(result3);

	// Test 4: INT_MIN
	int n4 = -2147483648;
	char *expected4 = "-2147483648";
	char *result4 = ft_itoa(n4);
	if (strcmp(result4, expected4) == 0)
	{
		printf("\033[0;32m✓ ft_itoa_tester: Test 4 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_itoa_tester: Test 4 failed\n");
		printf("  expected: \"%s\"\n", expected4);
		printf("  got:      \"%s\"\n", result4);
		tests_failed++;
	}
	free(result4);

	// Test 5: INT_MAX
	int n5 = 2147483647;
	char *expected5 = "2147483647";
	char *result5 = ft_itoa(n5);
	if (strcmp(result5, expected5) == 0)
	{
		printf("\033[0;32m✓ ft_itoa_tester: Test 5 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_itoa_tester: Test 5 failed\n");
		printf("  expected: \"%s\"\n", expected5);
		printf("  got:      \"%s\"\n", result5);
		tests_failed++;
	}
	free(result5);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_itoa_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_itoa_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

//-------------------------------------------2-------------------------------------------------

int	ft_memchr_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Search for character in string
	char str1[] = "Hello, world!";
	char *result1 = ft_memchr(str1, 'w', strlen(str1));
	if (result1 != NULL && result1 - str1 == 7)
	{
		printf("\033[0;32m✓ ft_memchr_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memchr_tester: Test 1 failed\n");
		tests_failed++;
	}

	// Test 2: Search for character not in string
	char str2[] = "Hello, world!";
	char *result2 = ft_memchr(str2, 'z', strlen(str2));
	if (result2 == NULL)
	{
		printf("\033[0;32m✓ ft_memchr_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memchr_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 3: Search for character in memory block
	char buf3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char *result3 = ft_memchr(buf3, 5, sizeof(buf3));
	if (result3 != NULL && result3 - buf3 == 5)
	{
		printf("\033[0;32m✓ ft_memchr_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memchr_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Test 4: Search for character not in memory block
	char buf4[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char *result4 = ft_memchr(buf4, 10, sizeof(buf4));
	if (result4 == NULL)
	{
		printf("\033[0;32m✓ ft_memchr_tester: Test 4 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memchr_tester: Test 4 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_memchr_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_memchr_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int ft_memcmp_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Same strings
	char *s1 = "Hello, world!";
	char *s2 = "Hello, world!";
	if (ft_memcmp(s1, s2, strlen(s1) + 1) == memcmp(s1, s2, strlen(s1) + 1))
	{
		printf("\033[0;32m✓ ft_memcmp_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcmp_tester: Test 1 failed\n");
		tests_failed++;
	}

	// Test 2: Different strings
	char *s3 = "Hello, world";
	char *s4 = "Hello, there!";
	if (ft_memcmp(s1, s3, strlen(s1) + 1) == memcmp(s1, s3, strlen(s1) + 1))
	{
		printf("\033[0;32m✓ ft_memcmp_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcmp_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 3: Different length
	if (ft_memcmp(s1, s4, strlen(s1) + 1) == memcmp(s1, s4, strlen(s1) + 1))
	{
		printf("\033[0;32m✓ ft_memcmp_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcmp_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_memcmp_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_memcmp_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int ft_memcpy_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Copy string to buffer
	char buf1[100];
	char *str1 = "Hello, world!";
	char *result1 = ft_memcpy(buf1, str1, strlen(str1) + 1);
	if (memcmp(buf1, str1, strlen(str1) + 1) == 0 && result1 == buf1)
	{
		printf("\033[0;32m✓ ft_memcpy_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: Test 1 failed\n");
		tests_failed++;
	}

	// Test 2: Copy buffer to buffer
	char buf2[100];
	char buf3[100];
	memset(buf2, 'A', 100);
	memset(buf3, 'A', 100);
	char *result2 = ft_memcpy(buf2, buf3, 100);
	if (memcmp(buf2, buf3, 100) == 0 && result2 == buf2)
	{
		printf("\033[0;32m✓ ft_memcpy_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 3: Copy buffer to string
	char buf4[100];
	char *str2 = "Hello, world!";
	memset(buf4, 'A', 100);
	char *result3 = ft_memcpy(buf4, str2, strlen(str2) + 1);
	if (memcmp(buf4, str2, strlen(str2) + 1) == 0 && result3 == buf4)
	{
		printf("\033[0;32m✓ ft_memcpy_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: Test 3 failed\n");
		tests_failed++;
	}
	
	// Test 4: Copy buffer to buffer with length 0
	char buf6[100];
	char buf7[100];
	memset(buf6, 'A', 100);
	memset(buf7, 'A', 100);
	char *result5 = ft_memcpy(buf6, buf7, 0);
	if (memcmp(buf6, buf7, 100) == 0 && result5 == buf6)
	{
		printf("\033[0;32m✓ ft_memcpy_tester: Test 5 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: Test 5 failed\n");
		tests_failed++;
	}
	
	// Test 5: Copy buffer to buffer with length 1
	char buf9[100];
	char buf10[100];
	memset(buf9, 'A', 100);
	memset(buf10, 'A', 100);
	char *result7 = ft_memcpy(buf9, buf10, 1);
	if (memcmp(buf9, buf10, 100) == 0 && result7 == buf9)
	{
		printf("\033[0;32m✓ ft_memcpy_tester: Test 7 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: Test 7 failed\n");
		tests_failed++;
	}
	
	// print summary
	
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_memcpy_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

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
	j = 0;
	if ((strcmp(input, "next") == 0) && (*page < 5))
		(*page)++;
	else if ((strcmp(input, "prev") == 0) && (*page > 1))
		(*page)--;
	else if (strcmp(input, "exit") == 0)
		return(*page = 0);
	else if (input[0] >= '1' && input[0] <= '9')
		intedinput = atoi(input);
	else
		invflag = 1;
	if (*page == 2)
		j = 10;
	if (*page == 3)
		j = 20;
	if (*page == 4)
		j = 30;
	printf("\033[0;32m                Welcome to the Libft Tester!\n");
	printf("\033[0;33m                     Made by sezequie\n");
	printf("\033[0;32m              Please select a function to test\033[0;37m:\n");
	printf("\033[0;32m                          Page \033[0;37m%d:\n", *page);
	while (*page < 5 && i < 10 && j < 34)
	{
		printf("%d - \033[0;32m%s\033[0;37m\n", i, functions[j]);
		if (j == 33)
			printf("next page to see bonus!..\n");
		j++;
		i++;
	}
	if (*page == 5)
		printf("\033[0;34m                          Bonus!!\n\033[0;37m");
	i = 0;
	while (*page == 5 && i < 9)
	{
		printf("%d - \033[0;32m%s\033[0;37m\n", i+1, bonus[i]);
		i++;
	}
	if (*page < 4)
		printf("\nnext - Next page\n");
	if (*page > 1)
		printf("prev - Previous page\n");
	printf("exit - Exit program\n");
	if (invflag == 1 && *start == 0)
		printf("\033[0;31mInvalid input or end/start of program!\033[0;37m\n");
	*start = 0;
	invflag = 0;
	return (intedinput);
}

int	main()
{
	char	*input;
	int		choice;
	int		page;
	int		start;

	start = 1;
	page = 1;
	input = malloc(sizeof(char) * 10);
	while (1)
	{
		system("clear");
		choice = menudisplay(input, &page, &start);
		if (page == 0)
			break;
		if (page == 1)
		{
			if (choice == 1)
				ft_atoi_tester();
			if (choice == 2)
				ft_bzero_tester();
			if (choice == 3)
				ft_calloc_tester();
			if (choice == 4)
				ft_isalnum_tester();
			if (choice == 5)
				ft_isalpha_tester();
			if (choice == 6)
				ft_isascii_tester();
			if (choice == 7)
				ft_isdigit_tester();
			if (choice == 8)
				ft_isprint_tester();
			if (choice == 9)
				ft_itoa_tester();
		}
		if (page == 2)
		{
			if (choice == 1)
				ft_memchr_tester();
			if (choice == 2)
				ft_memcmp_tester();
			if (choice == 3)
				ft_memcpy_tester();
		}
		printf("\033[0;32m_>\033[0;37m");
		scanf("%s", input);
	}
	free(input);
	return (0);
}
