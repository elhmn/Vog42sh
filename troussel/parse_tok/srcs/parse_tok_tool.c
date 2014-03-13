/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tok_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:58:16 by troussel          #+#    #+#             */
/*   Updated: 2014/03/13 16:02:44 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftsh.h"
#include "parse_tok.h"
#include "error_sh.h"

t_tokl	*add_tokl(t_lex *lex, t_tokl *lst)
{
	t_tokl	*new;
	t_tokl	*tmp;

	if (!(new = (t_tokl*)malloc(sizeof(t_tokl))))
	{
		error(0, "Out of memory", 0);
		return (NULL);
	}
	new->lst = lex;
	new->nxt = NULL;
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}

void    rmrf_lex(t_lex **lex)
{
	char	*str;

	str = lex[0]->elm;
	lex[0]->elm = NULL;
	free(str);
	str = NULL;
	free(lex[0]);
	lex[0] = NULL;
}
