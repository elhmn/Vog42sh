/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:04:41 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/23 14:08:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "tools.h"
//#include <stdio.h> /***************/

int		ft_echo(char *cmd, t_env *env) //change the type of the first arg in cmd
{
	char *opt;
	char *str;
	int	flag[4] = {0};

	if (!(str = get_arg(cmd, &opt)))
	{
//		printf("1-> opt = [%s] && str = [%s]\n", opt, str); /*******************/
		echo_print(cmd, env, flag);	
	}
	else
	{
		checksyn(&opt, &str, flag);
//		printf("2-> opt = [%s] && str = [%s]\n", opt, str); /*********************/
		echo_print(str, env, flag);
	}
	return (0);
}
