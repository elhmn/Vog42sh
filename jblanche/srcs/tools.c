/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:58:39 by bmbarga           #+#    #+#             */
/*   Updated: 2013/12/29 14:08:38 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int		ft_is_blank(char c)
{
	return (c == ' ' || c == '	');
}

static char		*del_spaces(char *str, int i)
{
	int			j;

	i++;
	while (str[i] && str[i] == ' ')
	{
		j = i;
		while (str[j])
		{
			str[j] = str[j + 1];
			j++;
		}
	}
	return (str);
}

static char		*trim_inline(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			str = del_spaces(str, i);
		i++;
	}
	return (str);
}

char			*ft_strtrim_lex(char *s)
{
	char		*new_str;
	size_t		i;
	size_t		len;

	len = ft_strlen(s) - 1;
	i = 0;
	if (!s || !s[0])
		return (ft_strnew(1));
	while (s[i] && ft_is_blank(s[i]))
		i++;
	while (len != i && ft_is_blank(s[len]))
		len--;
	new_str = ft_strsub(s, i, len - i + 1);
	if (!new_str)
		return (NULL);
	new_str = trim_inline(new_str);
	return (new_str);
}
