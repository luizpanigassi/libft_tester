/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:00:00 by luinasci          #+#    #+#             */
/*   Updated: 2025/07/22 15:50:29 by luinasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <fcntl.h>

// Test counter and result tracking
static int test_count = 0;
static int test_passed = 0;

// Color codes for output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Test assertion macro
#define TEST_ASSERT(condition, test_name)               \
    do                                                  \
    {                                                   \
        test_count++;                                   \
        if (condition)                                  \
        {                                               \
            printf(GREEN "✓ " RESET "%s\n", test_name); \
            test_passed++;                              \
        }                                               \
        else                                            \
        {                                               \
            printf(RED "✗ " RESET "%s\n", test_name);   \
        }                                               \
    } while (0)

// Helper function to compare arrays
int arrays_equal(char **arr1, char **arr2)
{
    if (!arr1 && !arr2)
        return 1;
    if (!arr1 || !arr2)
        return 0;

    int i = 0;
    while (arr1[i] && arr2[i])
    {
        if (strcmp(arr1[i], arr2[i]) != 0)
            return 0;
        i++;
    }
    return arr1[i] == NULL && arr2[i] == NULL;
}

// Helper function to free string arrays
void free_array(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i]; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

// Helper function for list deletion
void del_content(void *content)
{
    free(content);
}

// Helper function for list mapping
void *duplicate_content(void *content)
{
    char *str = (char *)content;
    return strdup(str);
}

// Helper function for list iteration
void print_content(void *content)
{
    printf("%s ", (char *)content);
}

// Helper function for ft_strmapi
char test_strmapi_func(unsigned int i, char c)
{
    (void)i; // Suppress unused parameter warning
    return c + 1;
}

// Helper function for ft_striteri
void test_striteri_func(unsigned int i, char *c)
{
    (void)i; // Suppress unused parameter warning
    *c = *c + 1;
}

// =============================================================================
// CHARACTER CLASSIFICATION TESTS
// =============================================================================

void test_ft_isalpha(void)
{
    printf(BLUE "\n=== Testing ft_isalpha ===\n" RESET);

    TEST_ASSERT(ft_isalpha('a') != 0, "ft_isalpha('a') should return non-zero");
    TEST_ASSERT(ft_isalpha('Z') != 0, "ft_isalpha('Z') should return non-zero");
    TEST_ASSERT(ft_isalpha('m') != 0, "ft_isalpha('m') should return non-zero");
    TEST_ASSERT(ft_isalpha('1') == 0, "ft_isalpha('1') should return 0");
    TEST_ASSERT(ft_isalpha(' ') == 0, "ft_isalpha(' ') should return 0");
    TEST_ASSERT(ft_isalpha('@') == 0, "ft_isalpha('@') should return 0");
    TEST_ASSERT(ft_isalpha('\0') == 0, "ft_isalpha('\\0') should return 0");
}

void test_ft_isdigit(void)
{
    printf(BLUE "\n=== Testing ft_isdigit ===\n" RESET);

    TEST_ASSERT(ft_isdigit('0') != 0, "ft_isdigit('0') should return non-zero");
    TEST_ASSERT(ft_isdigit('9') != 0, "ft_isdigit('9') should return non-zero");
    TEST_ASSERT(ft_isdigit('5') != 0, "ft_isdigit('5') should return non-zero");
    TEST_ASSERT(ft_isdigit('a') == 0, "ft_isdigit('a') should return 0");
    TEST_ASSERT(ft_isdigit('Z') == 0, "ft_isdigit('Z') should return 0");
    TEST_ASSERT(ft_isdigit(' ') == 0, "ft_isdigit(' ') should return 0");
    TEST_ASSERT(ft_isdigit('\0') == 0, "ft_isdigit('\\0') should return 0");
}

void test_ft_isalnum(void)
{
    printf(BLUE "\n=== Testing ft_isalnum ===\n" RESET);

    TEST_ASSERT(ft_isalnum('a') != 0, "ft_isalnum('a') should return non-zero");
    TEST_ASSERT(ft_isalnum('Z') != 0, "ft_isalnum('Z') should return non-zero");
    TEST_ASSERT(ft_isalnum('5') != 0, "ft_isalnum('5') should return non-zero");
    TEST_ASSERT(ft_isalnum('0') != 0, "ft_isalnum('0') should return non-zero");
    TEST_ASSERT(ft_isalnum(' ') == 0, "ft_isalnum(' ') should return 0");
    TEST_ASSERT(ft_isalnum('@') == 0, "ft_isalnum('@') should return 0");
    TEST_ASSERT(ft_isalnum('\0') == 0, "ft_isalnum('\\0') should return 0");
}

void test_ft_isascii(void)
{
    printf(BLUE "\n=== Testing ft_isascii ===\n" RESET);

    TEST_ASSERT(ft_isascii(0) != 0, "ft_isascii(0) should return non-zero");
    TEST_ASSERT(ft_isascii(127) != 0, "ft_isascii(127) should return non-zero");
    TEST_ASSERT(ft_isascii('a') != 0, "ft_isascii('a') should return non-zero");
    TEST_ASSERT(ft_isascii(128) == 0, "ft_isascii(128) should return 0");
    TEST_ASSERT(ft_isascii(-1) == 0, "ft_isascii(-1) should return 0");
    TEST_ASSERT(ft_isascii(255) == 0, "ft_isascii(255) should return 0");
}

void test_ft_isprint(void)
{
    printf(BLUE "\n=== Testing ft_isprint ===\n" RESET);

    TEST_ASSERT(ft_isprint('a') != 0, "ft_isprint('a') should return non-zero");
    TEST_ASSERT(ft_isprint(' ') != 0, "ft_isprint(' ') should return non-zero");
    TEST_ASSERT(ft_isprint('~') != 0, "ft_isprint('~') should return non-zero");
    TEST_ASSERT(ft_isprint('\t') == 0, "ft_isprint('\\t') should return 0");
    TEST_ASSERT(ft_isprint('\n') == 0, "ft_isprint('\\n') should return 0");
    TEST_ASSERT(ft_isprint(31) == 0, "ft_isprint(31) should return 0");
    TEST_ASSERT(ft_isprint(127) == 0, "ft_isprint(127) should return 0");
}

void test_ft_toupper(void)
{
    printf(BLUE "\n=== Testing ft_toupper ===\n" RESET);

    TEST_ASSERT(ft_toupper('a') == 'A', "ft_toupper('a') should return 'A'");
    TEST_ASSERT(ft_toupper('z') == 'Z', "ft_toupper('z') should return 'Z'");
    TEST_ASSERT(ft_toupper('m') == 'M', "ft_toupper('m') should return 'M'");
    TEST_ASSERT(ft_toupper('A') == 'A', "ft_toupper('A') should return 'A'");
    TEST_ASSERT(ft_toupper('1') == '1', "ft_toupper('1') should return '1'");
    TEST_ASSERT(ft_toupper(' ') == ' ', "ft_toupper(' ') should return ' '");
}

void test_ft_tolower(void)
{
    printf(BLUE "\n=== Testing ft_tolower ===\n" RESET);

    TEST_ASSERT(ft_tolower('A') == 'a', "ft_tolower('A') should return 'a'");
    TEST_ASSERT(ft_tolower('Z') == 'z', "ft_tolower('Z') should return 'z'");
    TEST_ASSERT(ft_tolower('M') == 'm', "ft_tolower('M') should return 'm'");
    TEST_ASSERT(ft_tolower('a') == 'a', "ft_tolower('a') should return 'a'");
    TEST_ASSERT(ft_tolower('1') == '1', "ft_tolower('1') should return '1'");
    TEST_ASSERT(ft_tolower(' ') == ' ', "ft_tolower(' ') should return ' '");
}

// =============================================================================
// STRING FUNCTIONS TESTS
// =============================================================================

void test_ft_strlen(void)
{
    printf(BLUE "\n=== Testing ft_strlen ===\n" RESET);

    TEST_ASSERT(ft_strlen("") == 0, "ft_strlen(\"\") should return 0");
    TEST_ASSERT(ft_strlen("Hello") == 5, "ft_strlen(\"Hello\") should return 5");
    TEST_ASSERT(ft_strlen("42") == 2, "ft_strlen(\"42\") should return 2");
    TEST_ASSERT(ft_strlen("Hello, World!") == 13, "ft_strlen(\"Hello, World!\") should return 13");
}

void test_ft_strchr(void)
{
    printf(BLUE "\n=== Testing ft_strchr ===\n" RESET);

    char *str = "Hello, World!";
    TEST_ASSERT(ft_strchr(str, 'H') == str, "ft_strchr should find 'H' at beginning");
    TEST_ASSERT(ft_strchr(str, 'o') == str + 4, "ft_strchr should find first 'o'");
    TEST_ASSERT(ft_strchr(str, '!') == str + 12, "ft_strchr should find '!' at end");
    TEST_ASSERT(ft_strchr(str, 'x') == NULL, "ft_strchr should return NULL for missing char");
    TEST_ASSERT(ft_strchr(str, '\0') == str + 13, "ft_strchr should find null terminator");
}

void test_ft_strrchr(void)
{
    printf(BLUE "\n=== Testing ft_strrchr ===\n" RESET);

    char *str = "Hello, World!";
    TEST_ASSERT(ft_strrchr(str, 'H') == str, "ft_strrchr should find 'H'");
    TEST_ASSERT(ft_strrchr(str, 'o') == str + 8, "ft_strrchr should find last 'o'");
    TEST_ASSERT(ft_strrchr(str, '!') == str + 12, "ft_strrchr should find '!'");
    TEST_ASSERT(ft_strrchr(str, 'x') == NULL, "ft_strrchr should return NULL for missing char");
    TEST_ASSERT(ft_strrchr(str, '\0') == str + 13, "ft_strrchr should find null terminator");
}

void test_ft_strncmp(void)
{
    printf(BLUE "\n=== Testing ft_strncmp ===\n" RESET);

    TEST_ASSERT(ft_strncmp("Hello", "Hello", 5) == 0, "ft_strncmp identical strings");
    TEST_ASSERT(ft_strncmp("Hello", "Hell", 4) == 0, "ft_strncmp first 4 chars");
    TEST_ASSERT(ft_strncmp("Hello", "Help", 3) == 0, "ft_strncmp first 3 chars");
    TEST_ASSERT(ft_strncmp("Hello", "Help", 4) < 0, "ft_strncmp 'Hello' < 'Help'");
    TEST_ASSERT(ft_strncmp("Help", "Hello", 4) > 0, "ft_strncmp 'Help' > 'Hello'");
    TEST_ASSERT(ft_strncmp("", "", 0) == 0, "ft_strncmp empty strings with n=0");
}

void test_ft_strlcpy(void)
{
    printf(BLUE "\n=== Testing ft_strlcpy ===\n" RESET);

    char dest[20];
    unsigned int result;

    result = ft_strlcpy(dest, "Hello", sizeof(dest));
    TEST_ASSERT(result == 5 && strcmp(dest, "Hello") == 0, "ft_strlcpy normal case");

    result = ft_strlcpy(dest, "Hello, World!", 6);
    TEST_ASSERT(result == 13 && strcmp(dest, "Hello") == 0, "ft_strlcpy with truncation");

    result = ft_strlcpy(dest, "Hi", sizeof(dest));
    TEST_ASSERT(result == 2 && strcmp(dest, "Hi") == 0, "ft_strlcpy shorter string");
}

void test_ft_strlcat(void)
{
    printf(BLUE "\n=== Testing ft_strlcat ===\n" RESET);

    char dest[20] = "Hello";
    size_t result;

    result = ft_strlcat(dest, ", World!", sizeof(dest));
    TEST_ASSERT(result == 13 && strcmp(dest, "Hello, World!") == 0, "ft_strlcat normal case");

    strcpy(dest, "Hello");
    result = ft_strlcat(dest, ", World!", 10);
    TEST_ASSERT(result == 13 && strcmp(dest, "Hello, Wo") == 0, "ft_strlcat with truncation");
}

void test_ft_strnstr(void)
{
    printf(BLUE "\n=== Testing ft_strnstr ===\n" RESET);

    char *haystack = "Hello, World!";
    TEST_ASSERT(ft_strnstr(haystack, "World", 13) == haystack + 7, "ft_strnstr find 'World'");
    TEST_ASSERT(ft_strnstr(haystack, "Hello", 13) == haystack, "ft_strnstr find at beginning");
    TEST_ASSERT(ft_strnstr(haystack, "!", 13) == haystack + 12, "ft_strnstr find at end");
    TEST_ASSERT(ft_strnstr(haystack, "World", 10) == NULL, "ft_strnstr with insufficient length");
    TEST_ASSERT(ft_strnstr(haystack, "", 13) == haystack, "ft_strnstr empty needle");
    TEST_ASSERT(ft_strnstr(haystack, "xyz", 13) == NULL, "ft_strnstr needle not found");
}

void test_ft_substr(void)
{
    printf(BLUE "\n=== Testing ft_substr ===\n" RESET);

    char *result;

    result = ft_substr("Hello, World!", 0, 5);
    TEST_ASSERT(result && strcmp(result, "Hello") == 0, "ft_substr from beginning");
    free(result);

    result = ft_substr("Hello, World!", 7, 5);
    TEST_ASSERT(result && strcmp(result, "World") == 0, "ft_substr from middle");
    free(result);

    result = ft_substr("Hello", 10, 5);
    TEST_ASSERT(result && strcmp(result, "") == 0, "ft_substr start beyond string");
    free(result);

    result = ft_substr("Hello", 2, 10);
    TEST_ASSERT(result && strcmp(result, "llo") == 0, "ft_substr length beyond string");
    free(result);
}

void test_ft_strjoin(void)
{
    printf(BLUE "\n=== Testing ft_strjoin ===\n" RESET);

    char *result;

    result = ft_strjoin("Hello", " World");
    TEST_ASSERT(result && strcmp(result, "Hello World") == 0, "ft_strjoin normal case");
    free(result);

    result = ft_strjoin("", "Hello");
    TEST_ASSERT(result && strcmp(result, "Hello") == 0, "ft_strjoin empty first string");
    free(result);

    result = ft_strjoin("Hello", "");
    TEST_ASSERT(result && strcmp(result, "Hello") == 0, "ft_strjoin empty second string");
    free(result);
}

void test_ft_strtrim(void)
{
    printf(BLUE "\n=== Testing ft_strtrim ===\n" RESET);

    char *result;

    result = ft_strtrim("   Hello   ", " ");
    TEST_ASSERT(result && strcmp(result, "Hello") == 0, "ft_strtrim spaces");
    free(result);

    result = ft_strtrim("abcHelloabc", "abc");
    TEST_ASSERT(result && strcmp(result, "Hello") == 0, "ft_strtrim multiple chars");
    free(result);

    result = ft_strtrim("Hello", "xyz");
    TEST_ASSERT(result && strcmp(result, "Hello") == 0, "ft_strtrim no trim needed");
    free(result);
}

void test_ft_split(void)
{
    printf(BLUE "\n=== Testing ft_split ===\n" RESET);

    char **result;

    result = ft_split("Hello,World,42", ',');
    TEST_ASSERT(result && result[0] && strcmp(result[0], "Hello") == 0 &&
                    result[1] && strcmp(result[1], "World") == 0 &&
                    result[2] && strcmp(result[2], "42") == 0 &&
                    result[3] == NULL,
                "ft_split basic case");
    free_array(result);

    result = ft_split("   hello   world   ", ' ');
    TEST_ASSERT(result && result[0] && strcmp(result[0], "hello") == 0 &&
                    result[1] && strcmp(result[1], "world") == 0 &&
                    result[2] == NULL,
                "ft_split with multiple separators");
    free_array(result);

    result = ft_split("", ',');
    TEST_ASSERT(result && result[0] == NULL, "ft_split empty string");
    free_array(result);
}

void test_ft_strmapi(void)
{
    printf(BLUE "\n=== Testing ft_strmapi ===\n" RESET);

    char *result = ft_strmapi("abc", test_strmapi_func);
    TEST_ASSERT(result && strcmp(result, "bcd") == 0, "ft_strmapi increment each char");
    free(result);
}

void test_ft_striteri(void)
{
    printf(BLUE "\n=== Testing ft_striteri ===\n" RESET);

    char str[] = "abc";
    ft_striteri(str, test_striteri_func);
    TEST_ASSERT(strcmp(str, "bcd") == 0, "ft_striteri increment each char");
}

void test_ft_strdup(void)
{
    printf(BLUE "\n=== Testing ft_strdup ===\n" RESET);

    char *result;

    result = ft_strdup("Hello");
    TEST_ASSERT(result && strcmp(result, "Hello") == 0, "ft_strdup normal case");
    free(result);

    result = ft_strdup("");
    TEST_ASSERT(result && strcmp(result, "") == 0, "ft_strdup empty string");
    free(result);
}

// =============================================================================
// MEMORY FUNCTIONS TESTS
// =============================================================================

void test_ft_memset(void)
{
    printf(BLUE "\n=== Testing ft_memset ===\n" RESET);

    char buffer[10];

    ft_memset(buffer, 'A', 5);
    buffer[5] = '\0';
    TEST_ASSERT(strcmp(buffer, "AAAAA") == 0, "ft_memset with 'A'");

    ft_memset(buffer, 0, 10);
    TEST_ASSERT(buffer[0] == 0 && buffer[9] == 0, "ft_memset with 0");
}

void test_ft_bzero(void)
{
    printf(BLUE "\n=== Testing ft_bzero ===\n" RESET);

    char buffer[10] = "Hello";
    ft_bzero(buffer, 5);
    TEST_ASSERT(buffer[0] == 0 && buffer[4] == 0, "ft_bzero clears memory");
}

void test_ft_memcpy(void)
{
    printf(BLUE "\n=== Testing ft_memcpy ===\n" RESET);

    char src[] = "Hello";
    char dest[10];

    ft_memcpy(dest, src, 5);
    dest[5] = '\0';
    TEST_ASSERT(strcmp(dest, "Hello") == 0, "ft_memcpy normal case");
}

void test_ft_memmove(void)
{
    printf(BLUE "\n=== Testing ft_memmove ===\n" RESET);

    char buffer[] = "Hello World";

    ft_memmove(buffer + 2, buffer, 5);
    TEST_ASSERT(strncmp(buffer, "HeHello", 7) == 0, "ft_memmove overlapping forward");

    strcpy(buffer, "Hello World");
    ft_memmove(buffer, buffer + 2, 5);
    TEST_ASSERT(strncmp(buffer, "llo W", 5) == 0, "ft_memmove overlapping backward");
}

void test_ft_memchr(void)
{
    printf(BLUE "\n=== Testing ft_memchr ===\n" RESET);

    char *str = "Hello, World!";
    TEST_ASSERT(ft_memchr(str, 'o', 13) == str + 4, "ft_memchr find 'o'");
    TEST_ASSERT(ft_memchr(str, 'x', 13) == NULL, "ft_memchr not found");
    TEST_ASSERT(ft_memchr(str, 'o', 3) == NULL, "ft_memchr with limited length");
}

void test_ft_memcmp(void)
{
    printf(BLUE "\n=== Testing ft_memcmp ===\n" RESET);

    TEST_ASSERT(ft_memcmp("Hello", "Hello", 5) == 0, "ft_memcmp identical");
    TEST_ASSERT(ft_memcmp("Hello", "Help", 4) < 0, "ft_memcmp 'Hello' < 'Help'");
    TEST_ASSERT(ft_memcmp("Help", "Hello", 4) > 0, "ft_memcmp 'Help' > 'Hello'");
    TEST_ASSERT(ft_memcmp("Hello", "Help", 3) == 0, "ft_memcmp partial match");
}
void test_ft_calloc(void)
{
    printf(BLUE "\n=== Testing ft_calloc ===\n" RESET);

    int *ptr = (int *)ft_calloc(5, sizeof(int));
    TEST_ASSERT(ptr != NULL, "ft_calloc returns non-NULL");
    TEST_ASSERT(ptr[0] == 0 && ptr[4] == 0, "ft_calloc initializes to zero");
    free(ptr);

    char *ptr2 = (char *)ft_calloc(10, sizeof(char));
    TEST_ASSERT(ptr2 != NULL && ptr2[0] == 0 && ptr2[9] == 0, "ft_calloc char array");
    free(ptr2);
}

// =============================================================================
// CONVERSION FUNCTIONS TESTS
// =============================================================================

void test_ft_atoi(void)
{
    printf(BLUE "\n=== Testing ft_atoi ===\n" RESET);

    TEST_ASSERT(ft_atoi("123") == 123, "ft_atoi positive number");
    TEST_ASSERT(ft_atoi("-123") == -123, "ft_atoi negative number");
    TEST_ASSERT(ft_atoi("   42") == 42, "ft_atoi with leading spaces");
    TEST_ASSERT(ft_atoi("+42") == 42, "ft_atoi with plus sign");
    TEST_ASSERT(ft_atoi("0") == 0, "ft_atoi zero");
    TEST_ASSERT(ft_atoi("42abc") == 42, "ft_atoi with trailing non-digits");
    TEST_ASSERT(ft_atoi("abc") == 0, "ft_atoi non-numeric string");
}

void test_ft_itoa(void)
{
    printf(BLUE "\n=== Testing ft_itoa ===\n" RESET);

    char *result;

    result = ft_itoa(123);
    TEST_ASSERT(result && strcmp(result, "123") == 0, "ft_itoa positive number");
    free(result);

    result = ft_itoa(-123);
    TEST_ASSERT(result && strcmp(result, "-123") == 0, "ft_itoa negative number");
    free(result);

    result = ft_itoa(0);
    TEST_ASSERT(result && strcmp(result, "0") == 0, "ft_itoa zero");
    free(result);

    result = ft_itoa(-2147483648);
    TEST_ASSERT(result && strcmp(result, "-2147483648") == 0, "ft_itoa INT_MIN");
    free(result);
}

// =============================================================================
// FILE DESCRIPTOR FUNCTIONS TESTS
// =============================================================================

void test_ft_putchar_fd(void)
{
    printf(BLUE "\n=== Testing ft_putchar_fd ===\n" RESET);

    // Create a temporary file for testing
    int fd = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd != -1)
    {
        ft_putchar_fd('A', fd);
        close(fd);

        // Read back the file
        fd = open("test_output.txt", O_RDONLY);
        char c;
        read(fd, &c, 1);
        close(fd);
        unlink("test_output.txt");

        TEST_ASSERT(c == 'A', "ft_putchar_fd writes correct character");
    }
    else
    {
        printf(YELLOW "⚠ Skipping ft_putchar_fd test (file creation failed)\n" RESET);
    }
}

void test_ft_putstr_fd(void)
{
    printf(BLUE "\n=== Testing ft_putstr_fd ===\n" RESET);

    int fd = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd != -1)
    {
        ft_putstr_fd("Hello", fd);
        close(fd);

        fd = open("test_output.txt", O_RDONLY);
        char buffer[10];
        int bytes_read = read(fd, buffer, 5);
        buffer[bytes_read] = '\0';
        close(fd);
        unlink("test_output.txt");

        TEST_ASSERT(strcmp(buffer, "Hello") == 0, "ft_putstr_fd writes correct string");
    }
    else
    {
        printf(YELLOW "⚠ Skipping ft_putstr_fd test (file creation failed)\n" RESET);
    }
}

void test_ft_putendl_fd(void)
{
    printf(BLUE "\n=== Testing ft_putendl_fd ===\n" RESET);

    int fd = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd != -1)
    {
        ft_putendl_fd("Hello", fd);
        close(fd);

        fd = open("test_output.txt", O_RDONLY);
        char buffer[10];
        int bytes_read = read(fd, buffer, 6);
        buffer[bytes_read] = '\0';
        close(fd);
        unlink("test_output.txt");

        TEST_ASSERT(strcmp(buffer, "Hello\n") == 0, "ft_putendl_fd writes string with newline");
    }
    else
    {
        printf(YELLOW "⚠ Skipping ft_putendl_fd test (file creation failed)\n" RESET);
    }
}

void test_ft_putnbr_fd(void)
{
    printf(BLUE "\n=== Testing ft_putnbr_fd ===\n" RESET);

    int fd = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd != -1)
    {
        ft_putnbr_fd(123, fd);
        close(fd);

        fd = open("test_output.txt", O_RDONLY);
        char buffer[10];
        int bytes_read = read(fd, buffer, 3);
        buffer[bytes_read] = '\0';
        close(fd);
        unlink("test_output.txt");

        TEST_ASSERT(strcmp(buffer, "123") == 0, "ft_putnbr_fd writes correct number");
    }
    else
    {
        printf(YELLOW "⚠ Skipping ft_putnbr_fd test (file creation failed)\n" RESET);
    }
}

// =============================================================================
// LINKED LIST FUNCTIONS TESTS (BONUS)
// =============================================================================

#ifdef BONUS_TESTS

void test_ft_lstnew(void)
{
    printf(BLUE "\n=== Testing ft_lstnew ===\n" RESET);

    char *content = strdup("Hello");
    t_list *node = ft_lstnew(content);

    TEST_ASSERT(node != NULL, "ft_lstnew returns non-NULL");
    TEST_ASSERT(node->content == content, "ft_lstnew sets content correctly");
    TEST_ASSERT(node->next == NULL, "ft_lstnew sets next to NULL");

    free(content);
    free(node);
}

void test_ft_lstadd_front(void)
{
    printf(BLUE "\n=== Testing ft_lstadd_front ===\n" RESET);

    t_list *list = NULL;
    t_list *node1 = ft_lstnew(strdup("World"));
    t_list *node2 = ft_lstnew(strdup("Hello"));

    ft_lstadd_front(&list, node1);
    TEST_ASSERT(list == node1, "ft_lstadd_front to empty list");

    ft_lstadd_front(&list, node2);
    TEST_ASSERT(list == node2 && list->next == node1, "ft_lstadd_front to existing list");

    free(node1->content);
    free(node2->content);
    free(node1);
    free(node2);
}

void test_ft_lstsize(void)
{
    printf(BLUE "\n=== Testing ft_lstsize ===\n" RESET);

    t_list *list = NULL;
    TEST_ASSERT(ft_lstsize(list) == 0, "ft_lstsize empty list");

    t_list *node1 = ft_lstnew(strdup("1"));
    t_list *node2 = ft_lstnew(strdup("2"));
    t_list *node3 = ft_lstnew(strdup("3"));

    ft_lstadd_front(&list, node1);
    TEST_ASSERT(ft_lstsize(list) == 1, "ft_lstsize single node");

    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node3);
    TEST_ASSERT(ft_lstsize(list) == 3, "ft_lstsize multiple nodes");

    free(node1->content);
    free(node2->content);
    free(node3->content);
    free(node1);
    free(node2);
    free(node3);
}

void test_ft_lstlast(void)
{
    printf(BLUE "\n=== Testing ft_lstlast ===\n" RESET);

    t_list *list = NULL;
    TEST_ASSERT(ft_lstlast(list) == NULL, "ft_lstlast empty list");

    t_list *node1 = ft_lstnew(strdup("1"));
    t_list *node2 = ft_lstnew(strdup("2"));

    ft_lstadd_front(&list, node1);
    TEST_ASSERT(ft_lstlast(list) == node1, "ft_lstlast single node");

    ft_lstadd_front(&list, node2);
    TEST_ASSERT(ft_lstlast(list) == node1, "ft_lstlast multiple nodes");

    free(node1->content);
    free(node2->content);
    free(node1);
    free(node2);
}

void test_ft_lstadd_back(void)
{
    printf(BLUE "\n=== Testing ft_lstadd_back ===\n" RESET);

    t_list *list = NULL;
    t_list *node1 = ft_lstnew(strdup("Hello"));
    t_list *node2 = ft_lstnew(strdup("World"));

    ft_lstadd_back(&list, node1);
    TEST_ASSERT(list == node1, "ft_lstadd_back to empty list");

    ft_lstadd_back(&list, node2);
    TEST_ASSERT(list == node1 && list->next == node2, "ft_lstadd_back to existing list");

    free(node1->content);
    free(node2->content);
    free(node1);
    free(node2);
}

void test_ft_lstdelone(void)
{
    printf(BLUE "\n=== Testing ft_lstdelone ===\n" RESET);

    t_list *node = ft_lstnew(strdup("Hello"));

    // Note: ft_lstdelone frees the node, so we can't check much after calling it
    // This is more of a "doesn't crash" test
    ft_lstdelone(node, del_content);
    TEST_ASSERT(1, "ft_lstdelone doesn't crash"); // If we get here, it didn't crash
}

void test_ft_lstclear(void)
{
    printf(BLUE "\n=== Testing ft_lstclear ===\n" RESET);

    t_list *list = NULL;
    t_list *node1 = ft_lstnew(strdup("1"));
    t_list *node2 = ft_lstnew(strdup("2"));

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    ft_lstclear(&list, del_content);
    TEST_ASSERT(list == NULL, "ft_lstclear sets list to NULL");
}

void test_ft_lstiter(void)
{
    printf(BLUE "\n=== Testing ft_lstiter ===\n" RESET);

    // This is hard to test without output capture, so we'll just test it doesn't crash
    t_list *list = NULL;
    t_list *node1 = ft_lstnew(strdup("Hello"));
    t_list *node2 = ft_lstnew(strdup("World"));

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    ft_lstiter(list, print_content);
    TEST_ASSERT(1, "ft_lstiter doesn't crash");

    ft_lstclear(&list, del_content);
}

void test_ft_lstmap(void)
{
    printf(BLUE "\n=== Testing ft_lstmap ===\n" RESET);

    t_list *list = NULL;
    t_list *node1 = ft_lstnew(strdup("Hello"));
    t_list *node2 = ft_lstnew(strdup("World"));

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    t_list *new_list = ft_lstmap(list, duplicate_content, del_content);
    TEST_ASSERT(new_list != NULL, "ft_lstmap returns non-NULL");
    TEST_ASSERT(ft_lstsize(new_list) == 2, "ft_lstmap preserves list size");

    ft_lstclear(&list, del_content);
    ft_lstclear(&new_list, del_content);
}

#endif // BONUS_TESTS

// =============================================================================
// MAIN FUNCTION
// =============================================================================

int main(void)
{
    printf(YELLOW "=== LIBFT TEST SUITE ===\n" RESET);
    printf("Testing all libft functions...\n\n");

    // Character classification tests
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_toupper();
    test_ft_tolower();

    // String function tests
    test_ft_strlen();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_strnstr();
    test_ft_substr();
    test_ft_strjoin();
    test_ft_strtrim();
    test_ft_split();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_strdup();

    // Memory function tests
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_calloc();

    // Conversion function tests
    test_ft_atoi();
    test_ft_itoa();

    // File descriptor function tests
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();

    // Linked list function tests (bonus)
#ifdef BONUS_TESTS
    test_ft_lstnew();
    test_ft_lstadd_front();
    test_ft_lstsize();
    test_ft_lstlast();
    test_ft_lstadd_back();
    test_ft_lstdelone();
    test_ft_lstclear();
    test_ft_lstiter();
    test_ft_lstmap();
#endif

    // Print summary
    printf(YELLOW "\n=== TEST SUMMARY ===\n" RESET);
    printf("Total tests: %d\n", test_count);
    printf(GREEN "Passed: %d\n" RESET, test_passed);
    printf(RED "Failed: %d\n" RESET, test_count - test_passed);

    if (test_passed == test_count)
    {
        printf(GREEN "\n🎉 All tests passed! Your libft is working correctly!\n" RESET);
        return 0;
    }
    else
    {
        printf(RED "\n❌ Some tests failed. Please check your implementations.\n" RESET);
        return 1;
    }
}
