/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 13:50:00 by troussel          #+#    #+#             */
/*   Updated: 2014/03/23 13:06:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "libft.h"
#include "error_sh.h"
#include <stdlib.h>

static t_path	*init_dir(char *dir, t_path *new)
{
	int	i;

	i = ft_strlen(dir);
	if (!(new->dir = (char*)malloc(sizeof(char) * (i + 2))))
		error(0, "Out of memory", 1);
	new->dir[i] = '/';
	new->dir[i + 1] = 0;
	i = -1;
	while (dir[++i])
		new->dir[i] = dir[i];
	new->nxt = NULL;
	return (new);
}

static t_path	*add_path(char *dir, t_path *lst)
{
	t_path	*new;
	t_path	*tmp;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		error(0, "Out of memory", 1);
	new = init_dir(dir, new);
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}

t_path			*compute_path(t_venv *pathvar, t_path *lst)
{
	char	**splt;
	int		i;

	splt = NULL;
	if (!pathvar->val)
		return (NULL);
	splt = ft_strsplit(pathvar->val, ':');
	if (!splt[0] || !splt)
		return (NULL);
	i = -1;
	while (splt[++i])
		lst = add_path(splt[i], lst);
	i = -1;
	while (splt[++i])
		free(splt[i]);
	free(splt[i]);
	free(splt);
	return (lst);
}
