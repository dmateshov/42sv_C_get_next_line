/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:49:49 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/27 13:00:56 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_num_len(int n)
{
	int				len;
	unsigned int	nc;

	len = 0;
	if (n <= 0)
	{
		len += 1;
		nc = -n;
	}
	else
		nc = n;
	while (nc > 0)
	{
		nc /= 10;
		len += 1;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	unsigned int	nc;
	char			*ptr;
	int				len;

	len = ft_num_len(n);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = 0;
	len--;
	if (n < 0)
	{
		ptr[0] = '-';
		nc = -n;
	}
	else
		nc = n;
	if (n == 0)
		ptr[0] = '0';
	while (nc > 0)
	{
		ptr[len] = (nc % 10) + 48;
		len--;
		nc /= 10;
	}
	return (ptr);
}
