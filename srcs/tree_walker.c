/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_walker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:41:53 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/27 11:40:51 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "ftsh.h"
#include "libft.h"
#include "error_sh.h"
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

static char	*join_env(t_venv *var)
{
	int			i;
	int			j;
	char		*ccat;

	i = ft_strlen(var->var) + 2;
	if (var->val)
		i += ft_strlen(var->val);
	if (i > 300)
		return (ft_strdup("OMITTED VARIABLE"));
	if (!(ccat = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	ccat[i - 1] = 0;
	i = -1;
	while (var->var[++i])
		ccat[i] = var->var[i];
	ccat[i] = '=';
	j = -1;
	while (var->val && var->val[++j])
		ccat[++i] = var->val[j];
	ccat[++i] = 0;
	return (ccat);
}

static char	**conv_env(t_venv *env)
{
	char	**enviro;
	int		sze;
	int		i;
	t_venv	*tmp;

	sze = count_var(env) + 1;
	if (!(enviro = (char**)malloc(sizeof(char*) * (sze))))
		return (NULL);
	enviro[sze - 1] = 0;
	tmp = env;
	i = -1;
	while (tmp)
	{
		enviro[++i] = join_env(tmp);
		tmp = tmp->nxt;
	}
	return (enviro);
}

static char	**free_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env[i]);
	return (NULL);
}

void		tree_walker(t_tree *wood, t_env *env)
{
	int	ret;

	if ((env->env = conv_env(env->var)))
	{
		ret = node_run(wood->data, env);
		env->env = free_env(env->env);
		free(env->env);
		env->env = NULL;
		if (wood->data->pipe_w || (wood->left && !ret))
			tree_walker(wood->left, env);
		else if (wood->right && ret)
			tree_walker(wood->right, env);
		wood->data = free_cmd(wood->data);
	}
	else
		error(0, "Out of memory", 1);
}
