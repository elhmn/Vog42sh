/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tok1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:56:28 by troussel          #+#    #+#             */
/*   Updated: 2014/03/11 15:51:08 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftsh.h"
#include "parse_tok.h"
#include <unistd.h>
#include <stdlib.h>

static t_lex	*def_newlst(t_lex *tmp)
{
	if (!(tmp->nxt))
		return (NULL);
	if (!(tmp->nxt->nxt))
		return (NULL);
	return (tmp->nxt->nxt);
}

static t_lex	*clear_void(t_lex *lst)
{
	t_lex	*tmp;

	tmp = lst;
	while (tmp->nxt->tok != VOID)
		tmp = tmp->nxt;
	free(tmp->nxt);
	tmp->nxt = NULL;
	return (lst);
}

t_tokl			*parse_tok(t_lex *lexlst)
{
	t_tokl	*tokl;
	t_lex	*cp_llst;
	t_lex	*tmp;

	lexlst = clear_void(lexlst);
	if (!lexlst)
		return (NULL);
	tokl = NULL;
	while (lexlst)
	{
		cp_llst = lexlst;
		tmp = lexlst;
		while (tmp->nxt && tmp->nxt->tok != SEMIC)
			tmp = tmp->nxt;
		lexlst = def_newlst(tmp);
		if (tmp->nxt)
			rmrf_lex(&tmp->nxt);
		tmp->nxt = NULL;
		tokl = add_tokl(cp_llst, tokl);
	}
	return (tokl);
}
