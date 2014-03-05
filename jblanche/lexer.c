/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:48:45 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/03 13:36:57 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft/libft.h"

// Reception: cd dev && cp ../img/toto.jpg titi && env -i &&

static t_lex		*add_if_spec(t_lex *tmp, char *line, int *i)
{
	if (!ft_strchr(line[*i], ">") || !ft_strchr(line[*i], "<")
		|| !ft_strchr(line[*i], ">>") || !ft_strchr(line[*i], "|")
		|| !ft_strchr(line[*i], ";") || !ft_strchr(line[*i], "&&")
		|| !ft_strchr(line[*i], "||"))
	{
		tmp = add_lex(tmp, line[i], );
		*i++;
	}
}

static t_lex		*fill_lex(t_lex *lex, char **line)
{
	int				i;
	t_lex			*tmp;

	i = 0;
	tmp = lex;
	tmp = add_if_spec(tmp, line[i], &i);
	add_lex(lex, line[i], CMD);
	while (line[i])
	{
		
		i++;
	}
	return (lex);
}

t_lex				*lexer(char *str)
{
	t_lex			*lex;
	char			**line;

	lex = init_lex(lex);
	str = ft_strtrim_lex(str);
	line = ft_strsplit(line);
	lex = fill_lex(lex, line);
}
