/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 13:20:20 by troussel          #+#    #+#             */
/*   Updated: 2014/03/18 16:10:21 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "error_sh.h"
#include <stdlib.h>

static t_for	*init_tree(t_tree *wood, t_for *new)
{
	new->wood = wood;
	new->nxt = NULL;
	return (new);
}

t_for			*add_tree(t_tree *wood, t_for *lst)
{
	t_for	*tmp;
	t_for	*new;

	if (!(new = (t_for*)malloc(sizeof(t_for) * 1)))
	{
		error(0, "Out of memory", 0);
		return (NULL);
	}
	new = init_tree(wood, new);
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}

t_for			*parse_for(t_tokl *lst)
{
	t_tokl	*tmp;
	t_for	*forest;
	t_tree	*atree;

	tmp = lst;
	forest = NULL;
	atree = NULL;
	while (tmp)
	{
		if (!(atree = parse_tree(tmp->lst, NULL, 0)))
			return (NULL);
		if (!(forest = add_tree(atree, forest)))
			return (NULL);
		tmp = tmp->nxt;
	}
	return (forest);
}
