/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/26 15:33:21 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_env	*ft_clear(t_venv *tmp, t_venv *bak, t_env *env)
{
	if (bak)
		bak->nxt = tmp->nxt;
	if (!bak)
		env->var = env->var->nxt;
	free(tmp->var);
	free(tmp->val);
	free(tmp);
	tmp = NULL;
	bak = NULL;
	return (env);
}

int				ft_unsetenv(t_cmd *dat, t_env *env)
{
	t_venv		*tmp;
	t_venv		*bak;
	int			i;

	tmp = NULL;
	bak = NULL;
	if (!env || !env->path || !env->var || !env->env)
		return (-1);
	i = 0;
	while (dat->arg[++i])
	{
		tmp = env->var;
		while (tmp && ft_strcmp(tmp->var, dat->arg[i]))
		{
			bak = tmp;
			tmp = tmp->nxt;
		}
		if (tmp)
			env = ft_clear(tmp, bak, env);
		bak = NULL;
	}
	return (0);
}
