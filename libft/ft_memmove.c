/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:21:44 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/27 21:47:41 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	unsigned char		*ptr_src;
	size_t				i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst == NULL || src == NULL || len == 0)
		return (dst);
	if (ptr_src < ptr_dst)
	{
		i = 0;
		while (++i <= len)
			ptr_dst[len - i] = ptr_src[len - i];
	}
	else
	{
		i = -1;
		while (++i < len)
			ptr_dst[i] = ptr_src[i];
	}
	return (dst);
}
