/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:04:41 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/24 13:22:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh_env.h"
#include "echo.h"
//#include <stdio.h> /***************/

int		ft_echo(t_cmd *cmd, t_env *env) //change the type of the first arg in cmd
{
	char	*opt;
	char	*str;
	int		flag[3] = {0};
	int		i;
	char	*str;

	i = 1;
	while (cmd->arg[i])
	{
		str = ft_strjoin();
		i++;
	}
	if (!(str = get_arg(str, &opt)))
	{
//		printf("1-> opt = [%s] && str = [%s]\n", opt, str); /*******************/
		echo_print(str, env, flag);	
	}
	else
	{
		checksyn(&opt, &str, flag);
//		printf("2-> opt = [%s] && str = [%s]\n", opt, str); /*********************/
		echo_print(str, env, flag);
	}
	return (0);
}
