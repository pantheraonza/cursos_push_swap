/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:01:29 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 17:01:31 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*r;

// 	printf("Tests with Replicated Function (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): join(\"hello \", \"world\")\n");
// 	r = ft_strjoin("hello ", "world");
// 	printf("--> Repl \"%s\"\n", r);
// 	free(r);
// 	printf("************************************************************\n");
// 	printf("Test 1 (Both empty): join(\"\", \"\") must return empty string\n");
// 	r = ft_strjoin("", "");
// 	printf("--> Repl \"%s\" (empty, not NULL)\n", r);
// 	free(r);
// 	return (0);
// }

// ******************************* M A N U A L ********************************
// The function ft_strjoin DOES NOT modify the original strings.
// It CREATES a NEW string by concatenating s1 followed by s2.
// char *new		pointer to the newly joined string
// if (s1 == NULL)	safety check: if one string does not exist, return NULL
// ft_strlen(s1)    calculate string length
// new = malloc()	allocate enough memory for both strings plus '\0'
// if (new == NULL) safety check: if memory allocation fails, return NULL
// ft_strlcpy(1)  	copy the 1st string into the beginning of the new string
// ft_strlcpy(2)	move the pointer len1 bytes forward and copy the
// 					second string immediately after the first one
// return (new)		return the pointer to the newly string
// There are edge cases to take into account:
// ft_strjoin returns NULL if s1 == NULL, s2 == NULL, or if malloc fails.
// Empty strings are valid inputs and produce a valid allocated string.
// ******************************* M A N U A L ********************************