/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:13:48 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/24 11:42:01 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t l;

	if (!*needle)
		return ((char *)haystack);
	l = 0;
	while (needle[l])
		l++;
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (j == l - 1)
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
