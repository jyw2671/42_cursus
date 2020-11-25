/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:04:45 by yjung             #+#    #+#             */
/*   Updated: 2020/11/25 18:46:19 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_next_line_make(char **store, char *buf, ssize_t read_size)
{
	char	*ret;

	buf[read_size] = '\0';
	if (*store)
	{
		ret = ft_strjoin(*store, buf);
		free(*store);
	}
	else
		ret = ft_strndup(buf, read_size);
	*store = ret;
	if (ft_strchr(*store, '\n'))
		return (1);
	return (0);
}

static int	get_next_line_check(char **store, char **line)
{
	char	*tmp;
	char	*ptr;

	if ((ptr = ft_strchr(*store, '\n')))
	{
		*line = ft_strndup(*store, ptr - *store);
		tmp = ft_strndup(ptr + 1, ft_strlen(ptr + 1));
		free(*store);
		*store = tmp;
		return (1);
	}
	else
	{
		*line = *store;
		*store = 0;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char		*store[OPEN_MAX];
	char			*buf[BUFFER_SIZE + 1];
	ssize_t			read_size;

	if (!line || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if (get_next_line_make(&store[fd], (char *)buf, read_size) || \
		read_size == 0)
			break ;
	}
	if (read_size < 0)
		return (-1);
	return (get_next_line_check(&store[fd], line));
}
