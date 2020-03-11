/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:17:30 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/24 17:01:40 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ptr_s1;
	unsigned const char	*ptr_s2;

	if (n == 0)
		return (0);
	ptr_s1 = (unsigned const char *)s1;
	ptr_s2 = (unsigned const char *)s2;
	i = 0;
	while (ptr_s1[i] == ptr_s2[i] && i < n - 1)
		i++;
	return ((unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
}
