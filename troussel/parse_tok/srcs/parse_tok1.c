/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tok1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:56:28 by troussel          #+#    #+#             */
/*   Updated: 2014/02/28 17:52:32 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftsh.h"
#include "parse_tok.h"
#include <unistd.h>

static t_lex	*def_newlst(t_lex *tmp)
{
	if (!(tmp->nxt))
		return (NULL);
	if (!(tmp->nxt->nxt))
		return (NULL);
	return (tmp->nxt->nxt);
}


t_tokl			*parse_tok(t_lex *lexlst)
{
	t_tokl	*tokl;
	t_lex	*cp_llst;
	t_lex	*tmp;

	if (!lexlst)
		return (NULL);
	tokl = NULL;
	while (lexlst)
/*tant que lexlst*/
	{
	/*copie du ptr lexlst*/
		cp_llst = lexlst;
	/*recherche du token SEMIC*/
		tmp = lexlst;
		while (tmp->nxt && tmp->nxt->tok != SEMIC)
			tmp = tmp->nxt;
	/*Redef de lst apres le token SEMIC*/
		lexlst = def_newlst(tmp);
	/*pop de SEMIC*/
		if (tmp->nxt)
			rmrf_lex(&tmp->nxt);
	/*Set du ptr avant SEMIC a NULL*/
		tmp->nxt = NULL;
	/*ajout de la copie du ptr lst dans la liste de tokl*/
		tokl = add_tokl(cp_llst, tokl);
	}
	return (tokl);
}
