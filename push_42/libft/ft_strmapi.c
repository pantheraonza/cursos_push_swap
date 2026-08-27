/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:02:28 by criredon          #+#    #+#             */
/*   Updated: 2026/06/11 17:02:29 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	new = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < ft_strlen(s))
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

// #include <stdio.h>

// static char	wrapper_ft_toupper(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_toupper(c));
// }

// int	main(void)
// {
// 	char	*result;

// 	printf("Tests with Replicated Function\n");
// 	printf("************************************************************\n");
// 	printf("Test 0 (Happy path): transform \"abcd\"\n");
// 	result = ft_strmapi("abcd", wrapper_ft_toupper);
// 	printf("--> Repl \"%s\"\n", result);
// 	free(result);
// 	return (0);
// }
