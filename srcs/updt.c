/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:46:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 13:11:29 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftcd.h"
#include "libft.h"
#include "error_sh.h"
#include <stdlib.h>
#include <unistd.h>

static t_venv	*findenv(char *query, t_venv *lst)
{
	t_venv		*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp && ft_strcmp(query, tmp->var))
		tmp = tmp->nxt;
	return (tmp);
}

static t_venv	*envbourne(char *name, t_venv *lst)
{
	t_venv		*new;
	t_venv		*tmp;

	if (!(new = (t_venv*)malloc(sizeof(t_venv))))
		error(0, "Out of memory", 1);
	new->var = name;
	new->val = NULL;
	new->nxt = NULL;
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}

t_env			*updt_oldpwd(char *oldpwd, t_env *env)
{
	t_venv		*old;
	t_venv		*pwd;
	int			flg;

	flg = 0;
	if (!oldpwd)
	{
		if (!(pwd = findenv("PWD", env->var)) && ++flg)
		{
			error(UNDEF, "cd: can't set OLDPWD", 0);
			return (env);
		}
		else
			oldpwd = pwd->var;
	}
	if (!(old = findenv("OLDPWD", env->var)))
		env->var = envbourne(ft_strdup("OLDPWD"), env->var);
	if (!old)
		old = findenv("OLDPWD", env->var);
	if (old->val)
		free(old->val);
	old->val = ft_strdup(oldpwd);
	if (!flg)
		free(oldpwd);
	return (env);
}

t_env			*updt_pwd(char *target, t_env *env)
{
	t_venv		*pwd;
	char		*apl;
	size_t		size;

	size = pathconf(".", _PC_PATH_MAX);
	apl = NULL;
	if (!(pwd = findenv("PWD", env->var)))
		env->var = envbourne(ft_strdup("PWD"), env->var);
	if (!pwd)
		pwd = findenv("PWD", env->var);
	if (pwd->val)
		free(pwd->val);
	if ((apl = getcwd(apl, size)))
		pwd->val = apl;
	else
		pwd->val = ft_strdup(target);
	return (env);
}

void			show_change(t_env *env)
{
	t_venv		*pwd;

	pwd = findenv("PWD", env->var);
	ft_putendl(pwd->val);
}
