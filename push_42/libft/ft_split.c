/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:02:00 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 17:02:01 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_subcnt(char const *s, char c)
{
	size_t	subcount;
	size_t	i;

	subcount = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			subcount++;
		i++;
	}
	return (subcount);
}

static size_t	ft_sublen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_arrayalloc(size_t subcount)
{
	char	**membuffer;

	membuffer = malloc((subcount + 1) * sizeof(char *));
	if (membuffer == NULL)
		return (NULL);
	return (membuffer);
}

static char	**ft_arrayclear(char **array, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	subcount;
	size_t	walk_s;
	size_t	walk_a;

	if (s == NULL)
		return (NULL);
	subcount = ft_subcnt(s, c);
	array = ft_arrayalloc(subcount);
	if (array == NULL)
		return (NULL);
	walk_s = 0;
	walk_a = 0;
	while (walk_a < subcount)
	{
		while (s[walk_s] == c)
			walk_s++;
		array[walk_a] = ft_substr(s, walk_s, (ft_sublen(s + walk_s, c)));
		if (array[walk_a] == NULL)
			return (ft_arrayclear(array, walk_a));
		walk_s = walk_s + (ft_sublen(s + walk_s, c));
		walk_a++;
	}
	array[walk_a] = NULL;
	return (array);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	**r;
// 	size_t	i;

// 	printf("Tests with Replicated Function (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): split(\"hello world 42\", ' ')\n");
// 	r = ft_split("hello world 42", ' ');
// 	i = 0;
// 	while (r[i] != NULL)
// 	{
// 		printf("  [%zu]: \"%s\"\n", i, r[i]);
// 		free(r[i]);
// 		i++;
// 	}
// 	free(r);
// 	printf("************************************************************\n");
// 	printf("Test 1 (Only delimiters \",,,,,,,\", must return empty array)\n");
// 	r = ft_split(",,,,,,,", ',');
// 	if (r[0] == NULL)
// 	printf("--> Empty array\n");
// 	else
// 	{
// 		i = 0;
// 		while (r[i] != NULL)
// 		{
// 			printf("  [%zu]: \"%s\"\n", i, r[i]);
// 			free(r[i]);
// 			i++;
// 		}
// 	}
// 	free(r);
// 	return (0);
// }

// ******************************* M A N U A L ********************************
// DESCRIPTION
// char **ft_split(char const *s, char c);
// Allocates (with malloc) and returns an array of strings obtained by
// splitting the original string using character 'c' as delimiter.
// RETURN VALUES & ERRORS
// Returns the array of strings, or NULL if a memory allocation fails.
// The function ft_split DOES NOT modify the original string.
// It CREATES a NEW array where each element points to a newly allocated
// substring.
// STRUCTURE
// char **new						pointer to the newly allocated array
// size_t subcount					total number of substrings to create
// size_t sublen					length of the current substring
// size_t walker_string				current position while walking the string
// size_t walker_array				current position while filling the array
// if (s == NULL)					safety check
// subcount = ft_subcnt(...)		count how many substrings exist
// new = malloc(...)				allocate memory for the array
// if (new == NULL)					safety check
// while (...)						create one substring per iteration
// while (s[walker_string] == c)	skip delimiter characters
// sublen = 0						start measuring the current substring
// while (...)						measure the substring until the next
//									delimiter or '\0'
// ft_substr(...)					create a new allocated substring
// if (...)							if allocation fails, free everything
//									created so far using ft_splitclear()
// walker_string += sublen			move to the end of the current substring
// walker_array++					move to the next position in the array
// new[walker_array] = NULL			add the NULL pointer marking the end
// return (new)						return the newly created array
// There are edge cases to take into account:
// ft_split returns NULL if s == NULL or malloc fails.
// Consecutive, leading and trailing delimiters are ignored.
// If no substrings are found, the function returns an allocated array
// containing only the final NULL pointer.
// Other important things to know:
// ft_subcnt() counts the exact number of substrings before the array
// is allocated, ensuring the correct amount of memory is reserved.
// ft_substr() allocates and copies each substring, so ft_split()
// never copies characters manually.
// ft_splitclear() frees every previously allocated substring if one
// allocation fails, preventing memory leaks.
// Every substring has its own allocated memory.
// Each substring must be freed before freeing the array itself.
// ******************************* M A N U A L ********************************