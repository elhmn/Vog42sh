/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tok_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:58:16 by troussel          #+#    #+#             */
/*   Updated: 2014/02/28 17:26:39 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "42sh.h"
#include "parse_tok.h"
#include "error_sh.h"

t_tokl	add_tokl(t_lex *lex, t_tokl *lst)
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

void    rmrf_lex(t_lex *lex)
{
	ft_strdel(lex->elm);
	free(lex);
	lex = NULL;
}
