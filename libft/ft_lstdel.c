/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:55:20 by dmatesho          #+#    #+#             */
/*   Updated: 2020/02/25 23:35:02 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cur;
	t_list *nxt;

	cur = *alst;
	while (cur)
	{
		nxt = cur->next;
		del(cur->content, cur->content_size);
		free(cur);
		cur = nxt;
	}
	*alst = NULL;
}
