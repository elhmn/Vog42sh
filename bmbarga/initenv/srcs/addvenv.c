/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addvenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 13:17:36 by troussel          #+#    #+#             */
/*   Updated: 2014/03/22 18:48:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
//#include "libft.h"
#include "error_sh.h"
#include <stdlib.h>

static char		*varname(char const *var, char *vvar)
{
	int	i;

	i = -1;
	while (var[++i] && var[i] != '=')
		;
	if (!i)
		return (NULL);
	if (!(vvar = (char*)malloc(sizeof(char) * (i + 1))))
		error(0, "Out of memory", 1);
	vvar[i] = 0;
	i = -1;
	while (var[++i] && var[i] != '=')
		vvar[i] = var[i];
	return (vvar);
}

static char		*varval(char const *var, char *varname, char *varval)
{
	int	i;

	i = ft_strlen(varname);
	if (!var[i + 1])
		return (NULL);
	varval = ft_strdup(&var[i + 1]);
	return (varval);
}

static t_venv	*init_var(char const *var, t_venv *new)
{
	new->var = NULL;
	new->var = varname(var, new->var);
	new->val = NULL;
	new->val = varval(var, new->var, new->val);
	new->nxt = NULL;
	return (new);
}

t_venv			*add_venv(char const *var, t_venv *lst)
{
	t_venv	*new;
	t_venv	*tmp;

	if (!(new = (t_venv*)malloc(sizeof(t_venv))))
		error(0, "Out of memory", 1);
	new = init_var(var, new);
	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->nxt)
		tmp = tmp->nxt;
	tmp->nxt = new;
	return (lst);
}
