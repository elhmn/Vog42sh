/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 15:44:42 by troussel          #+#    #+#             */
/*   Updated: 2014/03/25 17:43:35 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "ftsh_env.h"
#include "libft.h"
#include "error_sh.h"
#include <unistd.h>

static int	chk_max_val(char *str)
{
	if (str[0] - '0' > 2)
		return (1);
	else if (str[0] - '0' == 2 && str[1] - '0' > 1)
		return (1);
	else if (str[1] - '0' == 1 && str[2] - '0' > 4)
		return (1);
	else if (str[2] - '0' == 4 && str[3] - '0' > 7)
		return (1);
	else if (str[3] - '0' == 7 && str[4] - '0' > 4)
		return (1);
	else if (str[4] - '0' == 4 && str[5] - '0' > 8)
		return (1);
	else if (str[5] - '0' == 8 && str[6] - '0' > 3)
		return (1);
	else if (str[6] - '0' == 3 && str[7] - '0' > 6)
		return (1);
	else if (str[7] - '0' == 6 && str[8] - '0' > 4)
		return (1);
	else if (str[8] - '0' == 4 && str[9] - '0' > 7)
		return (1);
	return (0);
}

static int	chkval(char *str)
{
	if (str[0] == '-')
		str = &str[1];
	if (ft_strlen(str) > 10)
		return (1);
	else if (ft_strlen(str) == 10)
	{
		if (chk_max_val(str))
			return (1);
	}
	return (0);
}

static int	unconvertible(char *arg)
{
	if (!ft_isdigit(arg[0]) && arg[0] != '-' && arg[0] != '+')
	{
		error(0, "exit: numeric argument required", 0);
		return (1);
	}
	if ((arg[0] == '-' || arg[0] == '+') && !ft_isdigit(arg[1]))
	{
		error(0, "exit: numeric argument required", 0);
		return (1);
	}
	if (chkval(arg))
	{
		error(0, "exit: can't use extreme value", 0);
		return (1);
	}
	return (0);
}

int			ft_exit(t_cmd *dat, t_env *env)
{
	int	arg;

	if (!dat->pipe_w && !dat->pipe_r)
	ft_putendl("exit");
	if (!dat->arg[1] || unconvertible(dat->arg[1]))
		exit(env->last_ret);
	arg = ft_atoi(dat->arg[1]);
	if (arg > 255)
		exit(255);
	if (arg < 0)
	{
		while (arg < 0)
			arg = 256 + arg;
	}
	exit(arg);
}
