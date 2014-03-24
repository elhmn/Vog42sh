/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:56:24 by troussel          #+#    #+#             */
/*   Updated: 2014/03/24 14:56:27 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <stdlib.h>

static t_tree	*free_tree(t_tree *lst)
{
	if (!lst)
		return (NULL);
	else if (lst->left)
		lst->left = free_tree(lst->left);
	else if (lst->right)
		lst->right = free_tree(lst->right);
	free(lst);
	lst = NULL;
	return (NULL);
}

t_for			*free_for(t_for *lst)
{
	if (!lst)
		return (NULL);
	else if (lst->nxt && lst->nxt->nxt)
		lst->nxt = free_for(lst->nxt);
	lst->wood = free_tree(lst->wood);
	free(lst->wood);
	free(lst);
	lst = NULL;
	return (NULL);
}
