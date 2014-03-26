/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 15:47:38 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/26 18:36:29 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

/*
** tester si SF avec env HOME=./dsf=sfees
*/

static int		ft_env_cmd(t_env *tmp, t_cmd *dat, int i)
{
	char		*cmd;

	cmd = NULL;
	while (dat->arg[i])
	{
		cmd = ft_strjoin(cmd, dat->arg[i]);
		cmd = ft_strjoin(cmd, " ");
		i++;
	}
	cmd = ft_strtrim(cmd);
	tmp = runcore(cmd, tmp);
	free(cmd);
	free_env(dup);
	return (0);
}

static int		ft_env_varval(t_cmd *dat, t_env *tmp)
{
	char		**varval;
	int			i;

	i = 1;
	varval = NULL;
	while (ft_strchr(dat->arg[i], '='))
	{
		varval = ft_strsplit(dat->arg[i], '=');
		var = find_env_var(tmp, varval[0]);
		if (!var)
			tmp->var = app_venv(varval[0], varval[1], tmp->var);
		else
		{
			if (var->val)
				free(var->val);
			var->val = ft_strdup(varval[1]);
		}
		i++;
	}
	free(varval[0]);
	free(varval[1]);
	return (ft_env_cmd(dat, i));
}

int				ft_env(t_cmd *dat, t_env *env)
{
	t_env		*tmp;

	tmp = NULL;
	if (!dat || !dat->arg)
		return (-1);
	if (!dat->arg[1])
	{
		print_env(env);
		return (0);
	}
	tmp = envdup(env);
	if (!ft_strcmp(dat->arg[1], "-i"))
	{
		free_var(tmp->var);
		tmp->var = NULL;
		i++;
	}
	return (ft_env_varval(dat, tmp));
}
