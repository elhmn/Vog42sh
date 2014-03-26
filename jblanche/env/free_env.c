/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:15:29 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/26 18:31:42 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <stdlib.h>

static void free_path(t_path *path)
{
	if (path)
	{
		free(path->dir);
		if (path->next)
			free_var(varenv->next);
		free(path);
	}
}

void		free_var(t_venv *varenv)
{
	if (varenv)
	{
		free(varenv->val);
		free(varenv->var);
		if (varenv->next)
			free_var(varenv->next);
		free(varenv);
	}
}

void		free_env(t_env *env)
{
	free_path(env->path);
	free_var(env->var);
	free(env);
}
