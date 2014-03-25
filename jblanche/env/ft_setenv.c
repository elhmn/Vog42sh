/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/25 14:46:04 by jblanche         ###   ########.fr       */
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
	if (!dat || !env || !env->path || !env->var || !env->env || !dat->arg[1]
		|| !dat->arg[2])
		return (-1);
	i = 0;
	if (tmp = find_env_var(env, dat->arg[1]))
	{
		free(tmp->var->val);
		tmp->var->val = ft_strdup(dat->arg[2]);
	}
	else
	{
		arg = (char *)malloc(sizeof(arg) * ft_strlen(dat->arg[1]));
		arg = ft_strdup(dat->arg[1]);
		arg = ft_strjoin(arg, '=');
		arg = ft_strjoin(arg, dat->arg[2]);
		env = add_venv(arg, env);
	}
	return (0);
}
