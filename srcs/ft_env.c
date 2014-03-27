/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 15:47:38 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/27 11:42:06 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "libft.h"
#include "main_sh.h"

static int		ft_env_cmd(t_env *tmp, t_cmd *dat, int i)
{
	char		*cmd;
	int			flg;

	cmd = NULL;
	flg = 0;
	while (dat->arg[i])
	{
		cmd = (cmd ? ft_strjoin(cmd, dat->arg[i]) : ft_strdup(dat->arg[i]));
		cmd = ft_strjoin(cmd, " ");
		flg++;
		i++;
	}
	cmd = ft_strtrim(cmd);
	if (flg)
	{
		tmp = runcore(cmd, tmp);
		free(cmd);
	}
	else if (tmp && tmp->var)
		print_env(tmp->var);
	free_env(tmp);
	return (0);
}

static char		**free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
	return (NULL);
}

static int		ft_env_varval(t_cmd *dat, t_env *tmp, int i)
{
	char		**varval;
	t_venv		*var;

	varval = NULL;
	while (dat->arg[i] && dat->arg[i][0] != '=' && ft_strchr(dat->arg[i], '='))
	{
		var = NULL;
		varval = ft_strsplit(dat->arg[i], '=');
		if (!varval[0])
			break ;
		var = find_env_var(tmp->var, varval[0]);
		if (!var)
			tmp->var = app_venv(varval[0], varval[1], tmp->var);
		else
		{
			if (var->val)
				free(var->val);
			var->val = (varval[1] ? ft_strdup(varval[1]) : NULL);
		}
		i++;
	}
	if (i != 1 && ft_strcmp(dat->arg[1], "-i"))
		varval = free_tab(varval);
	return (ft_env_cmd(tmp, dat, i));
}

int				ft_env(t_cmd *dat, t_env *env)
{
	t_env		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
	if (!dat || !dat->arg)
		return (-1);
	if (!dat->arg[1])
	{
		print_env(env->var);
		return (0);
	}

	if (ft_strcmp(dat->arg[1], "-i"))
		tmp = envdup(env, 0);
	else
	{
		tmp = envdup(env, 1);
		++i;
	}
	return (ft_env_varval(dat, tmp, i));
}
