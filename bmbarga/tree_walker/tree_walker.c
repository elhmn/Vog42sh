/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_walker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:41:53 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/18 15:58:41 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "ftsh.h"
#include "libft.h"
#include <stdlib.h>

static int	count_var(t_venv *env)
{
	t_venv	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		++i;
		tmp = tmp->nxt;
	}
	return (i);
}

static char	**conv_env(t_venv *env)
{
	char	**enviro;
	int		sze;
	int		i;
	t_venv	*tmp;
	char	*str;

	sze = count_var(env);
	if (!(enviro = (char**)malloc(sizeof(char*) * (sze + 1))))
		return (NULL);
	enviro[sze] = 0;
	tmp = env;
	i = -1;
	while (tmp)
	{
		str = ft_strjoin(tmp->var, "=");
		enviro[i] = ft_strjoin(str, tmp->val);
		ft_strdel(&str);
		tmp = tmp->nxt;
	}
	return (enviro);
}

static char	**free_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		free(env[i]);
		env[i] = NULL;
	}
	free(env[i]);
	env[i] = NULL;
	free(env);
	env = NULL;
	return (NULL);
}

void		tree_walker(t_tree *wood, t_env *env)
{
	t_tree	*tmp;
	int		ret;
	int		flg;

	flg = 0;
	tmp = wood;
	if (tmp)
	{
		while (tmp->right || tmp->left)
		{
			if (!(env->env = conv_env(env->var)))
				break ;
			ret = node_run(tmp->data, env);
			env->env = free_env(env->env);
			if (tmp->data->pipe_w || (ret == 0 && tmp->left))
				tmp = tmp->left;
			else if (ret && tmp->right)
				tmp = tmp->right;
			else if (++flg)
				break ;
		}
		if (!flg)
		{
			env->env = conv_env(env->var);
			node_run(tmp->data, env);
			env->env = free_env(env->env);
		}
	}
}
