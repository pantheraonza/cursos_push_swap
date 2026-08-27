/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:01:26 by criredon          #+#    #+#             */
/*   Updated: 2026/06/10 17:01:27 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// ******************************** M A N U A L ********************************
// DESCRIPTION
// Erases the first n bytes of s by writing zero bytes ('\0') to it.
// RETURN VALUES & ERRORS
// None — void function.
// ******************************* M A N U A L ********************************
