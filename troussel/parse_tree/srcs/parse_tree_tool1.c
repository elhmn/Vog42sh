/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_tool1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:17:09 by troussel          #+#    #+#             */
/*   Updated: 2014/03/12 13:03:52 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftsh.h"
#include "parse_tree.h"
#include "error_sh.h"

t_lex		*treat_cmd(char **prg, t_lex *tok)
{
	if (tok->tok != CMD || !tok->elm)
		error(0, "Parse anomaly", 1);
	prg[0] = ft_strdup(tok->elm);
	return (tok->nxt);
}

t_lex		*treat_inf(char **ifile, t_lex *tok)
{
	t_lex	*tmp;

	if (tok->tok != IN || !tok->nxt || tok->nxt->tok != FIL || !tok->nxt->elm)
		error(0, "Parse anomaly", 1);
	tmp = tok;
	while (tmp->nxt->nxt->tok == IN)
		tmp = tmp->nxt->nxt;
	if (tmp->tok != IN || !tmp->nxt || tmp->nxt->tok != FIL || !tmp->nxt->elm)
		error(0, "Parse anomaly", 1);
	if (ifile[0])
		ft_strdel(ifile);
	ifile[0] = ft_strdup(tmp->nxt->elm);
	return (tmp->nxt->nxt);
}

static int	count_arg(t_lex *tok)
{
	int		i;
	t_lex	*tmp;

	i = 0;
	tmp = tok;
	while (tmp->tok == ARG)
	{
		++i;
		tmp = tmp->nxt;
	}
	return (i);
}

t_lex		*treat_arg(char ***arg, t_lex *tok)
{
	int		i;
	t_lex	*tmp;

	i = count_arg(tok);
	if (!(arg[0] = (char**)malloc(sizeof(char*) * (i + 2))))
	{
		error(0, "Out of memory", 0);
		return (NULL);
	}
	arg[0][i + 1] = 0;
	tmp = tok;
	i = 0;
	while (tmp && tmp->tok == ARG)
	{
		arg[0][++i] = ft_strdup(tmp->elm);
		tmp = tmp->nxt;
	}
	return (tmp);
}

t_lex		*treat_pipe(int *pipe_w, t_lex *tok)
{
	pipe_w[0] = 1;
	return (tok->nxt);
}
