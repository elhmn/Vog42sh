/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:28:09 by troussel          #+#    #+#             */
/*   Updated: 2014/03/27 14:37:20 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "ftsh_env.h"
#include "runcore.h"
#include <stdlib.h>

static t_lex	*free_lex(t_lex *lst)
{
	char	*str;

	if (!lst)
		return (NULL);
	if (lst->nxt)
		lst->nxt = free_lex(lst->nxt);
	str = lst->elm;
	free(str);
	str = NULL;
	free(lst);
	lst = NULL;
	return (NULL);
}

static t_tokl	*free_tokl(t_tokl *lst)
{
	if (!lst)
		return (NULL);
	if (lst->nxt)
		lst->nxt = free_tokl(lst->nxt);
	lst->lst = free_lex(lst->lst);
	free(lst);
	lst = NULL;
	return (NULL);
}

static t_for	*parse_it(t_lex *lex_tree, t_for *for_tree)
{
	t_tokl		*tokl_tree;

	if (!parse_syn(lex_tree))
		return (NULL);
	if (!(tokl_tree = parse_tok(lex_tree)))
		return (NULL);
	for_tree = parse_for(tokl_tree);
	tokl_tree = free_tokl(tokl_tree);
	return (for_tree);
}

t_env			*runcore(const char *input, t_env *env)
{
	t_lex		*lex_tree;
	t_for		*for_tree;
	t_for		*for_walker;

	for_tree = NULL;
	lex_tree = lexer((char*)input);
	if (!(for_tree = parse_it(lex_tree, for_tree)))
		return (env);
	for_walker = for_tree;
	while (for_walker)
	{
		tree_walker(for_walker->wood, env);
		for_walker = for_walker->nxt;
	}
	if (!for_tree && lex_tree)
		lex_tree = free_lex(lex_tree);
	else
		for_tree = free_for(for_tree);
	return (env);
}
