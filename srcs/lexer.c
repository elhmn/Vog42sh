/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:48:45 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/25 14:19:34 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int			whoami_aux(char *line, int *tok)
{
	if (ft_strstr(line, "||"))
	{
		*tok = OR;
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
	else if (ft_strchr(line, '|'))
	{
		*tok = PIPE;
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
	lex = add_lex(lex, str[*i], CMD);
	*i = *i + 1;
	while (str[*i] && !is_spec(str[*i]))
	{
		lex = add_lex(lex, str[*i], ARG);
		*i = *i + 1;
	}
	return (lex);
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
	return (lex);
}
