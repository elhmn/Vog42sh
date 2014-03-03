/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_tool2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:17:09 by troussel          #+#    #+#             */
/*   Updated: 2014/03/03 16:02:10 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "42sh.h"
#include "parse_tree.h"

t_lex		*treat_outf(char **ofile, int *flg_app, t_lex *tok)
{
	t_lex	*tmp;

	if (!tok->nxt || tok->nxt->tok != FIL || !tok->nxt->elm)
		error(0, "Parse anomaly", 1);
	tmp = tok;
	while (tmp->nxt->nxt->tok == OUT || tmp->nxt->nxt->tok == APP)
		tmp = tmp->nxt->nxt;
	if (!tmp->nxt || tmp->nxt->tok != FIL || !tmp->nxt->elm)
		error(0, "Parse anomaly", 1);
	if (ofile[0])
		ft_strdel(ofile);
	ofile[0] = ft_strdup(tmp->nxt->elm);
	flg_app[0] = (tmp->tok == APP ? 1 : 0);
	return (tmp->nxt->nxt);
}

t_lex		*treat_redir(t_cmd **cmd, t_lex *tok)
{
	t_lex	*tmp;

	tmp = tok;
	while (tmp->tok == OUT || tmp->tok == IN || tmp->tok == APP)
	{
		if (tmp->tok == OUT || tmp->tok == APP)
			tmp = treat_outf(&cmd[0]->ofile, &cmd[0]->flg_app, tmp);
		if (tmp->tok == IN)
			tmp = treat_inf(&cmd[0]->ifile, tmp);
	}
	return (tmp);
}