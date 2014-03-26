/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/26 18:30:10 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh_env.h"
#include "printf.h"

t_venv				*find_env_var(t_venv *env, char *var)
{
	t_venv			*tmp;

	tmp = env;
	while (tmp && ft_strcmp(tmp->var, var))
		tmp = tmp->nxt;
	return (tmp);
}

void				print_env(t_venv *env)
{
	t_venv			*tmp;

	tmp = NULL;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		ft_printf("%s=%s\n", tmp->var, tmp->val);
		tmp = tmp->nxt;
	}
	return (0);
}
