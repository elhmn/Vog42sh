/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 12:51:24 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 14:09:03 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initenv.h"
#include "error_sh.h"
#include "libft.h"

static t_venv	*load_env(char **environ, t_venv *lst)
{
	int		i;

	i = -1;
	while (environ[++i])
		lst = add_venv(environ[i], lst);
	return (lst);
}

static t_path	*load_path(t_venv *varlst, t_path *lst)
{
	t_venv	*tmp;

	tmp = varlst;
	while (tmp && ft_strcmp(tmp->var, "PATH"))
		tmp = tmp->nxt;
	if (tmp)
		lst = compute_path(tmp, lst);
	return (lst);
}


static t_env	*boot_env(t_env *env)
{
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->var = NULL;
	env->path = NULL;
	env->env = NULL;
	env->last_ret = 0;
	return (env);
}

t_env			*initenv(char **environ, t_env *env)
{
	if (!(env = boot_env(env)))
		error(0, "Can't load env\n", 1);
	if (!(env->var = load_env(environ, env->var)))
		error(0, "Can't load path\n", 1);
	if (!(env->path = load_path(env->var, env->path)))
		error(0, "Can't load path\n", 1);
	return (env);
}
