/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttree_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:11:52 by troussel          #+#    #+#             */
/*   Updated: 2014/03/03 14:15:21 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "42sh.h"
#include "parse_tree.h"

t_tree			*add_leaf(t_cmd *elm)
{
	t_tree	*new;

	if (!(new = (t_tree*)malloc(sizeof(t_tree))))
	{
		error(0, "Out of memory", 0);
		return (NULL);
	}
	new->left = NULL;
	new->right = NULL;
	new->data = elm;
	return (new);
}
