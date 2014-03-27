/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/27 10:46:45 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh_env.h"

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
	if (env)
	{
		tmp = env;
		while (tmp)
		{
			ft_putstr(tmp->var);
			ft_putchar('=');
			if (tmp->val)
				ft_putendl(tmp->val);
			else
				ft_putchar('\n');
			tmp = tmp->nxt;
		}
	}
}
