/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gethomedir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/18 15:56:42 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcd.h"
#include "libft.h"

char	*gethomedir(t_env *env)
{
	t_venv		*tmp;

	if (!env->homedir && !env->var)
	{
		error(0, "Empty environment", 0);
		return (NULL);
	}
	else if (env->homedir)
		return (ft_strdup(env->homedir));
	tmp = env->var;
	while (tmp && !ft_strcmp("HOME", tmp->var))
		tmp = tmp->nxt;
	if (tmp && tmp->val)
		return (ft_strdup(tmp->val));
	error(0, "cd: Can't load home directory", 0);
	return (NULL);
}
