/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:25:12 by yjung             #+#    #+#             */
/*   Updated: 2020/11/24 23:10:06 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int	get_next_line_make(char **store, char *buf, ssize_t read_size)
{
	char	*tmp;

	buf[read_size] = '\0';
	if (!(*store))
	{
		tmp = ft_strjoin(*store, buf);
		free(*store);
	}
	else
		tmp = ft_strndup(buf, read_size);
	*store = tmp;
	if (ft_strchr(*store, '\n') != 0)
		return (1);
	return (0);
}

static int	get_next_line_check(char **store, char **line)
{
	char	*tmp;

	if (ft_strchr(store, '\n') == 0)
	{

		return (1);
	}
	else
	{

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
	// buffer가 작아서 아직 \n까지 못 읽은 경우 -> 계속 버퍼만 큼 불러와서 strjoin하기
	//						-> \n 만난 경우 while 빠져나옴(\n 이후부분은 저장해놓기)
	// buffer가 너무 커서 \n을 여러개 읽은 경우

	// 남은 줄이 한줄밖에 없는경우
	while (read_size = read(fd, buf, BUFFER_SIZE) >= 0)
	{
		if (get_next_line_make(store, buf, read_size) == 0 || read_size <= 0)
			break;
	}
	// read 시에 컴퓨터가 정해준 fd값이 아닌 다른 fd 값을 넣었을경우 예외처리
	if (read_size < 0)
		return (-1);
	return (get_next_line_check(&store[fd], &line));
}

int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("testfile2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
