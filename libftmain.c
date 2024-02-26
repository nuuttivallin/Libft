/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvallin <nvallin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:46:41 by nvallin           #+#    #+#             */
/*   Updated: 2024/02/26 16:04:34 by nvallin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

void    test_print(char *s1, char *s2, int n)
{
    printf("Comparing '%s' and '%s' up to %d bytes:\n", s1, s2, n);
    printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
    printf("strncmp: %d\n\n", strncmp(s1, s2, n));
}

void    test_print2(char *s1, char *s2, int n)
{
    printf("Comparing '%s' and '%s' up to %d bytes:\n", s1, s2, n);
    printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, n));
    printf("memcmp: %d\n\n", memcmp(s1, s2, n));
}

void	*ft_nothing(void *s)
{
	s++;
	return (s);
}


void	ft_del(void *content)
{
	free(content);
}

int	main(void)
{
	char	s[10];
	char	s2[10];
  	strcpy(s, "yesyesyes");
	strcpy(s2, "yesyesyes");
	ft_bzero(s, 0);
//	printf("ft_bzero with 0: %s\n", s);
//	bzero(s2, 0);
	printf("bzero with 0: %s\n\n", s2);
	ft_bzero(s, 1);
	printf("ft_bzero with 1: %s\n", s);
	printf("string +2: %s\n", s + 2);
	bzero(s2, 1);
	printf("bzero with 1: %s\n", s2);
	printf("string +2: %s\n\n", s2 + 2);
	ft_bzero(s, 9);
	printf("ft_bzero with 9: %s\n\n", s + 8);

	printf("ft_isalpha 'a': %d\n", ft_isalpha('a'));
	printf("ft_isalpha '3': %d\n", ft_isalpha('3'));
	puts("");

	printf("ft_isdigit '9': %d\n", ft_isdigit('9'));
	printf("ft_isdigit 'A': %d\n", ft_isdigit('A'));
	puts("");

	printf("ft_isalnum '3': %d\n", ft_isalnum('3'));
	printf("ft_isalnum 'w': %d\n", ft_isalnum('w'));
	printf("ft_isalnum '!': %d\n", ft_isalnum('!'));
	printf("isalnum '!': %d\n", isalnum('!'));
	puts("");

	printf("ft_isprint ' ': %d\n", ft_isprint(' '));
	printf("isprint ' ': %d\n\n", isprint(' '));

	char	str[50];
	strcpy(str, "This is string.h library function");
	puts(str);
	puts("ft_memset 123, 7");
	ft_memset(str, 123, 7);
	puts(str);
	puts("memset 124, 7");
	memset(str, 124, 7);
	puts(str);

	int	arr[6] = {1, 2, 3, 4, 5};
	ft_memset(arr, '1', 6);
	int	i = 0;
	puts("ft_memset int array 1,2,3,4,5 with int c '1' and len 6:");
   	while (arr[i] != '\0')
		printf("%d\n", arr[i++]);
	puts("");

	int	arr2[6] = {1, 2, 3, 4, 5};
	memset(arr2, '1', 6);
	i = 0;
	puts("memset int array 1,2,3,4,5 with int c '1' and len 6:");
	while (arr2[i])
		printf("%d\n", arr2[i++]);
	puts("");

	char	des[10];
	char	so[10];
	strcpy(des, "desti");
	strcpy(so, "soosi");
	ft_memcpy(des, so, 2);
	puts("ft_memcpy desti, soosi, 2");
	puts(des);
	strcpy(des, "desti");
	strcpy(so, "soosi");
	puts("memcpy desti, soosi, 2");
	memcpy(des, so, 2);
	puts(des);

	ft_memmove(so + 2, so, 6);
	puts("ft_memmove soosi + 2, soosi, 6");
	puts(so);
	memmove(so + 2, so, 8);
	puts("memmove sosoosi + 2, sosoosi, 6");
	puts(so);


	char			dest[25] = "Cannon fodder";
	char			dest2[25] = "Cannon fodder";
	int				result;
	int				res;
	unsigned int	l;
	char			source[12] = "Copy_this!\n";
	char			source2[12] = "Copy_this!\n";

	l = 6;
	result = ft_strlcpy(dest, source, l);
	printf("The length of the source string is %d\n", result);
	printf("Copied string: %s\n", dest);
	res = strlcpy(dest2, source2, l);
	printf("The length of the source string is %d\n", res);
	printf("Copied string: %s\n", dest2);

	char			desti[30] = "It's easy ";
	int				resulti;
	unsigned int	li;
	char			sourcei[27] = "as 123!";
	char			desti2[30] = "It's easy ";
	char			sourcei2[27] = "as 123!";
	int				resi;

	resi = strlcat(desti2, sourcei2, 5);
	li = 5;
	printf("%d\n", resi);
	printf("%s\n", desti2);
	resulti = ft_strlcat(desti, sourcei, li);
	printf("The length of the string we tried to create: %d\n", resulti);
	printf("Copied string: %s\n", desti);

	printf("cat %lu\n", strlcat(((void *)0), "hi!", 0));
	printf("ft_cat %lu\n", ft_strlcat(((void *)0), "hi!", 0));
	
	char	*mdesti;
	mdesti = malloc(15);
	memset(mdesti, 'r', 15);
	resulti = ft_strlcat(mdesti, "lorem ipsum dolor sit amet", 5);
	printf("ft_strlcat: The length of the string we tried to create: %d\n", resulti);
	printf("Copied string: %s\n", mdesti);
	char	*mdest;
	mdest = malloc(15);
	memset(mdest, 'r', 15);
	resi = strlcat(mdest, "lorem ipsum dolor sit amet", 5);
	printf("strlcat: The length of the string we tried to create: %d\n", resi);
	printf("Copied string: %s\n", mdest);

	puts("ft_toupper str index 12");
	str[12] = ft_toupper(str[12]);
	puts(str);
	puts("touppre str index 13");
	str[13] = toupper(str[13]);
	puts(str);
	puts("ft_tolower str index 12");
	str[12] = ft_tolower(str[12]);
	puts(str);

	puts("ft_strchr look for i");
	puts(ft_strchr(str, 'i'));
	puts("ft_strchr look for z");
	puts(ft_strchr(str, 122));
	puts(strchr(str, 122));
	puts("ft_strchr look for e");
	puts(ft_strchr("teste", 'e'));
	puts("ft_strchr look for i");
	puts(ft_strrchr(str, 105));


    test_print("abcde", "abcd", 5);         // Different at 5th char
    test_print("abcde", "bbcde", 5);  // Different at 1st char s
    test_print("abc", "abcd", 3);           // Identical up to 3 chars
    // Empty strings
    test_print("", "", 5);                  // Both empty
    test_print("abc", "", 3);               // One empty

    test_print2("abcd", "abc", 4);           // Different at 4th char
    // Special characters
    test_print2("abc\0def", "abc\0dgh", 7);  // Include null terminator in middle
    // Empty strings
    test_print2("", "", 5);                  // Both empty
    test_print2("abc", "", 3);               // One empty

	puts(ft_memchr(str, 104, 40));
	puts(ft_memchr("bonjourno", 'n', 2));
	puts(memchr("bonjourno", 'n', 2));

	
	char	from[40] = "see FF your FF return FF now FF";
	char	find[20] = "FF";
	char	*resultii;
	char	*resii;

	resii = strnstr(from, find, 20);
	resultii = ft_strnstr(from, find, 20);
	printf("%s\n", resii);
	printf("%s\n", resultii);
	
	puts(ft_strnstr("aaabcdacd", "aabc", -1));
	puts(strnstr("aaabcdacd", "aabc", -1));

	int	fato;
	int ato;
	fato = ft_atoi("   +2147483647ab567");
	ato = atoi("   +2147483647ab567");
	printf("ft_atoi '   +2147483647ab567': %d\n", fato);
	printf("atoi '   +2147483647ab567': %d\n", ato);
	printf("ft_atoi 2147483649: %d\n", ft_atoi("2147483649"));
	printf("atoi 2147483649: %d\n", atoi("2147483649"));
	printf("ft_atoi 21474836490: %d\n", ft_atoi("21474836490"));
	printf("atoi 21474836490: %d\n", atoi("21474836490"));
	printf("ft_atoi -2147483648: %d\n", ft_atoi("-2147483648"));
	printf("atoi -2147483648: %d\n", atoi("-2147483648"));
	printf("ft_atoi -214748364877: %d\n", ft_atoi("-214748364877"));
	printf("atoi -214748364877: %d\n", atoi("-214748364877"));
	printf("ft_atoi 21474836490000000000: %d\n", ft_atoi("21474836490000000000"));
	printf("atoi 21474836490000000000: %d\n", atoi("21474836490000000000"));
	printf("ft_atoi :63410682753376583680  %d\n", ft_atoi("	  \n63410682753376583680"));
	printf("atoi : :63410682753376583680 %d\n", atoi(" 	\n 63410682753376583680"));

	char	*ft_call;
	ft_call = ft_calloc(21, sizeof(char));
	strcpy(ft_call, "calloc"); 
	char	*call;
	call = calloc(21, sizeof(char));
	strcpy(call, "calloc");
	printf("ft_calloc: %s\n", ft_call);
	printf("calloc: %s\n", call);
	free(ft_call);
	free(call);	

	char	*dup;
	dup = ft_strdup("duppi");
	puts(dup);

	char	*sub;
   	sub = ft_substr(so, 4, 4);
	puts(sub);

	sub = ft_strjoin(dup, sub);
	puts(sub);

	char	*trim;
	trim = ft_strtrim("asdheldslosda", "asd");
	puts(trim);

	char	**splits;
	splits = ft_split(" a aa  a a  ", 'a');
	i = 0;
	while (i < 5)
		puts(splits[i++]);

	char **spl;
	spl = ft_split("          ", ' ');
	if (spl == NULL)
		printf("null?\n");
	else
		printf("%s", *spl);

	char **sp;
	sp = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse",' ');
	i = 0;
	while (i < 12)
		puts(sp[i++]);

	char	*intti;
	intti = ft_itoa(-2147483648);
	puts(intti);

	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd("print", 1);
	ft_putchar_fd('\n', 1);

	ft_putendl_fd("string", 2);

	ft_putnbr_fd(-2147483648, 1);

	puts(" ");

	t_list	*lista;
	char	*gon;
	gon = strdup("first");
	lista = ft_lstnew(gon);
	printf("%s\n", lista->content);

	t_list	*listb;
	char	*tent;
   	tent = strdup("firster");
	listb = ft_lstnew(tent);
	ft_lstadd_front(&lista, listb);
	printf("first in list: %s\n", lista->content);
	printf("second in list: %s\n", lista->next->content);

	printf("length of list: %d\n", ft_lstsize(lista));
	
	t_list	*node;
	char	*tti;
   	tti = strdup("last");
	node = ft_lstnew(tti);

	ft_lstadd_back(&lista, node);

	printf("length of list: %d\n", ft_lstsize(lista));

	t_list	*last;
	last = ft_lstlast(lista);
	printf("last node of list: %s\n", last->content);

	ft_lstdelone(node, &ft_del);
	lista->next->next = NULL;
	last = ft_lstlast(lista);
	printf("last node of list: %s\n", last->content);

    t_list  *uusi;
    uusi = ft_lstmap(lista, &ft_nothing, &ft_del);	

	printf("length of new list: %d\n", ft_lstsize(uusi));

	ft_lstclear(&lista, &ft_del);
	printf("length of lista after clear: %d\n", ft_lstsize(lista));

	return (0);
}
