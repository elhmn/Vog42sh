/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 16:27:01 by troussel          #+#    #+#             */
/*   Updated: 2014/01/26 14:41:43 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_emptyline(t_chk *chk, char **line, char *resp)
{
	*line = resp;
	if (chk->size == 1)
		ft_strdel(&chk->str);
	else
		chk->str = ft_strsub(chk->str, 1, chk->size - 1);
	chk->size -= 1;
	return (1);
}

static int	ft_gotnb(t_chk *chk, char *resp, char **line)
{
	int	i;

	i = -1;
	while (chk->str[++i] != '\n' && i != (int)chk->size + 1)
		;
	if (i == (int)chk->size + 1)
		return (0);
	resp = (char*)malloc(sizeof(char));
	resp[0] = '\0';
	if (i == 0)
		return (ft_emptyline(chk, line, resp));
	ft_strdel(&resp);
	resp = ft_strsub(chk->str, 0, i);
	*line = resp;
	if ((int)chk->size - i - 1 != 0)
		chk->str = ft_strsub(chk->str, i + 1, chk->size - (size_t)i - 1);
	else
		ft_strdel(&chk->str);
	chk->size = (chk->size - i - 1);
	return (1);
}

static char	*ft_strjoin_gnl(char *chk, char *buf, size_t chk_size, size_t size)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)malloc(sizeof(char) * (chk_size + 1));
	while (++i != (int)(chk_size - size))
		str[i] = chk[i];
	ft_strdel(&chk);
	while (i != (int)chk_size)
	{
		str[i] = buf[i - chk_size + size];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_dumpstr(t_chk *chk, char *resp, char **line)
{
	int	i;

	i = -1;
	while (chk->str[++i] != '\n' && i != (int)chk->size + 1)
		;
	resp = (char*)malloc(sizeof(char));
	resp[0] = '\0';
	if (i == (int)chk->size + 1)
		resp = ft_strsub(chk->str, 0, i - 1);
	else if (i == (int)chk->size || (i > 0 && i < (int)chk->size))
		resp = ft_strsub(chk->str, 0, i);
	*line = resp;
	if (i == 0 && chk->size != 1)
		chk->str = ft_strsub(chk->str, 1, chk->size - 1);
	else if (i > 0 && i < (int)chk->size)
		chk->str = ft_strsub(chk->str, i + 1, chk->size - (size_t)i - 1);
	else
		ft_strdel(&chk->str);
	if (i == 0)
		chk->size -= 1;
	else if (i > 0 && i < (int)chk->size)
		chk->size = (chk->size - i - 1);
	else
		chk->size = 0;
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_chk	chk;
	int				size;
	char			**buf_resp;

	if (line == NULL || !(buf_resp = (char**)malloc(sizeof(*buf_resp) * 2)))
		return (-1);
	if (!(buf_resp[0] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((size = read(fd, buf_resp[0], BUFF_SIZE)))
	{
		if (size == -1)
			return (-1);
		buf_resp[0][size] = '\0';
		chk.size += size;
		chk.str = ft_strjoin_gnl(chk.str, buf_resp[0], chk.size, size);
		if (ft_gotnb(&chk, buf_resp[1], line))
		{
			ft_strdel(&buf_resp[0]);
			return (1);
		}
	}
	ft_strdel(&buf_resp[0]);
	if (chk.size > 0)
		return (ft_dumpstr(&chk, buf_resp[1], line));
	return (0);
}
