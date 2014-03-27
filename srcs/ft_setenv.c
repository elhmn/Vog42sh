/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/27 12:15:43 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "error_sh.h"
#include "ft_env.h"

static t_venv	*add_venv(char *var, char *val, t_venv *lst)
{
	t_venv	*new;
	t_venv	*tmp;

	if (!(new = (t_venv*)malloc(sizeof(t_venv))))
		error(0, "Out of memory", 1);
	new->var = ft_strdup(var);
	new->val = (val ? ft_strdup(val) : NULL);
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
	if (!dat || !env)
		return (-1);
	if (!dat->arg[1])
	{
		print_env(env->var);
		return (0);
	}
	tmp = env->var;
	if ((tmp = find_env_var(env->var, dat->arg[1])))
	{
		if (tmp->val)
			free(tmp->val);
		tmp->val = (dat->arg[2] ? ft_strdup(dat->arg[2]) : NULL);
	}
	else
		env->var = add_venv(dat->arg[1], dat->arg[2], env->var);
	return (0);
}
