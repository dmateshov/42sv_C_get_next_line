/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:41:41 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/27 13:31:31 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	is_ws(char const *str, size_t i, int dir)
{
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i += dir;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	int		k;
	char	*ptr;

	if (!s)
		return (NULL);
	i = is_ws(s, 0, 1);
	j = ft_strlen(s);
	if (i < j)
		j = is_ws(s, j - 1, -1) + 1;
	if (!(ptr = (char *)malloc(j - i + 1)))
		return (NULL);
	k = 0;
	while (i < j)
	{
		ptr[k] = s[i];
		i++;
		k++;
	}
	ptr[k] = 0;
	return (ptr);
}
