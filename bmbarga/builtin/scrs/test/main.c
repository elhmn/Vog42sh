/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:19:17 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/23 14:02:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initenv.h"
#include "tools.h"
#include "libft.h"
//#include <stdio.h> /***************/

extern char		**environ;

int		main(int ac, char **av)
{
	t_env 	*env;
	int		i;
	char 	*str;

	env = NULL;
	str = NULL;
	i = 1;
	if (ac > 1)
	{
		env = initenv(environ, env);
		while (i < ac)
		{
			str = ft_strjoin(str, av[i]);
			i++;
//			printf("str[ %d ] =[%s]\n", i, str); /*******************/
		}
		ft_echo(str, env);
	}
	else
		ft_putstr("To few argument\n");
	return (0);
}
