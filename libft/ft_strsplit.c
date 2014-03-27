/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:43:19 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 12:26:47 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int		count_wd(char const *str, char c)
{
	int			i;
	int			n;

	i = -1;
	n = 0;
	while (str[++i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			++n;
	}
	return (n);
}

static int		loc_str(char const *str, int tgt, char c)
{
	if (tgt == -1)
	{
		while (str[++tgt] && str[tgt] == c)
			;
		return (tgt);
	}
	while (str[++tgt] && str[tgt] != c)
		;
	if (!str[tgt])
		return (-1);
	while (str[++tgt] && str[tgt] == c)
		;
	if (!str[tgt])
		return (-1);
	return (tgt);
}

static int		loc_strend(char const *str, int tgt, char c)
{
	while (str[++tgt] && str[tgt] != c)
		;
	return (tgt);
}

static char		*load_subs(char const *str, int len, int tgt, char *subs)
{
	int	i;

	i = -1;
	while (++i != len)
		subs[i] = str[tgt + i];
	subs[i] = 0;
	return (subs);
}

char			**ft_strsplit(char const *str, char c)
{
	char		**splt;
	int			n_wd;
	int			tgt;
	int			tgt_end;
	int			len;

	n_wd = count_wd(str, c);
	splt = (char**)malloc(sizeof(char*) * (n_wd + 1));
	splt[n_wd] = 0;
	if (!n_wd)
		return (splt);
	tgt = -1;
	n_wd = 0;
	while ((tgt = loc_str(str, tgt, c)) != -1)
	{
		tgt_end = loc_strend(str, tgt, c);
		len = tgt_end - tgt;
		splt[n_wd] = (char*)malloc(sizeof(char) * len);
		splt[n_wd] = load_subs(str, len, tgt, splt[n_wd]);
		++n_wd;
	}
	return (splt);
}
