/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tild_replace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 15:49:01 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 16:19:41 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"

static char	*replace(char *target, char *home, char *arg, int sze)
{
	int	i;
	int	j;

	if (!(target = (char*)malloc(sizeof(char) * sze)))
		error(0, "Out of memory", 1);
	target[sze - 1] = 0;
	i = -1;
	while (home[++i])
		target[i] = home[i];
	j = 0;
	while (arg[++j])
		target[i + j - 1] = arg[j];
	return (target);
}

char		*tild_replace(char *target, char *arg, t_venv *var)
{
	t_venv	*tmp;
	int		sze;

	tmp = var;
	while (tmp && ft_strcmp("HOME", var->var))
		tmp = tmp->nxt;
	if (!tmp)
	{
		error(0, "cd: HOME is unset", 0);
		return (NULL);
	}
	sze = ft_strlen(arg) + ft_strlen(tmp->val);
	target = replace(target, tmp->val, arg, sze);
	return (target);
}
