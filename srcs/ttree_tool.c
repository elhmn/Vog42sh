/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttree_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:11:52 by troussel          #+#    #+#             */
/*   Updated: 2014/03/11 17:11:09 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftsh.h"
#include "parse_tree.h"
#include "error_sh.h"
#include <stdlib.h>

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
