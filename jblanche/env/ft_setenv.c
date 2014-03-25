/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/25 15:30:08 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "error_sh.h"

static t_venv	*add_venv(char *var, char *val, t_venv *lst)
{
	t_venv	*new;
	t_venv	*tmp;

	if (!(new = (t_venv*)malloc(sizeof(t_venv))))
		error(0, "Out of memory", 1);
	new->var = ft_strdup(var);
	new->val = ft_strdup(val);
	new->nxt = NULL;
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}

int				ft_setenv(t_cmd *dat, t_env *env)
{
	t_venv		*tmp;

	tmp = NULL;
	if (!dat || !env || !env->path || !env->var || !env->env || !dat->arg[1])
		return (-1);
	tmp = env->var;
	if ((tmp = find_env_var(env->var, dat->arg[1])))
	{
		free(tmp->val);
		tmp->val = (dat->arg[2] ? ft_strdup(dat->arg[2]) : NULL);
	}
	else
		env->var = add_venv(dat->arg[1], dat->arg[2], env->var);
	return (0);
}
