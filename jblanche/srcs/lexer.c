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

#include "lexer.h"

// Reception: cd dev && cp ../img/toto.jpg titi && env -i &&

static t_lex		*add_if_spec(t_lex *tmp, char *line, int *i)
{
	if (!ft_strchr(line, '>') || !ft_strchr(line, '<')
		|| !ft_strstr(line, ">>") || !ft_strchr(line, '|')
		|| !ft_strchr(line, ';') || !ft_strstr(line, "&&")
		|| !ft_strstr(line, "||"))
	{
		tmp = add_lex(tmp, line, CMD);
		*i = *i + 1;
	}
	return (tmp);
}

static t_lex		*fill_lex(t_lex *lex, char **line)
{
	int				i;
	t_lex			*tmp;

	i = 0;
	tmp = lex;
	while (line[i])
	{
		tmp = add_if_spec(tmp, line[i], &i);
		add_lex(lex, line[i], CMD);
		i++;
	}
	return (lex);
}

t_lex				*lexer(char *str)
{
	t_lex			*lex;
	char			**line;

	line = NULL;
	lex = NULL;
	lex = init_lex(lex);
	if (!str || !str[0])
		return (lex);
	ft_printf("lexer initialized\n");
	ft_printf("str = %s\n", str);
	if (!(str = ft_strtrim_lex(str)))
		return (NULL);
	ft_printf("cp9\n");
	ft_printf("str cut. str = %s, line[0] = %s\n", str, line[0]);
	line = ft_strsplit(str, ' ');
	lex = fill_lex(lex, line);
	return (lex);
}

int					main(int ac, char **av)
{
	if (ac > 0)
		lexer(av[1]);
	return (0);
}
