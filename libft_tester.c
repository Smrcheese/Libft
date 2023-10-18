/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:36 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/15 19:52:49 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

char custom_map(unsigned int index, char c)
{
	// This example function appends 'A' to every character in the input string
	return c + 1;
}

//-------------------------------------------1-------------------------------------------------

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
	// Test 2: Non-zero-length allocation
	void *ptr2 = calloc(5, sizeof(int));
	void *ft_ptr2 = ft_calloc(5, sizeof(int));
	if (memcmp(ptr2, ft_ptr2, 5 * sizeof(int)) == 0)
	{
		printf("\033[0;32m✓ ft_calloc_tester: Test passed\n");
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_calloc_tester: Test failed\n");
		return 0;
	}
	free(ptr2);
	free(ft_ptr2);
}

int	ft_isalnum_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Non-alphanumeric character (should return false)
	int char2 = '@';
	int result2 = ft_isalnum(char2);
	int expected2 = isalnum(char2);
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_isalnum_tester: Test passed\n");
		tests_passed++;
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_isalnum_tester: Test failed\n");
		tests_failed++;
		return 0;
	}
}

int	ft_isalpha_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Non-alphabetic character (should return false)
	int char2 = '5';
	int result2 = ft_isalpha(char2);
	int expected2 = isalpha(char2);
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_isalpha_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_isalpha_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 2: Symbol character (should return false)
	int char3 = '@';
	int result3 = ft_isalpha(char3);
	int expected3 = isalpha(char3);
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_isalpha_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_isalpha_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_isalpha_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_isalpha_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_isascii_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: ASCII characters (0-127)
	for (int c = 0; c <= 127; c++)
	{
		int result = ft_isascii(c);
		int expected = isascii(c);
		if (result == expected)
		{
			printf("\033[0;32m✓ ft_isascii_tester: Test 1.%d passed\n", c);
			tests_passed++;
		}
		else
		{
			printf("\033[0;31m✗ ft_isascii_tester: Test 1.%d failed\n", c);
			tests_failed++;
		}
	}

	// Test 2: Non-ASCII characters
	int non_ascii[] = {128, 255, 256, 1000, -1};
	for (int i = 0; non_ascii[i] != -1; i++)
	{
		int result = ft_isascii(non_ascii[i]);
		int expected = isascii(non_ascii[i]);
		if (result == expected)
		{
			printf("\033[0;32m✓ ft_isascii_tester: Test 2.%d passed\n", non_ascii[i]);
			tests_passed++;
		}
		else
		{
			printf("\033[0;31m✗ ft_isascii_tester: Test 2.%d failed\n", non_ascii[i]);
			tests_failed++;
		}
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_isascii_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_isascii_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_isdigit_tester(void)
{
    int tests_passed = 0;
    int tests_failed = 0;

    // Test 1: Alphabetic character (should return false)
    int char2 = 'A';
    int result2 = ft_isdigit(char2);
    int expected2 = isdigit(char2);
    if (result2 == expected2)
    {
        printf("\033[0;32m✓ ft_isdigit_tester: Test 1 passed\n");
        tests_passed++;
    }
    else
    {
        printf("\033[0;31m✗ ft_isdigit_tester: Test 1 failed\n");
        tests_failed++;
    }

    // Test 2: Symbol character (should return false)
    int char3 = '@';
    int result3 = ft_isdigit(char3);
    int expected3 = isdigit(char3);
    if (result3 == expected3)
    {
        printf("\033[0;32m✓ ft_isdigit_tester: Test 2 passed\n");
        tests_passed++;
    }
    else
    {
        printf("\033[0;31m✗ ft_isdigit_tester: Test 2 failed\n");
        tests_failed++;
    }

    // Print summary
    if (tests_failed == 0)
    {
        printf("\033[0;32m✓ ft_isdigit_tester: All tests passed (%d tests)\n", tests_passed);
        return 1;
    }
    else
    {
        printf("\033[0;31m✗ ft_isdigit_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
        return 0;
    }
}

int	ft_isprint_tester(void)
{
    // Test 2: Control character (should return false)
    int char2 = '\n';
    int result2 = ft_isprint(char2);
    int expected2 = isprint(char2);
    if (result2 == expected2)
    {
        printf("\033[0;32m✓ ft_isprint_tester: Test passed\n");
		return 1;
    }
    else
    {
        printf("\033[0;31m✗ ft_isprint_tester: Test failed\n");
		return 0;
    }
}

int	ft_itoa_tester(void)
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

int	ft_memcmp_tester(void)
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

int	ft_memcpy_tester(void)
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
		printf("\033[0;32m✓ ft_memcpy_tester: Test 4 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: Test 4 failed\n");
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
		printf("\033[0;32m✓ ft_memcpy_tester: Test 5 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memcpy_tester: Test 5 failed\n");
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

int	ft_memmove_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic move
	char src1[] = "123456789";
	char dst1[] = "abcdefghi";
	char *expected1 = memmove(dst1, src1, 5);
	char *result1 = ft_memmove(dst1, src1, 5);
	if (memcmp(result1, expected1, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memmove_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memmove_tester: Test 1 failed\n");
		printf("  expected: %s\n", expected1);
		printf("  got:      %s\n", result1);
		tests_failed++;
	}

	// Test 2: Overlapping move
	char src2[] = "123456789";
	char dst2[] = "abcdefghi";
	char *expected2 = memmove(dst2 + 2, dst2, 5);
	char *result2 = ft_memmove(dst2 + 2, dst2, 5);
	if (memcmp(result2, expected2, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memmove_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memmove_tester: Test 2 failed\n");
		printf("  expected: %s\n", expected2);
		printf("  got:      %s\n", result2);
		tests_failed++;
	}

	// Test 3: Move to same location
	char src3[] = "123456789";
	char dst3[] = "abcdefghi";
	char *expected3 = memmove(dst3, src3, 0);
	char *result3 = ft_memmove(dst3, src3, 0);
	if (memcmp(result3, expected3, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memmove_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memmove_tester: Test 3 failed\n");
		printf("  expected: %s\n", expected3);
		printf("  got:      %s\n", result3);
		tests_failed++;
	}

	// Test 4: Move from same location
	char src4[] = "123456789";
	char dst4[] = "abcdefghi";
	char *expected4 = memmove(dst4, dst4, 5);
	char *result4 = ft_memmove(dst4, dst4, 5);
	if (memcmp(result4, expected4, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memmove_tester: Test 4 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memmove_tester: Test 4 failed\n");
		printf("  expected: %s\n", expected4);
		printf("  got:      %s\n", result4);
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_memmove_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_memmove_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int	ft_memset_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic set
	char str1[] = "123456789";
	char *expected1 = memset(str1, 'a', 5);
	char *result1 = ft_memset(str1, 'a', 5);
	if (memcmp(result1, expected1, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memset_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memset_tester: Test 1 failed\n");
		printf("  expected: %s\n", expected1);
		printf("  got:      %s\n", result1);
		tests_failed++;
	}

	// Test 2: Set to zero
	char str2[] = "123456789";
	char *expected2 = memset(str2, 0, 5);
	char *result2 = ft_memset(str2, 0, 5);
	if (memcmp(result2, expected2, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memset_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memset_tester: Test 2 failed\n");
		printf("  expected: %s\n", expected2);
		printf("  got:      %s\n", result2);
		tests_failed++;
	}

	// Test 3: Set entire string
	char str3[] = "123456789";
	char *expected3 = memset(str3, 'a', 9);
	char *result3 = ft_memset(str3, 'a', 9);
	if (memcmp(result3, expected3, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memset_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memset_tester: Test 3 failed\n");
		printf("  expected: %s\n", expected3);
		printf("  got:      %s\n", result3);
		tests_failed++;
	}

	// Test 4: Set zero bytes
	char str4[] = "123456789";
	char *expected4 = memset(str4, 'a', 0);
	char *result4 = ft_memset(str4, 'a', 0);
	if (memcmp(result4, expected4, 10) == 0)
	{
		printf("\033[0;32m✓ ft_memset_tester: Test 4 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_memset_tester: Test 4 failed\n");
		printf("  expected: %s\n", expected4);
		printf("  got:      %s\n", result4);
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_memset_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_memset_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int	ft_putchar_fd_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic output
	int fd1[2];
	pipe(fd1);
	printf("\n");
	putchar('a');
	fflush(stdout);
	ft_putchar_fd('a', fd1[1]);
	close(fd1[1]);
	char buf1[2];
	read(fd1[0], buf1, 1);
	close(fd1[0]);
	printf(" \033[0;33m<-- char printed\n\n");
	if (buf1[0] == 'a')
	{
		printf("\033[0;32m✓ ft_putchar_fd_tester: Test 1 passed\n");
		tests_passed++;
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_putchar_fd_tester: Test 1 failed\n");
		printf("  expected: a\n");
		tests_failed++;
		return (0);
	}
}

int	ft_putendl_fd_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic output
	int fd1[2];
	pipe(fd1);
	printf("\n");
	puts("hello i'm a string!");
	fflush(stdout);
	ft_putendl_fd("hello i'm a string!", fd1[1]);
	close(fd1[1]);
	char buf1[20];
	read(fd1[0], buf1, 19);
	close(fd1[0]);
	buf1[19] = '\0';
	printf(" \033[0;33mI should be under the string!\n\n");
	if (strcmp(buf1, "hello i'm a string!") == 0)
	{
		printf("\033[0;32m✓ ft_putendl_fd_tester: Test 1 passed\n");
		tests_passed++;
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_putendl_fd_tester: Test 1 failed\n");
		printf("  expected: hello i'm a string!\\n\n");
		printf("  got:      %s", buf1);
		tests_failed++;
		return (0);
	}
}

int	ft_putnbr_fd_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic output
	int fd1[2];
	pipe(fd1);
	printf("\n");
	putchar('1');
	fflush(stdout);
	ft_putnbr_fd(1, fd1[1]);
	close(fd1[1]);
	char buf1[2];
	read(fd1[0], buf1, 1);
	close(fd1[0]);
	printf(" \033[0;33m <-- number printed\n\n");
	if (buf1[0] == '1')
	{
		printf("\033[0;32m✓ ft_putnbr_fd_tester: Test 1 passed\n");
		tests_passed++;
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_putnbr_fd_tester: Test 1 failed\n");
		printf("  expected: 1\n");
		printf("  got:      %c\n", buf1[0]);
		tests_failed++;
		return (0);
	}
}

int	ft_putstr_fd_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic output
	int fd1[2];
	pipe(fd1);
	printf("\n");
	puts("hello");
	fflush(stdout);
	ft_putstr_fd("hello", fd1[1]);
	close(fd1[1]);
	char buf1[6];
	read(fd1[0], buf1, 5);
	close(fd1[0]);
	buf1[5] = '\0';
	printf(" \033[0;33mis hello printed above?\n\n");
	if (strcmp(buf1, "hello") == 0)
	{
		printf("\033[0;32m✓ ft_putstr_fd_tester: Test 1 passed\n");
		tests_passed++;
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_putstr_fd_tester: Test 1 failed\n");
		printf("  expected: hello\n");
		printf("  got:      %s\n", buf1);
		tests_failed++;
		return (0);
	}
}

//-------------------------------------------3-------------------------------------------------

int	ft_split_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic split
	char *str1 = "This is a test";
	char **expected1 = (char *[]){"This", "is", "a", "test", NULL};
	char **result1 = ft_split(str1, ' ');
	if (strcmp(result1[0], expected1[0]) == 0 && strcmp(result1[1], expected1[1]) == 0 &&
		strcmp(result1[2], expected1[2]) == 0 && strcmp(result1[3], expected1[3]) == 0 &&
		result1[4] == expected1[4])
	{
		printf("\033[0;32m✓ ft_split_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_split_tester: Test 1 failed\n");
		printf("  expected: %s %s %s %s (null)\n", expected1[0], expected1[1], expected1[2], expected1[3]);
		printf("  got:      %s %s %s %s (%s)\n", result1[0], result1[1], result1[2], result1[3], result1[4]);
		tests_failed++;
	}
	for (int i = 0; result1[i] != NULL; i++)
		free(result1[i]);
	free(result1);

	// Test 2: Empty string
	char *str2 = "";
	char **expected2 = (char *[]){NULL};
	char **result2 = ft_split(str2, ' ');
	if (result2[0] == expected2[0])
	{
		printf("\033[0;32m✓ ft_split_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_split_tester: Test 2 failed\n");
		printf("  expected: (null)\n");
		printf("  got:      %s\n", result2[0]);
		tests_failed++;
	}
	for (int i = 0; result2[i] != NULL; i++)
		free(result2[i]);
	free(result2);

	// Test 3: Single character delimiter
	char *str3 = "This,is,a,test";
	char **expected3 = (char *[]){"This", "is", "a", "test", NULL};
	char **result3 = ft_split(str3, ',');
	if (strcmp(result3[0], expected3[0]) == 0 && strcmp(result3[1], expected3[1]) == 0 &&
		strcmp(result3[2], expected3[2]) == 0 && strcmp(result3[3], expected3[3]) == 0 &&
		result3[4] == expected3[4])
	{
		printf("\033[0;32m✓ ft_split_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_split_tester: Test 3 failed\n");
		printf("  expected: %s %s %s %s (null)\n", expected3[0], expected3[1], expected3[2], expected3[3]);
		printf("  got:      %s %s %s %s (%s)\n", result3[0], result3[1], result3[2], result3[3], result3[4]);
		tests_failed++;
	}
	for (int i = 0; result3[i] != NULL; i++)
		free(result3[i]);
	free(result3);

	// Test 4: Multiple character delimiter
	char *str4 = "This---is---a---test";
	char **expected4 = (char *[]){"This", "is", "a", "test", NULL};
	char **result4 = ft_split(str4, '-');
	if (strcmp(result4[0], expected4[0]) == 0 && strcmp(result4[1], expected4[1]) == 0 &&
		strcmp(result4[2], expected4[2]) == 0 && strcmp(result4[3], expected4[3]) == 0 &&
		result4[4] == expected4[4])
	{
		printf("\033[0;32m✓ ft_split_tester: Test 4 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_split_tester: Test 4 failed\n");
		printf("  expected: %s %s %s %s (null)\n", expected4[0], expected4[1], expected4[2], expected4[3]);
		printf("  got:      %s %s %s %s (%s)\n", result4[0], result4[1], result4[2], result4[3], result4[4]);
		tests_failed++;
	}
	for (int i = 0; result4[i] != NULL; i++)
		free(result4[i]);
	free(result4);

	// Test 5: Delimiter not found
	char *str5 = "This is a test";
	char **expected5 = (char *[]){"This is a test", NULL};
	char **result5 = ft_split(str5, '-');
	if (strcmp(result5[0], expected5[0]) == 0 && result5[1] == expected5[1])
	{
		printf("\033[0;32m✓ ft_split_tester: Test 5 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_split_tester: Test 5 failed\n");
		printf("  expected: %s (null)\n", expected5[0]);
		printf("  got:      %s (%s)\n", result5[0], result5[1]);
		tests_failed++;
	}
	for (int i = 0; result5[i] != NULL; i++)
		free(result5[i]);
	free(result5);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_split_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_split_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int	ft_strchr_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic search
	char *str1 = "This is a test";
	char *result1 = ft_strchr(str1, 's');
	ptrdiff_t expected1 = result1 - str1;
	if (result1 != NULL && expected1 == 3)
	{
		printf("\033[0;32m✓ ft_strchr_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strchr_tester: Test 1 failed\n");
		printf("  expected: %td\n", expected1);
		printf("  got:      %td\n", result1 != NULL ? result1 - str1 : -1);
		tests_failed++;
	}

	// Test 2: Null character
	char *str3 = "This is a test";
	char *result3 = ft_strchr(str3, '\0');
	ptrdiff_t expected3 = result3 - str3;
	if (result3 != NULL && expected3 == 14)
	{
		printf("\033[0;32m✓ ft_strchr_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strchr_tester: Test 2 failed\n");
		printf("  expected: %td\n", expected3);
		printf("  got:      %td\n", result3 != NULL ? result3 - str3 : -1);
		tests_failed++;
	}

	// Test 3: Search for first character
	char *str5 = "This is a test";
	char *result5 = ft_strchr(str5, 'T');
	ptrdiff_t expected5 = result5 - str5;
	if (result5 != NULL && expected5 == 0)
	{
		printf("\033[0;32m✓ ft_strchr_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strchr_tester: Test 3 failed\n");
		printf("  expected: %td\n", expected5);
		printf("  got:      %td\n", result5 != NULL ? result5 - str5 : -1);
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strchr_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strchr_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_strdup_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic copy
	char *str1 = "This is a test";
	char *expected1 = strdup(str1);
	char *result1 = ft_strdup(str1);
	if (strcmp(result1, expected1) == 0)
	{
		printf("\033[0;32m✓ ft_strdup_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strdup_tester: Test 1 failed\n");
		printf("  expected: %s\n", expected1);
		printf("  got:      %s\n", result1);
		tests_failed++;
	}
	free(expected1);
	free(result1);

	// Test 2: Empty string
	char *str2 = "";
	char *expected2 = strdup(str2);
	char *result2 = ft_strdup(str2);
	if (strcmp(result2, expected2) == 0)
	{
		printf("\033[0;32m✓ ft_strdup_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strdup_tester: Test 2 failed\n");
		printf("  expected: %s\n", expected2);
		printf("  got:      %s\n", result2);
		tests_failed++;
	}
	free(expected2);
	free(result2);

	// Test 3: Large string
	char *str4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";
	char *expected4 = strdup(str4);
	char *result4 = ft_strdup(str4);
	if (strcmp(result4, expected4) == 0)
	{
		printf("\033[0;32m✓ ft_strdup_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strdup_tester: Test 3 failed\n");
		printf("  expected: %s\n", expected4);
		printf("  got:      %s\n", result4);
		tests_failed++;
	}
	free(expected4);
	free(result4);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strdup_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strdup_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_strjoin_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic join
	char *str1a = "This is a";
	char *str1b = " test";
	char *expected1 = "This is a test";
	char *result1 = ft_strjoin(str1a, str1b);
	if (strcmp(result1, expected1) == 0)
	{
		printf("\033[0;32m✓ ft_strjoin_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strjoin_tester: Test 1 failed\n");
		printf("  expected: %s\n", expected1);
		printf("  got:      %s\n", result1);
		tests_failed++;
	}
	free(result1);

	// Test 2: Empty string
	char *str2a = "";
	char *str2b = "";
	char *expected2 = "";
	char *result2 = ft_strjoin(str2a, str2b);
	if (strcmp(result2, expected2) == 0)
	{
		printf("\033[0;32m✓ ft_strjoin_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strjoin_tester: Test 2 failed\n");
		printf("  expected: %s\n", expected2);
		printf("  got:      %s\n", result2);
		tests_failed++;
	}
	free(result2);

	// Test 3: Large strings
	char *str4a = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.";
	char *str4b = " Fusce fermentum odio eu feugiat.";
	char *expected4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Fusce fermentum odio eu feugiat.";
	char *result4 = ft_strjoin(str4a, str4b);
	if (strcmp(result4, expected4) == 0)
	{
		printf("\033[0;32m✓ ft_strjoin_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strjoin_tester: Test 3 failed\n");
		printf("  expected: %s\n", expected4);
		printf("  got:      %s\n", result4);
		tests_failed++;
	}
	free(result4);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strjoin_tester: All tests passed (%d tests)\n", tests_passed);
		return (1);
	}
	else
	{
		printf("\033[0;31m✗ ft_strjoin_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return (0);
	}
}

int	ft_strlcat_tester(void)
{
	// Test 1: Basic concatenation
	char dest1[20] = "Hello, ";
	const char source1[] = "world";
	size_t result1 = ft_strlcat(dest1, source1, sizeof(dest1));
	char dest1_copy[20];
	strcpy(dest1_copy, dest1);
	size_t expected1 = strlen(dest1_copy);
	strncat(dest1_copy, source1, sizeof(dest1_copy) - expected1 - 1);
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_strlcat_tester: Test passed\n");
	}
	else
	{
		printf("\033[0;31m✗ ft_strlcat_tester: Test failed\n");
		printf("  expected: %lu\n", expected1);
		printf("  got:      %lu\n", result1);
	}
}

int	ft_strlcpy_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic copying
	char dest1[20] = "Hello, ";
	const char source1[] = "world";
	size_t result1 = ft_strlcpy(dest1, source1, sizeof(dest1));
	char dest1_copy[20];
	strncpy(dest1_copy, source1, sizeof(dest1_copy));
	if (result1 == strlen(source1) && strcmp(dest1, source1) == 0)
	{
		printf("\033[0;32m✓ ft_strlcpy_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlcpy_tester: Test 1 failed\n");
		printf("  expected: %lu\n", (size_t)strlen(source1));
		printf("  got:      %lu\n", result1);
		tests_failed++;
	}

	// Test 2: Truncation (dstsize is smaller than the source string)
	char dest2[8] = "123";
	const char source2[] = "abcdef";
	size_t result2 = ft_strlcpy(dest2, source2, sizeof(dest2));
	char dest2_copy[8];
	strncpy(dest2_copy, source2, sizeof(dest2_copy));
	if (result2 == strlen(source2) && strcmp(dest2, source2) == 0)
	{
		printf("\033[0;32m✓ ft_strlcpy_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlcpy_tester: Test 2 failed\n");
		printf("  expected: %lu\n", (size_t)strlen(source2));
		printf("  got:      %lu\n", result2);
		tests_failed++;
	}

	// Test 3: Exact fit (dstsize is equal to the length of source)
	char dest3[5] = "abcd";
	const char source3[] = "efgh";
	size_t result3 = ft_strlcpy(dest3, source3, sizeof(dest3));
	char dest3_copy[5];
	strncpy(dest3_copy, source3, sizeof(dest3_copy));
	if (result3 == strlen(source3) && strcmp(dest3, source3) == 0)
	{
		printf("\033[0;32m✓ ft_strlcpy_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlcpy_tester: Test 3 failed\n");
		printf("  expected: %lu\n", (size_t)strlen(source3));
		printf("  got:      %lu\n", result3);
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strlcpy_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlcpy_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_strlen_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic string length
	const char str1[] = "Hello, world!";
	size_t result1 = ft_strlen(str1);
	size_t expected1 = strlen(str1);
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_strlen_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlen_tester: Test 1 failed\n");
		printf("  expected: %lu\n", expected1);
		printf("  got:      %lu\n", result1);
		tests_failed++;
	}

	// Test 2: Empty string
	const char str2[] = "";
	size_t result2 = ft_strlen(str2);
	size_t expected2 = strlen(str2);
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_strlen_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlen_tester: Test 2 failed\n");
		printf("  expected: %lu\n", expected2);
		printf("  got:      %lu\n", result2);
		tests_failed++;
	}

	// Test 3: String with spaces
	const char str3[] = "   ";
	size_t result3 = ft_strlen(str3);
	size_t expected3 = strlen(str3);
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_strlen_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlen_tester: Test 3 failed\n");
		printf("  expected: %lu\n", expected3);
		printf("  got:      %lu\n", result3);
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strlen_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strlen_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_strmapi_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic string mapping
	const char str1[] = "Hello, world!";
	char result1[15];
	char expected1[] = "Ifmmp-!xpsme\"";
	char *output1 = ft_strmapi(str1, custom_map);
	if (strcmp(output1, expected1) == 0)
	{
		printf("\033[0;32m✓ ft_strmapi_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strmapi_tester: Test 1 failed\n");
		printf("  expected: %s\n", expected1);
		printf("  got:      %s\n", output1);
		tests_failed++;
	}
	free(output1);

	// Test 2: Empty string
	const char str2[] = "";
	char *output2 = ft_strmapi(str2, custom_map);
	if (output2 != NULL && strcmp(output2, "") == 0)
	{
		printf("\033[0;32m✓ ft_strmapi_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strmapi_tester: Test 2 failed\n");
		tests_failed++;
	}
	free(output2);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strmapi_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strmapi_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_strncmp_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic string comparison (equal)
	const char str1a[] = "Hello, world!";
	char str1b[] = "Hello, world!";
	int result1 = ft_strncmp(str1a, str1b, 14);
	int expected1 = ft_strncmp(str1a, str1b, 14);
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_strncmp_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strncmp_tester: Test 1 failed\n");
		printf("  expected: %d\n", expected1);
		printf("  got:      %d\n", result1);
		tests_failed++;
	}

	// Test 2: Basic string comparison (different)
	const char str2a[] = "Hello, world!";
	char str2b[] = "Goodbye, world!";
	int result2 = ft_strncmp(str2a, str2b, 14);
	int expected2 = ft_strncmp(str2a, str2b, 14);
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_strncmp_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strncmp_tester: Test 2 failed\n");
		printf("  expected: %d\n", expected2);
		printf("  got:      %d\n", result2);
		tests_failed++;
	}

	// Test 3: Compare only a portion of the strings
	const char str3a[] = "Hello, world!";
	char str3b[] = "Goodbye, world!";
	int result3 = ft_strncmp(str3a, str3b, 5);
	int expected3 = ft_strncmp(str3a, str3b, 5);
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_strncmp_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strncmp_tester: Test 3 failed\n");
		printf("  expected: %d\n", expected3);
		printf("  got:      %d\n", result3);
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strncmp_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strncmp_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

//-------------------------------------------4-------------------------------------------------

int	ft_strnstr_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic substring search
	const char haystack1[] = "Hello, world!";
	const char needle1[] = "world";
	char *result1 = ft_strnstr(haystack1, needle1, 14);
	char *expected1 = strstr(haystack1, needle1);
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_strnstr_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strnstr_tester: Test 1 failed\n");
		tests_failed++;
	}

	// Test 2: Substring not found
	const char haystack2[] = "Hello, world!";
	const char needle2[] = "universe";
	char *result2 = ft_strnstr(haystack2, needle2, 14);
	char *expected2 = strstr(haystack2, needle2);
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_strnstr_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strnstr_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 3: Empty haystack
	const char haystack3[] = "";
	const char needle3[] = "world";
	char *result3 = ft_strnstr(haystack3, needle3, 0);
	char *expected3 = strstr(haystack3, needle3);
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_strnstr_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strnstr_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strnstr_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strnstr_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_strrchr_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic search
	const char str1[] = "This is a test";
	char *result1 = ft_strrchr(str1, 's');
	char *expected1 = strrchr(str1, 's');
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_strrchr_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strrchr_tester: Test 1 failed\n");
		tests_failed++;
	}

	// Test 2: Null character
	const char str2[] = "This is a test";
	char *result2 = ft_strrchr(str2, '\0');
	char *expected2 = strrchr(str2, '\0');
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_strrchr_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strrchr_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 3: Search for first character
	const char str3[] = "This is a test";
	char *result3 = ft_strrchr(str3, 'T');
	char *expected3 = strrchr(str3, 'T');
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_strrchr_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strrchr_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strrchr_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strrchr_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_strtrim_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic trimming
	const char s1[] = "  Hello, world!   ";
	const char set1[] = " ";
	char *result1 = ft_strtrim(s1, set1);
	const char expected1[] = "Hello, world!";
	if (strcmp(result1, expected1) == 0)
	{
		printf("\033[0;32m✓ ft_strtrim_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strtrim_tester: Test 1 failed\n");
		tests_failed++;
	}
	free(result1);

	// Test 2: No trimming needed
	const char s2[] = "Hello, world!";
	const char set2[] = "x";
	char *result2 = ft_strtrim(s2, set2);
	const char expected2[] = "Hello, world!";
	if (strcmp(result2, expected2) == 0)
	{
		printf("\033[0;32m✓ ft_strtrim_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_strtrim_tester: Test 2 failed\n");
		tests_failed++;
	}
	free(result2);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_strtrim_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_strtrim_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_substr_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Basic substring extraction
	const char str1[] = "This is a test";
	unsigned int start1 = 5;
	size_t len1 = 2;
	char *result1 = ft_substr(str1, start1, len1);
	const char expected1[] = "is";
	if (strcmp(result1, expected1) == 0)
	{
		printf("\033[0;32m✓ ft_substr_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_substr_tester: Test 1 failed\n");
		tests_failed++;
	}
	free(result1);

	// Test 2: Substring starting at the beginning
	const char str2[] = "This is a test";
	unsigned int start2 = 0;
	size_t len2 = 4;
	char *result2 = ft_substr(str2, start2, len2);
	const char expected2[] = "This";
	if (strcmp(result2, expected2) == 0)
	{
		printf("\033[0;32m✓ ft_substr_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_substr_tester: Test 2 failed\n");
		tests_failed++;
	}
	free(result2);

	// Test 3: Substring with length exceeding the string length
	const char str3[] = "This is a test";
	unsigned int start3 = 10;
	size_t len3 = 15;
	char *result3 = ft_substr(str3, start3, len3);
	const char expected3[] = "test";
	if (strcmp(result3, expected3) == 0)
	{
		printf("\033[0;32m✓ ft_substr_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_substr_tester: Test 3 failed\n");
		tests_failed++;
	}
	free(result3);

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_substr_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_substr_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_tolower_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Uppercase letter 'A'
	int result1 = ft_tolower('A');
	int expected1 = tolower('A');
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_tolower_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_tolower_tester: Test 1 failed\n");
		tests_failed++;
	}

	// Test 2: Lowercase letter 'b'
	int result2 = ft_tolower('b');
	int expected2 = tolower('b');
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_tolower_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_tolower_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 3: Non-alphabetic character '5'
	int result3 = ft_tolower('5');
	int expected3 = tolower('5');
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_tolower_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_tolower_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_tolower_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_tolower_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

int	ft_toupper_tester(void)
{
	int tests_passed = 0;
	int tests_failed = 0;

	// Test 1: Uppercase letter 'A'
	int result1 = ft_toupper('A');
	int expected1 = toupper('A');
	if (result1 == expected1)
	{
		printf("\033[0;32m✓ ft_toupper_tester: Test 1 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_toupper_tester: Test 1 failed\n");
		tests_failed++;
	}

	// Test 2: Lowercase letter 'b'
	int result2 = ft_toupper('b');
	int expected2 = toupper('b');
	if (result2 == expected2)
	{
		printf("\033[0;32m✓ ft_toupper_tester: Test 2 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_toupper_tester: Test 2 failed\n");
		tests_failed++;
	}

	// Test 3: Non-alphabetic character '5'
	int result3 = ft_toupper('5');
	int expected3 = toupper('5');
	if (result3 == expected3)
	{
		printf("\033[0;32m✓ ft_toupper_tester: Test 3 passed\n");
		tests_passed++;
	}
	else
	{
		printf("\033[0;31m✗ ft_toupper_tester: Test 3 failed\n");
		tests_failed++;
	}

	// Print summary
	if (tests_failed == 0)
	{
		printf("\033[0;32m✓ ft_toupper_tester: All tests passed (%d tests)\n", tests_passed);
		return 1;
	}
	else
	{
		printf("\033[0;31m✗ ft_toupper_tester: %d/%d tests failed\n", tests_failed, tests_passed + tests_failed);
		return 0;
	}
}

//----------------------------------------MAIN-------------------------------------------------

int	menudisplay(char *input, int *page, int *start)
{
	char	*functions[] = 
	{"ft_atoi", "ft_bzero", "ft_calloc", "ft_isalnum",
	"ft_isalpha", "ft_isascii", "ft_isdigit", "ft_isprint",
	"ft_itoa", "ft_memchr", "ft_memcmp", "ft_memcpy",
	"ft_memmove", "ft_memset", "ft_putchar_fd", "ft_putendl_fd",
	"ft_putnbr_fd", "ft_putstr_fd", "ft_split", "ft_strchr", "ft_strdup",
	"ft_strjoin", "ft_strlcat", "ft_strlcpy", "ft_strlen", "ft_strmapi",
	"ft_strncmp", "ft_strnstr", "ft_strrchr", "ft_strtrim", "ft_substr",
	"ft_tolower", "ft_toupper"};
	char	*bonus[] = 
	{"ft_lstnew", "ft_lstadd_front", "ft_lstsize", "ft_lstlast",
		"ft_lstadd_back", "ft_lstdelone", "ft_lstclear", "ft_lstiter",
		"ft_lstmap"};
	int		bonuslen = 9;
	int		functionlen = 33;
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
	else if ((strcmp(input, "all") == 0))
		return(*page = 10);
	else if (strcmp(input, "exit") == 0)
		return(*page = 0);
	else if (input[0] >= '0' && input[0] <= '9')
		intedinput = atoi(input);
	else
		invflag = 1;
	if (*page == 2)
		j = 9;
	if (*page == 3)
		j = 18;
	if (*page == 4)
		j = 27;
	printf("\033[0;32m                Welcome to the Libft Tester!\n");
	printf("\033[0;33m                     Made by sezequie\n");
	printf("\033[0;32m              Please select a function to test\033[0;37m:\n");
	printf("\033[0;32m                          Page \033[0;37m%d:\n", *page);
	printf("all - \033[0;32mTest ALL libft\033[0;37m\n");
	while (*page < 5 && i < 10 && j < functionlen)
	{
		printf("%d - \033[0;32m%s\033[0;37m\n", i, functions[j]);
		if (j == 33)
			printf("next page to see bonus!..\n");
		j++;
		i++;
	}
	if (*page == 5)
		printf("\033[0;34m                          Bonus!!\n\033[0;37m");
	while (*page == 5 && j < bonuslen)
	{
		printf("%d - \033[0;32m%s\033[0;37m\n", j+1, bonus[j]);
		if (j == 8)
			printf("\n");
		j++;
	}
	if (*page < 5)
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
	int		allflg;

	start = 1;
	page = 1;
	input = malloc(sizeof(char) * 10);
	printf("\033[0;34m     ....LAUNCHING....\033[0;37m\n");
	system("norminette src/*.c -R CheckForbiddenSourceHeader");
	printf("\033[0;34mBewary of normi!\n");
	sleep(2);
	while (1)
	{
		system("clear");
		choice = menudisplay(input, &page, &start);
		if (page == 0)
			break;
		if (page == 10)
			allflg = 1;
		if (page == 1 || allflg == 1)
		{
			if (choice == 1 || allflg == 1)
				ft_atoi_tester();
			if (choice == 2 || allflg == 1)
				ft_bzero_tester();
			if (choice == 3 || allflg == 1)
				ft_calloc_tester();
			if (choice == 4 || allflg == 1)
				ft_isalnum_tester();
			if (choice == 5 || allflg == 1)
				ft_isalpha_tester();
			if (choice == 6 || allflg == 1)
				ft_isascii_tester();
			if (choice == 7 || allflg == 1)
				ft_isdigit_tester();
			if (choice == 8 || allflg == 1)
				ft_isprint_tester();
			if (choice == 9 || allflg == 1)
				ft_itoa_tester();
		}
		if (page == 2 || allflg == 1)
		{
			if (choice == 1 || allflg == 1)
				ft_memchr_tester();
			if (choice == 2 || allflg == 1)
				ft_memcmp_tester();
			if (choice == 3 || allflg == 1)
				ft_memcpy_tester();
			if (choice == 4 || allflg == 1)
				ft_memmove_tester();
			if (choice == 5 || allflg == 1)
				ft_memset_tester();
			if (choice == 6 || allflg == 1)
				ft_putchar_fd_tester();
			if (choice == 7 || allflg == 1)
				ft_putendl_fd_tester();
			if (choice == 8 || allflg == 1)
				ft_putnbr_fd_tester();
			if (choice == 9 || allflg == 1)
				ft_putstr_fd_tester();
		}
		if (page == 3 || allflg == 1)
		{
			if (choice == 1 || allflg == 1)
				ft_split_tester();
			if (choice == 2 || allflg == 1)
				ft_strchr_tester();
			if (choice == 3 || allflg == 1)
				ft_strdup_tester();
			if (choice == 4 || allflg == 1)
				ft_strjoin_tester();
			if (choice == 5 || allflg == 1)
				ft_strlcat_tester();
			if (choice == 6 || allflg == 1)
				ft_strlcpy_tester();
			if (choice == 7 || allflg == 1)
				ft_strlen_tester();
			if (choice == 8 || allflg == 1)
				ft_strmapi_tester();
			if (choice == 9 || allflg == 1)
				ft_strncmp_tester();
		}
		if (page == 4 || allflg == 1)
		{
			if (choice == 1 || allflg == 1)
				ft_strnstr_tester();
			if (choice == 2 || allflg == 1)
				ft_strrchr_tester();
			if (choice == 3 || allflg == 1)
				ft_strtrim_tester();
			if (choice == 4 || allflg == 1)
				ft_substr_tester();
			if (choice == 5 || allflg == 1)
				ft_tolower_tester();
			if (choice == 6 || allflg == 1)
				ft_toupper_tester();
		}
		if (allflg == 1)
		{
			printf("\n\033[0;37minput anything to continue\n");
			start = 1;
			allflg = 0;
			page = 1;
		}
		printf("\033[0;32m_>\033[0;37m");
		scanf("%s", input);
	}
	free(input);
	return (0);
}
