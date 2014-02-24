/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:36:18 by jblanche          #+#    #+#             */
/*   Updated: 2014/01/14 15:05:32 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "sh.h"

static void		work_on_buffers(char *buf_tmp, int i, char *buf, int choice)
{
	int	j;

	j = 0;
	if (choice)
	{
		while (buf[i])
			buf_tmp[j++] = buf[i++];
		buf_tmp[j] = '\0';
	}
	else
	{
		while (buf_tmp[i])
			buf_tmp[j++] = buf_tmp[i++];
		buf_tmp[j] = '\0';
	}
}

static int		aux_gnl(char *buf_tmp, char **str, char **line, int fd)
{
	int	ret;
	int	cycle;

	cycle = 0;
	str[STR] = ft_strjoin(buf_tmp, NULL);
	while ((ret = read(fd, str[BUFF], BUFF_SIZE)) && ret != -1)
	{
		cycle++;
		if (str[BUFF][0] == '\n')
			return (2);
		if ((str[TMP] = ft_strchr(str[BUFF], '\n')))
		{
			work_on_buffers(buf_tmp, str[TMP] - str[BUFF] + 1, str[BUFF], 1);
			str[STR] = ft_strjoin(str[STR], ft_strsub(str[BUFF], 0, str[TMP]
									- str[BUFF]));
			*line = str[STR];
			return (1);
		}
		str[STR] = ft_strjoin(str[STR], ft_strsub(str[BUFF], 0, BUFF_SIZE));
		str[BUFF] = ft_memset(str[BUFF], '\0', BUFF_SIZE);
	}
	if (cycle == 0)
		kill(0, SIGUSR2);
	buf_tmp[BUFF_SIZE] = MY_EOF;
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	char			**str;
	static char		buf_tmp[BUFF_SIZE + 1] = "";
	int				ret;

	str = (char**)malloc(sizeof(char*) * 3);
	if (buf_tmp[BUFF_SIZE] == MY_EOF)
		return (0);
	if (fd < 0 || fd > MAX_NBR || BUFF_SIZE <= 0 || !line)
		return (-1);
	if ((str[TMP] = ft_strchr(buf_tmp, '\n')))
	{
		*line = ft_memmove(ft_memalloc(str[TMP] - buf_tmp),
							buf_tmp, str[TMP] - buf_tmp);
		work_on_buffers(buf_tmp, (str[TMP] - buf_tmp + 1), str[BUFF], 0);
		return (1);
	}
	if (!(str[BUFF] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	str[BUFF][BUFF_SIZE] = '\0';
	if ((ret = aux_gnl(buf_tmp, str, line, fd)) == -1)
		return (-1);
	if (ret == 2)
		return (2);
	*line = str[STR];
	return (1);
}
