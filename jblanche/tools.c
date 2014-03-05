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

#include "libft/libft.h"

static int		ft_is_blank(char c)
{
	return (c == ' ' || c == '	');
}

static char		*del_spaces(char *str, int i)
{
	int			j;

	i++;
	j = i;
	while (str[i] && str[i] == ' ')
	{
		while (str[i])
			str[i] = str[i + 1];
	}
	return (str);
}

static char		*trim_inline(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '	')
			str[i] = ' ';
		i++;
	}
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			str = del_spaces(str, i);
		i++;
	}
	return (str);
}

char			*ft_strtrim(char *s)
{
	char		*new_str;
	size_t		i;
	size_t		len;

	len = ft_strlen(s) - 1;
	i = 0;
	if (!s || !s[i])
		return (ft_strnew(1));
	while (s[i] && ft_is_blank(s[i]))
		i++;
	while (len != i && ft_is_blank(s[len]))
		len--;
	if (!i && len == ft_strlen(s) - 1)
	{
		new_str = ft_strsub(s, 0, ft_strlen(s));
		return (new_str);
	}
	new_str = ft_strsub(s, i, len - i + 1);
	if (!new_str)
		return (NULL);
	new_str = trim_inline(new_str);
	return (new_str);
}
