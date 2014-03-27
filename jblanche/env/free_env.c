/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:15:29 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/27 11:09:27 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <stdlib.h>

static void free_path(t_path *path)
{
	if (path)
	{
		free(path->dir);
		if (path->nxt)
			free_path(path->nxt);
		free(path);
	}
}

void		free_var(t_venv *varenv)
{
	if (varenv)
	{
		free(varenv->val);
		free(varenv->var);
		if (varenv->nxt)
			free_var(varenv->nxt);
		free(varenv);
	}
}

void		free_env(t_env *env)
{
	if (env)
	{
		if (env->path)
			free_path(env->path);
		if (env->var)
			free_var(env->var);
		free(env);
	}
}
