/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:03:57 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:03:58 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

// #include <stdio.h>
// #include <stdint.h>

// int	main(void)
// {
// 	int		*array;

// 	printf("Tests with Replicated Function\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): calloc 5 integers\n");
// 	array = ft_calloc(5, sizeof(int));
// 	if (array != NULL)
// 	{
// 		printf("--> Repl [%d] [%d] [%d] [%d] [%d]\n",
// 			array[0], array[1], array[2], array[3], array[4]);
// 		free(array);
// 	}
// 	printf("************************************************************\n");
// 	printf("Test 1 (Overflow protection)\n");
// 	array = ft_calloc(SIZE_MAX, 2);
// 	printf("--> Repl %p (expected NULL)\n", (void *)array);
// 	return (0);
// }

// ******************************* M A N U A L ********************************
// DESCRIPTION
// void *ft_calloc(size_t nmemb, size_t size);
// Allocates memory for an array of nmemb elements of size bytes each.
// The allocated memory is initialized to zero before being returned.
// RETURN VALUES & ERRORS
// Returns a pointer to the allocated memory.
// Returns NULL if the allocation fails or if the multiplication
// nmemb * size would overflow.
// The function ft_calloc DOES NOT initialize memory manually.
// It REUSES ft_bzero() to fill the allocated memory with zeros.
// STRUCTURE
// void	*ptr;					pointer to the allocated memory
// if (...)						check that nmemb * size does not overflow
// ptr = malloc(...)			allocate the requested memory
// if (ptr == NULL)				safety check
// ft_bzero(...)				initialize every allocated byte to 0
// return (ptr)					return the allocated memory
// There are edge cases to take into account:
// ft_calloc returns NULL if malloc fails.
// ft_calloc returns NULL if nmemb * size would overflow size_t.
// If nmemb or size is 0, the behaviour follows malloc(0), which is
// implementation-defined but still valid according to the C standard.
// Other important things to know:
// calloc differs from malloc because the allocated memory is always
// initialized to zero before being returned.
// The overflow check:
//		if (size != 0 && nmemb > SIZE_MAX / size)
// prevents the multiplication from wrapping around and allocating
// fewer bytes than requested.
// ft_bzero() is reused instead of rewriting the initialization logic,
// keeping the implementation simple and consistent with the rest of
// libft.
// SIZEOF USE
// sizeof is a C operator that returns the size, in bytes, of a type or
// variable. malloc() allocates raw bytes, so sizeof() is commonly used
// to compute the exact number of bytes required for a given number of
// elements, avoiding hard-coded values.
// CONCEPTO OF SIZE_MAX
// SIZE_MAX is the largest value that can be stored in a size_t.
// Before multiplying two size_t values (such as nmemb * size),
// ft_calloc verifies that the multiplication will not exceed
// SIZE_MAX, preventing integer overflow and unsafe allocations.
// ******************************* M A N U A L ********************************