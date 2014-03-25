/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 15:44:42 by troussel          #+#    #+#             */
/*   Updated: 2014/03/25 17:02:26 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "ftsh_env.h"
#include "libft.h"
#include <unistd.h>

static int	unconvertible(char *arg)
{
	if (!ft_isdigit(arg[0]) && (arg[0] != '-' || arg[0] != '+'))
		return (1);
	if ((arg[0] == '-' || arg[0] == '+') && !ft_isdigit(arg[1]))
		return (1);
	return (0);
}

int			ft_exit(t_cmd *dat, t_env *env)
{
	int	arg;

	if (!dat->arg[1] || unconvertible(dat->arg[1]))
		exit(env->last_ret);
	arg = ft_atoi(dat->arg[1]);
	if (arg > 255)
		exit(env->last_ret);
	if (arg < 0)
	{
		while (arg < 0)
			arg = 256 + arg;
	}
	exit(arg);
}
