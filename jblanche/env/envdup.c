/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 16:52:18 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 18:24:39 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "error_sh.h"
#include "libft.h"
#include <stdlib.h>

t_venv			*app_venv(char *var, char *val, t_venv *lst)
{
	t_venv	*new;
	t_venv	*lst;

	if (!(new = (t_venv*)malloc(sizeof(t_venv))))
		error(O, "Out of memory", 1);
	new->var = ft_strdup(var);
	if (!val)
		new->val = NULL;
	else
		new->val = ft_strdup(val);
	new->nxt = NULL;
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}

static t_venv	*copy_tvenv(t_venv *ori)
{
	t_venv	*lst;
	t_venv	*tmp;

	if (!ori)
		return (NULL);
	lst = NULL;
	tmp = ori;
	while (tmp)
	{
		lst = app_venv(tmp->var, tmp->val, lst);
		tmp = tmp->nxt;
	}
	return (lst);
}

static t_path	*add_path(char *dir, t_path *lst)
{
	t_path	*new;
	t_path	*tmp;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		error(0, "Out of memory", 1);
	new->nxt = NULL;
	if (!dir)
		new->dir = NULL;
	else
		new->dir = ft_strdup(dir);
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}

static t_path	*copy_tpath(t_path *ori)
{
	t_path	*lst;
	t_path	*tmp;

	if (!ori)
		return (NULL);
	lst = NULL;
	tmp = ori;
	while (tmp)
	{
		lst = app_path(tmp->dir, lst);
		tmp = tmp->nxt;
	}
	return (lst);
}

t_env			*envdup(t_env *ori)
{
	t_env	*envcpy;

	if (!(envcpy = (t_env*)malloc(t_env)))
		error(O, "Out of memory", 1);
	env->var = NULL;
	env->path = NULL;
	env->env = NULL;
	env->last_ret = 0;
	envcpy = initcpy(envcpy);
	envcpy->var = copy_tvenv(ori->var);
	envcpy->path = copy_tpath(ori->path);
	return (envcpy);
}
