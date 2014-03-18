/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_walker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:41:53 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/12 14:28:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "ftsh.h"

void	tree_walker(t_tree *wood, t_env *env)
{
	t_tree	*tmp;
	int		ret;

	tmp = wood;
	if (tmp)
	{
		while (tmp->right || tmp->left)
		{
			con_env(t_env);
			ret = node_run(tmp->data, env);
			if (tmp->data->pipe_w || (ret == 0 && tmp->left))
				tmp = tmp->left;
			else if (ret && tmp->right)
				tmp = tmp->right;
			free_env(t_env);
		}
		con_env(t_env);
		node_run(tmp->data, env);
		free_env(t_env);
	}
}
