/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:48:06 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/21 18:48:32 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int l;

	if (*needle == '\0')
		return ((char *)haystack);
	l = 0;
	while (needle[l])
		l++;
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == l - 1)
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
