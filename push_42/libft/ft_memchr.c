/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:03:14 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:03:15 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(&ptr[i]));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*result;
// 	char	text[] = "Hello 42!";

// 	printf("Tests with Original & Replicated Functions\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): search for '4'\n");
// 	result = ft_memchr(text, '4', ft_strlen(text));
// 	if (result != NULL)
// 	{
// 		printf("--> Found \"%c\"\n", *result);
// 		printf("--> Starts from \"%s\"\n", result);
// 		printf("--> Position %ld\n", result - text);
// 	}
// 	else
// 		printf("--> Not found\n");
// 	return (0);
// }

// ******************************* M A N U A L ********************************
// DESCRIPTION
// void *ft_memchr(const void *s, int c, size_t n);
// Searches the first n bytes of the memory block pointed to by s
// for the first occurrence of the byte c.
// RETURN VALUES & ERRORS
// Returns a pointer to the first matching byte.
// Returns NULL if the byte is not found.
// STRUCTURE
// const unsigned char *ptr;		view the memory as individual bytes
// size_t i;						current byte being inspected
// ptr = (const unsigned char *)s;	cast the generic memory block into bytes
// i = 0;							start from the first byte
// while (...)						scan exactly n bytes
// if (...)							compare the current byte with c
// return (...)						return the address of the matching byte
// return (NULL)					no matching byte was found
// There are edge cases to take into account:
// ft_memchr does not stop when a '\0' byte is found.
// It always scans exactly n bytes.
// If n is 0, nothing is searched and NULL is returned.
// Other important things to know:
// Unlike ft_strchr(), ft_memchr() works on raw memory rather than
// C strings, so '\0' has no special meaning.
// The returned pointer points directly inside the original memory
// block; no new memory is allocated.
// ******************************* M A N U A L ********************************