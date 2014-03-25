/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/18 14:29:36 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int				ft_unsetenv(t_cmd *dat, t_env *env)
{
	t_venv		*tmp;
	t_venv		*bak;

	if (!env || !env->path || !env->var || !env->env || !env->homedir)
		return (-1);
	tmp = env->var;
	while (tmp && ft_strcmp(tmp->var, dat->arg[0]))
	{
		bak = tmp;
		tmp = tmp->nxt;
	}
	if (!tmp)
		return (-1);
	else
	{
		bak->nxt = tmp->nxt;
		free(tmp->var);
		free(tmp->val);
		tmp = NULL;
	}
	return (0);
}
