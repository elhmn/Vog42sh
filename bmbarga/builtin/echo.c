/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:04:41 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/22 17:39:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "tools.h"

extern char	**environ;

int		ft_echo(t_cmd cmd, t_env *env);
{
	char *opt;
	char *str;
	int	flag[3]; = {0}

	str = cpy_opt(cmd.arg, &opt);
	if (!str) //if no flag
		echo_print(arg, env, flag);
	else
	{
		if (!(str = cpy_arg(str)))
			return (0);
		check_syn(&opt, &str, flag);
		echo_print(str, env, flag);
	}
	return (0);
}
