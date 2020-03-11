/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatesho <dmatesho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:50:02 by dmatesho          #+#    #+#             */
/*   Updated: 2020/03/10 21:51:21 by dmatesho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_remaining(char *remaining, char **line)
{
    char *p_n;

    p_n = NULL;
    if (remaining)
    {
        if ((p_n = ft_strchr(remaining, '\n')))
        {
            *p_n = '\0';
            *line = ft_strdup(remaining);
            ft_strcpy(remaining, p_n + 1);
        }
        else
        {
            *line = ft_strdup(remaining);
            ft_strclr(remaining);
        }
    }
    else
        *line = ft_strnew(1);
    return (p_n);
}

int	get_line(const int fd, char **line, char **remaining)
{
    char    buf[BUFF_SIZE + 1];
    int     buf_was_read;
    char    *p_n;
    char    *tmp;

    *line = ft_strnew(1);
    p_n = check_remaining(*remaining, line);
    while (!(p_n) && (buf_was_read = read(fd, &buf, BUFF_SIZE)))
    {
        buf[buf_was_read] = 0;
        if ((p_n = ft_strchr(buf, '\n')))
        {
            *remaining = ft_strdup(p_n + 1);
            *p_n = '\0';
        }
        tmp = *line;
        *line = ft_strjoin(*line, buf);
        free(tmp);
    }
    return (buf_was_read || ft_strlen(*line) ? 1 : 0);
}

GNL *new_ll(int fd)
{
    GNL new;

    new = (GNL *)malloc(sizeof(GNL));
    new->fd = fd;
    new->remaining = ft_strnew(BUFF_SIZE);
    new->next = NULL;
    return (new);
}

int	get_next_line(const int fd, char **line)
{
    static GNL  *head;
    GNL         *tmp;

    if (!head)
        head = new_ll(fd);
    tmp = head;
    while (tmp->fd != fd)
    {
        if (!tmp->next)
            tmp->next = new_ll(fd);
        tmp = tmp->next;
    }
    return (get_line(tmp->fd, line, &tmp->remaining));

}


int main(void)
{
    char    *line;
    int     fd;

    fd = open("text.txt", O_RDONLY);
    while (get_next_line(fd, &line))
        printf("%s\n\n", line);
}
