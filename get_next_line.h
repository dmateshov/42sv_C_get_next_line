/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <dmatesho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:50:08 by dmatesho          #+#    #+#             */
/*   Updated: 2020/03/09 20:06:08 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFF_SIZE 8
# define MAX_FD 1000

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct      get_next_line
{
    int             fd;
    char            *remaining;
    get_next_line   *next;
}                   GNL

int	get_next_line(const int fd, char **line);

#endif
