/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:02:11 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 17:02:12 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long number)
{
	size_t	len;

	len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new;
	long	number;
	size_t	len;

	number = n;
	len = ft_numlen(number);
	new = malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[len] = '\0';
	if (number < 0)
	{
		new[0] = '-';
		number = -number;
	}
	while (len > (new[0] == '-'))
	{
		new[--len] = (number % 10) + '0';
		number /= 10;
	}
	return (new);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	char	*r;

// 	printf("Tests with Replicated Function (Edge Cases)\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): itoa(42)\n");
// 	r = ft_itoa(42);
// 	printf("--> Repl \"%s\"\n", r);
// 	free(r);
// 	printf("************************************************************\n");
// 	printf("Test 1 (INT_MIN): itoa(INT_MIN)\n");
// 	r = ft_itoa(INT_MIN);
// 	printf("--> Repl \"%s\"\n", r);
// 	free(r);
// 	return (0);
// }

// ******************************* M A N U A L ********************************
// DESCRIPTION
// char *ft_itoa(int n);
// Allocates (with malloc) and returns a newly allocated string
// representing the integer n.
// RETURN VALUES & ERRORS
// Returns the newly created string, or NULL if malloc fails.
// The function ft_itoa DOES NOT modify the original integer.
// It CREATES a NEW string containing its decimal representation.
// STRUCTURE
// long number                  copy of n stored as long
// size_t len                   number of characters to allocate
// char *new                    pointer to the newly allocated string
// if (new == NULL)             safety check
// new[len] = '\0'              add the string terminator
// if (number < 0)              write '-' and convert to positive
// while (...)                  fill the string from right to left,
//                              writing one digit per iteration
// return (new)                 return the pointer to the new string
// There are edge cases to take into account:
// ft_itoa returns NULL if malloc fails.
// Zero ("0") is handled as a one-character string.
// INT_MIN is handled correctly because the value is first promoted
// from int to long before being negated.
// Other important things to know:
// ft_numlen() calculates exactly how many characters are needed
// before allocating memory.
// The digits are written from right to left.
// Each iteration stores the last digit using (number % 10) and then
// removes it using (number / 10) until every digit has been written.
// This implementation does not need to reverse the string because
// it starts writing from the end of the allocated buffer.
// ******************************* M A N U A L ********************************