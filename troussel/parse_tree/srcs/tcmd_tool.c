/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcmd_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:40:56 by troussel          #+#    #+#             */
/*   Updated: 2014/03/03 16:06:34 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "42sh.h"
#include "parse_tree.h"

static t_cmd	*init_new(t_cmd *new)
{
	new->prg = NULL;
	new->arg = NULL;
	new->ifile = NULL;
	new->ofile = NULL;
	new->flg_app = 0;
	new->pipe_w = 0;
	new->pipe_r = 0;
	new->nxt = NULL;
	return (new);
}

t_cmd			*add_cmdd(t_cmd *lst)
{
	t_cmd	*new;
	t_cmd	*tmp;

	if (!(new = (t_cmd*)malloc(sizeof(t_cmd))))
	{
		error(0, "Out of memory", 0);
		return (NULL);
	}
	new = init_new(new);
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (new);
}
