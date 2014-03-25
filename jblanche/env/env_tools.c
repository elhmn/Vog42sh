/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/25 14:18:19 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_venv				*find_env_var(t_venv *env, char *var)
{
	t_venv			*tmp;

	tmp = env;
	while (tmp && ft_strcmp(tmp->var, var))
		tmp = tmp->nxt;
	return (tmp);
}
