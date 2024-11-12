FUNCTION         TESTS                RESULT
ft_isalpha       ✓✓✓✓✓✓✓              OK
ft_isdigit       ✓✓✓✓✓✓✓              OK
ft_isalnum       ✓✓✓✓✓✓✓              OK
ft_isascii       ✓✓✓✓✓✓✓✓             OK
ft_isprint       ✓✓✓✓✓✓✓              OK
ft_strlen        ✓✓✓✓✓✓               OK
ft_memset        ✓✓✓✓                 OK
ft_bzero         ✓✓                   OK
ft_memcpy        ✓✓✓                  OK
ft_memmove       ✓✓✓✓✓                OK
ft_strlcpy       ✓✓✗✗✗                KO
ft_strlcat       ✓✓✓✗✗✗✗✗✗            KO
ft_toupper       ✓✓✓✓✓✓✓              OK
ft_tolower       ✓✓✓✓✓✓✓              OK
ft_strchr        ✓✓✓✓✗✗               KO
ft_strrchr       ✗✓✓✓✓✓✗✓             KO
ft_strncmp       ✓✓✓✓✓✓✓✗✗✗✗          KO
ft_memchr        ✓✓✓✓✓✓               OK
ft_memcmp        ✓✓✓✓✓✓✓✓✓            OK
ft_strnstr       ✗✗✗✓✗✗✓✓✗✓           KO
ft_atoi          ✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓✓  OK
ft_calloc        ✓                    OK
ft_strdup        ✓                    OK
ft_substr        ✗✗✓✓✗                KO
ft_strjoin       ✓✓✓✓                 OK
ft_strtrim       ✓✓✓✓✓                OK
ft_split         ✓✓✓✓✓✓               OK
ft_itoa          ✗✗✗✗✗✗✗✗✗✗           KO
ft_strmapi       ✓                    OK
ft_striteri      ✓                    OK
ft_putchar_fd    ✓✓✓✓✓✓✓              OK
ft_putstr_fd     ✓✓✓✓                 OK
ft_putendl_fd    ✓✓✓✓                 OK
ft_putnbr_fd     ✓✓✓✓✓✓✓✓✓            OK

Abort: A  Bus error: B  Segmentation fault: S  Timeout: T

More information in: /home/ngaudoui/.local/share/francinette/temp/libft/war-machine/deepthought

Errors in strlcat: /home/ngaudoui/.local/share/francinette/temp/libft/war-machine/tests/Part1_functions/ft_strlcat
Test 4:
    dest[14] = 'a';
    ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
    write(1, "\n", 1);
    write(1, dest, 15);
Expected (cat -e test04.output):
32$
rrrrrrlorem ip^@
Your result (cat -e user_output_test04):
32$
rrrrrrlorem ips
Test 5:
    dest[10] = 'a';
    ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
    write(1, "\n", 1);
    write(1, dest, 15);
Expected (cat -e test05.output):
26$
...

File too large. To see full report open: /home/ngaudoui/.local/share/francinette/temp/libft/war-machine/errors.log

✔ Compiling tests: libftTester (https://github.com/Tripouille/libftTester)
ℹ Testing:
ft_isalpha	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 
ft_isdigit	: 1.OK 2.OK 3.OK 4.OK 
ft_isalnum	: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 
ft_isascii	: 1.OK 2.OK 3.OK 4.OK 
ft_isprint	: 1.OK 2.OK 3.OK 4.OK 
ft_strlen	: 1.OK 2.OK 
ft_memset	: 1.OK 2.OK 
ft_bzero	: 1.OK 2.OK 3.OK 
ft_memcpy	: 1.OK 2.OK 3.OK 
ft_memmove	: 1.OK 2.OK 3.OK 4.OK 
ft_strlcpy	: 1.KO 2.KO 3.KO 4.OK 5.KO 6.OK 7.OK 8.OK 9.KO 
ft_strlcat	: 1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.OK 11.OK 12.OK 13.KO 14.KO 15.KO 16.OK 17.KO 
ft_toupper	: 1.OK 2.OK 3.OK 4.OK 
ft_tolower	: 1.OK 2.OK 3.OK 4.OK 
ft_strchr	: 1.OK 2.OK 3.OK 4.KO 5.OK 
ft_strrchr	: 1.KO 2.OK 3.OK 4.OK 5.OK 6.KO 7.OK 8.KO 
ft_strncmp	: 1.KO 2.KO 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.KO 13.KO 14.OK 15.OK 16.OK 
ft_memchr	: 1.OK 2.OK 3.OK 4.OK 5.OK 
ft_memcmp	: 1.OK 2.OK 3.OK 4.OK 5.OK 
ft_strnstr	: 1.OK 2.KO 3.KO 4.KO 5.OK 6.OK 7.OK 8.KO 9.OK 10.KO 11.OK 12.KO 13.OK 14.OK 
ft_atoi		: 1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.OK 10.OK 11.OK 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 
ft_calloc	: 1.OK 2.MOK 
ft_strdup	: 1.OK 2.MOK 3.OK 4.MOK 
ft_substr	: 1.OK 2.MOK 3.KO 4.MKO 5.SIGSEGV
ft_strjoin	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 
ft_strtrim	: 1.OK 2.MOK 3.OK 4.MOK 5.OK 6.MOK 7.OK 8.MOK 9.OK 10.MOK 11.OK 12.MOK 13.OK 14.MOK 15.KO 16.MOK 
ft_split	: 1.MKO 2.SIGSEGV
ft_itoa		: 1.OK 2.MOK 3.KO 4.MKO 5.OK 6.MOK 7.OK 8.MOK 9.OK 10.MOK 11.OK 12.MOK 
nbr = 2147483647
len = 10nbr = -2147483648
len = 2nbr = 0
len = 1nbr = 1
len = 1nbr = -1
len = 2nbr = 42
ft_strmapi	: 1.OK 2.MOK 3.OK 4.MOK 
ft_striteri	: 1.OK 2.OK 3.OK 
ft_putchar_fd	: 1.OK 
ft_putstr_fd	: 1.OK 
ft_putendl_fd	: 1.OK 
ft_putnbr_fd	: 1.OK 2.OK 3.OK 4.OK 5.OK 

MKO: test about your malloc size (this shouldn't be tested by moulinette)

Errors in:

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_strlcpy_test.cpp:
KO  20: 	/* 1 */ check(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A'); showLeaks();
KO  21: 	/* 2 */ check(ft_strlcpy(dest, src, 1) == strlen(src) && dest[0] == 0 && dest[1] == 'A'); showLeaks();
KO  22: 	/* 3 */ check(ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A'); showLeaks();
KO  24: 	/* 5 */ check(ft_strlcpy(dest, src, 6) == strlen(src) && !memcmp(src, dest, 5) && dest[5] == 0); showLeaks(); memset(dest, 'A', 10);
KO  28: 	/* 9 */ check(ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0); showLeaks(); memset(dest, 'A', 10);

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_strlcat_test.cpp:
KO  21: 	/* 1 */ check(ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B")); showLeaks();
KO  23: 	/* 2 */ check(ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B")); showLeaks();
KO  25: 	/* 3 */ check(ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB")); showLeaks();
KO  26: 	/* 4 */ check(ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA")); showLeaks();
KO  28: 	/* 5 */ check(ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA")); showLeaks();
KO  30: 	/* 6 */ check(ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA")); showLeaks();
KO  32: 	/* 7 */ check(ft_strlcat(dest, src, 1) == strlen(src) && !strcmp(dest, "")); showLeaks();
KO  34: 	/* 8 */ check(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111")); showLeaks();
KO  36: 	/* 9 */ check(ft_strlcat(dest, src, 5) == strlen(src) + 5 && !strcmp(dest, "1111111111")); showLeaks();
KO  44: 	/* 13 */ check(ft_strlcat(dest, "123", 1) == 3 && !strcmp(dest, "")); showLeaks();
KO  46: 	/* 14 */ check(ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1")); showLeaks();
KO  48: 	/* 15 */ check(ft_strlcat(dest, "123", 3) == 3 && !strcmp(dest, "12")); showLeaks();
KO  52: 	/* 17 */ check(ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, "")); showLeaks();

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_strchr_test.cpp:
KO  21: 	/* 4 */ check(ft_strchr(s, 0) == s + strlen(s)); showLeaks();

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_strrchr_test.cpp:
KO  20: 	/* 1 */ check(ft_strrchr(s, 't') == s); showLeaks();
KO  25: 	/* 6 */ check(ft_strrchr(s, 't' + 256) == s); showLeaks();
KO  28: 	/* 8 */ check(ft_strrchr(s3, 0) == s3); showLeaks();

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_strncmp_test.cpp:
KO  18: 	/* 1 */ check(ft_strncmp("t", "", 0) == 0); showLeaks();
KO  19: 	/* 2 */ check(ft_strncmp("1234", "1235", 3) == 0); showLeaks();
KO  29: 	/* 12 */ check(ft_strncmp("", "1", 0) == 0); showLeaks();
KO  30: 	/* 13 */ check(ft_strncmp("1", "", 0) == 0); showLeaks();

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_strnstr_test.cpp:
KO  22: 	/* 2 */ check(ft_strnstr(haystack, needle, -1) == haystack + 1); showLeaks();
KO  23: 	/* 3 */ check(ft_strnstr(haystack, "a", -1) == haystack); showLeaks();
KO  24: 	/* 4 */ check(ft_strnstr(haystack, "c", -1) == haystack + 4); showLeaks();
KO  28: 	/* 8 */ check(ft_strnstr(haystack, "aaabc", 5) == haystack); showLeaks();
KO  30: 	/* 10 */ check(ft_strnstr(haystack, "abcd", 9) == haystack + 5); showLeaks();
KO  32: 	/* 12 mbueno-g */ check(ft_strnstr(haystack, "a", 1) == haystack); showLeaks();

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_substr_test.cpp:
KO  23: 	/* 3 */ check(!strcmp(s, "r"));
MKO 24: 	/* 4 */ mcheck(s, 2); free(s); showLeaks();
SIGSEGV 27: 	/* 5 */ check(!strcmp(s, ""));

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_strtrim_test.cpp:
KO  47: 	/* opsec-infosec 15 */ check(!strcmp(s, "d"));

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_split_test.cpp:
MKO 26: 	/* 1 */ mcheck(tab, sizeof(char *) * 3);
SIGSEGV 28: 	/* 2 */ check(!strcmp(tab[0], "tripouille"));

For /home/ngaudoui/.local/share/francinette/tests/libft/Tripouille/tests/ft_itoa_test.cpp:
KO  24: 	/* 3 */ check(!strcmp(s, to_string(INT_MIN).c_str()));
MKO 25: 	/* 4 */ mcheck(s, strlen(to_string(INT_MIN).c_str()) + 1); free(s); showLeaks();

✔ Compiling tests: libft-unit-test (https://github.com/alelievr/libft-unit-test)
ℹ Testing:
ft_isalpha      : [OK] 
ft_isdigit      : [OK] 
ft_isalnum      : [OK] 
ft_isascii      : [OK] 
ft_isprint      : [OK] 
ft_strlen       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_memset       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_bzero        : [OK] [OK] [OK] [OK] 
ft_memcpy       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [CRASH] 
[crash]: your memcpy does not behave well with NULL as both params with size

ft_memmove      : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strlcpy      : [OK] [OK] [OK] [FAILED] [OK] [FAILED] [OK] 
[fail]: your strlcpy does works whe size < strlen(src)
[fail]: your strlcpy copies while destsize is zero, or does not return the size of the string it tried to create

ft_strlcat      : [FAILED] [FAILED] [FAILED] [OK] [OK] [OK] [OK] [OK] [OK] [FAILED] [OK] [OK] 
[fail]: your strlcat does not work with basic input
[fail]: your strlcat does not work with basic input
[fail]: your strlcat does not work with basic input
[fail]: your strlcat return value is false

ft_toupper      : [OK] 
ft_tolower      : [OK] 
ft_strchr       : [OK] [OK] [OK] [OK] [OK] [OK] [FAILED] [OK] [OK] [OK] 
[fail]: your strchr does not work with \0

ft_strrchr      : [OK] [FAILED] [OK] [OK] [OK] [OK] [OK] [OK] 
[fail]: your strrchr does not work with basic input

ft_strncmp      : [OK] [OK] [OK] [OK] [OK] [OK] [FAILED] [OK] [OK] [FAILED] [FAILED] [OK] [OK] [OK] 
[fail]: your strncmp does not cast in unsigned char the diff
[fail]: your strncmp does not work with non ascii chars
[fail]: your strncmp does not work when s1 is contained in s2

ft_memchr       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_memcmp       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strnstr      : [FAILED] [OK] [OK] [FAILED] [OK] [OK] [OK] [OK] [OK] [FAILED] [FAILED] [OK] [OK] [OK] 
[fail]: your strnstr does not work with basic input
[fail]: your strnstr does not work with basic input
[fail]: your strnstr does not work with the same pointer "little" string
[fail]: your strnstr does not work with the same pointer and an exceeding length value

ft_atoi         : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_calloc       : [OK] [OK] [OK] [OK] [OK] 
ft_strdup       : [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_substr       : [OK] [OK] [OK] [FAILED] [FAILED] [CRASH] [OK] [OK] [CRASH] 
[fail]: your substr did not allocate the good size so the \0 test may be false
[fail]: your substr does not set \0 to the end of the string
[crash]: you did not protect your malloc
[crash]: your substr does not work when start >= ft_strlen(s)

ft_strjoin      : [OK] [OK] [OK] [OK] [OK] 
ft_strtrim      : [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_split        : [CRASH] [OK] [CRASH] [CRASH] [OK] [OK] [OK] [CRASH] [OK] [OK] nbr = -623
len = 4nbr = 156
len = 3nbr = 0
len = 1
[crash]: your split does not work with basic input
[crash]: your split does not work with one word
[crash]: your split does not work with one word
[crash]: your split does not work with basic input


len = 10[OK] nbr = 2147483647
len = 10[OK] nbr = -2147483648
len = 2[FAILED] nbr = -1234
len = 5[OK] nbr = -1234
len = 5[OK] nbr = -5859
len = 5[OK] nbr = 0
len = 1[OK] nbr = -2147483648
len = 2[OK] 
[fail]: your itoa does not work with min int

ft_strmapi      : [OK] [OK] [OK] [OK] [OK] 
ft_striteri     : [OK] [OK] 
ft_putchar_fd   : [OK] [OK] 
ft_putstr_fd    : [OK] [OK] 
ft_putendl_fd   : [OK] [OK] 
ft_putnbr_fd    : [OK] [OK] [OK] [OK] [OK] 

[crash]: your memcpy does not behave well with NULL as both params with size
 Test code:
 	ft_memcpy(((void*)0), ((void*)0), 3);
 
 
 [fail]: your strlcpy does works whe size < strlen(src)
 Test code:
 	char *str = "hello !";
 	char buff1[0xF00];
 	char buff2[0xF00];
 	size_t r1;
 	size_t r2;
 
 	memset(buff1, 'A', 20);
 	memset(buff2, 'A', 20);
 	r1 = strlcpy(buff1, str, 2);
 	r2 = ft_strlcpy(buff2, str, 2);
 	if (r1 == r2 && !memcmp(buff1, buff2, 20))
 		exit(TEST_SUCCESS);
 	if (r1 != r2)
 	{
 	}
 		for (register int __i = 0; __i < 20; ++__i)
 		for (register int __i = 0; __i < 20; ++__i)
 	}
 	exit(TEST_FAILED);
 
 Diffs:
      strlcpy: |\x68 \x0  \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 |
   ft_strlcpy: |\x68 \x65 \x6c \x6c \x6f \x20 \x21 \x0  \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 \x41 |
 
 [fail]: your strlcpy copies while destsize is zero, or does not return the size of the string it tried to create
 Test code:
 	char *str = "BBBB";
 	char buff1[0xF00];
 	char buff2[0xF00];
 
 	memset(buff1, 'A', 20);
 	memset(buff2, 'A', 20);
 	if (strlcpy(buff1, str, 0) != ft_strlcpy(buff2, str, 0))
 		exit(TEST_FAILED);
 	if (!memcmp(buff1, buff2, 20))
 		exit(TEST_SUCCESS);
 	for (register int __i = 0; __i < 20; ++__i)
 	for (register int __i = 0; __i < 20; ++__i)
 	exit(TEST_FAILED);
 
 Diffs:
 
 
...

File too large. To see full report open: /home/ngaudoui/.local/share/francinette/temp/libft/alelievr/result.log

✔ Compiling tests: fsoares (my own)
ℹ Testing:
ft_isalpha      : OK
ft_isdigit      : OK
ft_isalnum      : OK
ft_isascii      : OK
ft_isprint      : OK
ft_strlen       : OK
ft_memset       : OK
ft_bzero        : OK
ft_memcpy       : OK
ft_memmove      : OK
ft_strlcpy      : KO
ft_strlcat      : KO
ft_toupper      : OK
ft_tolower      : OK
ft_strchr       : KO
ft_strrchr      : KO
ft_strncmp      : KO
ft_memchr       : OK
ft_memcmp       : OK
ft_strnstr      : KO
ft_atoi         : OK
ft_calloc       : OK
ft_strdup       : OK
ft_substr       : KO
ft_strjoin      : OK
ft_strtrim      : OK
ft_split        : OK
ft_itoa         : nbr = 0
len = 1nbr = 1000034
len = 7nbr = -10004
len = 6nbr = 2147483647
len = 10nbr = -2147483648
len = 2KO
'NoneType' object has no attribute 'group'

Summary: no bonus

Norminette Errors: ft_atoi.c, ft_memchr.c, ft_memcmp.c, ft_memmove.c, ft_memset.c, ft_putendl_fd.c, ft_putnbr_fd.c, ft_putstr_fd.c, ft_split.c, ft_strchr.c, ft_strjoin.c, ft_strlcat.c, ft_strncmp.c, ft_strnstr.c, ft_strrchr.c, ft_strtrim.c, ft_substr.c, ft_tolower.c, ft_toupper.c, libft.h

Failed tests: strrchr, fsoares, memcpy, ft_itoa, ft_strlcat, strlcpy, strncmp, ft_substr, ft_strrchr, substr, ft_split, itoa, ft_strtrim, ft_strchr, ft_strnstr, ft_strlcpy, split, strnstr, strlcat, ft_strncmp, strchr

Passed tests: isalpha, isdigit, isalnum, isascii, isprint, strlen, memset, bzero, memmove, toupper, tolower, memchr, memcmp, atoi, calloc, strdup, strjoin, strtrim, strmapi, striteri, putchar_fd, putstr_fd, putendl_fd, putnbr_fd
