/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:19:17 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/24 16:36:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initenv.h"
#include "echo.h"
#include "libft.h"
//#include <stdio.h> /***************/

extern char		**environ;

int		main(int ac, char **av)
{
	t_env 	*env;
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->arg = av;
	env = NULL;
	if (ac)
	{
		env = initenv(environ, env);
		ft_echo(cmd, env);
	}
	//else
	//	ft_putstr("To few argument\n");
	return (0);
}
