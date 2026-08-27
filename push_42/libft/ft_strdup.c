/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:04:09 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:04:10 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *str;
// 	char *orig;
// 	char *repl;

// 	str = "Hello World";
// 	printf("Tests with Original & Replicated Functions (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): duplicate \"Hello World\"\n");
// 	orig = strdup(str);
// 	repl = ft_strdup(str);
// 	printf("--> Orig %s | Repl %s\n", orig, repl);
// 	free(orig);
// 	free(repl);
// 	printf("************************************************************\n");
// 	printf("Test 1 (Empty string)\n");
// 	orig = strdup("");
// 	repl = ft_strdup("");
// 	printf("--> Orig '%s' | Repl '%s'\n", orig, repl);
// 	free(orig);
// 	free(repl);
// 	return (0);
// }

/* ******************************* M A N U A L *********************************
// DESCRIPTION
// The  strdup()  function returns a pointer to a new string which is a
// duplicate of the string s. Memory for the new string is obtained with
// malloc(3), and can be freed with free(3).
// The strndup() function is similar, but copies at most n bytes.
// If s is longer than n,  only  n bytes are copied, and a terminating
// null byte ('\0') is added.
// strdupa()  and  strndupa()  are  similar,  but  use alloca(3) to allocate
// the buffer.  They are available only when using the GNU GCC suite,
// and suffer from the same limitations described  in alloca(3)
// RETURN VALUES
// On  success, the strdup() function returns a pointer to the duplicated string.
// It returns NULL if insufficient memory was available, with errno set to
// indicate the cause of the error.
// ERRORS
// ENOMEM Insufficient memory available to allocate duplicate string.
******************************** M A N U A L ******************************** */