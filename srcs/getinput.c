/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 15:15:34 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 16:11:09 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcd.h"
#include "error_sh.h"
#include "libft.h"

static char		*getoldpwd(t_venv *var)
{
	t_venv	*tmp;

	tmp = var;
	while (tmp && ft_strcmp("OLDPWD", tmp->var))
		tmp = tmp->nxt;
	if (!tmp)
		error(0, "cd: OLDPWD is unset", 0);
	else
		return (ft_strdup(tmp->val));
	return (NULL);
}

static char		*usage(char *str)
{
	error(UNKOP, str, 0);
	ft_putendl("Usage: cd [directory]");
	ft_putstr("        if multiple directory is transmit, only the first");
	ft_putendl(" argument is used");
	return (NULL);
}

char			*getinput(t_cmd *dat, t_env *env)
{
	char	*target;

	target = NULL;
	if (dat->arg[1] && dat->arg[1][0] == '-' && dat->arg[1][1])
		return (usage(dat->arg[1]));
	else if (dat->arg[1] && dat->arg[1][0] == '-')
		target = getoldpwd(env->var);
	else if (dat->arg[1] && dat->arg[1][0] == '~' && dat->arg[1][1] == '/')
		target = tild_replace(target, dat->arg[1], env->var);
	else
		target = ft_strdup(dat->arg[1]);
	return (target);
}
