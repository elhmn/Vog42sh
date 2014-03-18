/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:48:45 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/18 14:27:13 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			whoami_aux(char *line, int *tok)
{
	if (ft_strchr(line, '|'))
	{
		*tok = PIPE;
		return (1);
	}
	else if (ft_strchr(line, ';'))
	{
		*tok = SEMIC;
		return (1);
	}
	else if (ft_strstr(line, "&&"))
	{
		*tok = AND;
		return (1);
	}
	else if (ft_strstr(line, "||"))
	{
		*tok = OR;
		return (1);
	}
	else
	{
		*tok = CMD;
		return (2);
	}
}

static int			whoami(char *line, int *tok)
{
	if (ft_strchr(line, '>'))
	{
		*tok = OUT;
		return (0);
	}
	else if (ft_strchr(line, '<'))
	{
		*tok = IN;
		return (0);
	}
	else if (ft_strstr(line, ">>"))
	{
		*tok = APP;
		return (0);
	}
	return (whoami_aux(line, tok));
}

static t_lex		*get_arg(t_lex *lex, char **str, int *i)
{
	char			*arg;

	lex = add_lex(lex, str[*i], CMD);
	*i = *i + 1;
	if (str[*i] && !is_spec(str[*i]))
	{
		arg = ft_strdup(str[*i]);
		*i = *i + 1;
		while (str[*i] && !is_spec(str[*i]))
		{
			arg = ft_strjoin(arg, " ");
			arg = ft_strjoin(arg, str[*i]);
			*i = *i + 1;
			if (!str[*i])
				break ;
		}
	}
	else
		return (lex);
	return (lex = add_lex(lex, arg, ARG));
}

static t_lex		*fill_lex(t_lex *lex, char **line)
{
	int				i;
	int				tok;

	tok = 0;
	i = 0;
	while (line[i])
	{
		if (!whoami(line[i], &tok))
		{
			lex = add_lex(lex, line[i++], tok);
			if (line[i] && !is_spec(line[i]))
				lex = add_lex(lex, line[i++], FIL);
			i++;
		}
		else if (whoami(line[i], &tok) == 2)
		{
			lex = get_arg(lex, line, &i);
			if (!line[i])
				break ;
		}
		else
			lex = add_lex(lex, line[i++], tok);
	}
	lex = add_lex(lex, NULL, VOID);
	return (lex);
}

t_lex				*lexer(char *str)
{
	t_lex			*lex;
	char			**line;

	line = NULL;
	lex = NULL;
	if (!str || !str[0])
		return (lex);
	if (!(str = ft_strtrim_lex(str)))
		return (NULL);
	line = ft_strsplit(str, ' ');
	lex = fill_lex(lex, line);
	print_lex(lex);
	return (lex);
}

int					main(int ac, char **av)
{
	if (ac > 0)
		lexer(av[1]);
	return (0);
}
