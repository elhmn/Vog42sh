/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/25 15:16:51 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "initenv.h"

int				ft_setenv(t_cmd *dat, t_env *env)
{
	t_venv		*tmp;
	char		*arg;

	tmp = NULL;
	arg = NULL;
	if (!dat || !env || !env->path || !env->var || !env->env || !dat->arg[1])
		return (-1);
	tmp = env->var;
	if ((tmp = find_env_var(env->var, dat->arg[1])))
	{
		free(tmp->val);
		tmp->val = (dat->arg[2] ? ft_strdup(dat->arg[2]) : NULL);
	}
	else
	{
		arg = ft_strdup(dat->arg[1]);
		arg = ft_strjoin(arg, "=");
		arg = (dat->arg[2] ? ft_strjoin(arg, dat->arg[2]) : arg);
		env->var = add_venv(arg, env->var);
	}
	free(arg);
	return (0);
}
