/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:19:17 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/22 19:13:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initenv.h"
#include "tools.h"
#include "libft.h"

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
		}
		ft_echo(str, env);
	}
	ft_putstr("To few argument\n");
	return (0);
}
