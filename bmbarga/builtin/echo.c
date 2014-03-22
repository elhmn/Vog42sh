/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:04:41 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/22 20:57:56 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "tools.h"


int		ft_echo(char *cmd, t_env *env) //change the type of the first arg in cmd
{
	char *opt;
	char *str;
	int	flag[3] = {0};

	if (!(str = get_arg(cmd, &opt)))
		echo_print(cmd, env, flag);	
	else
		echo_print(str, env, flag);
	return (0);
}
