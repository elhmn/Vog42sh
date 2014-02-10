/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 13:40:23 by jblanche          #+#    #+#             */
/*   Updated: 2014/01/04 12:17:18 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void		ft_env(char **str, char **enviro)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (str[1])
	{
		while (str[i] && (strchr(str[i], '=')) != NULL)
			ft_chg_str_in_tab(enviro, str[i++]);
		if (i == 1)
		{
			ft_error(10, str[i]);
			return ;
		}
		if (str[i])
		{
			ft_error(4, "env");
			return ;
		}
	}
	ft_puttab((const char **)enviro);
}

static void		ft_setenv(char *name, char *value, char **enviro)
{
	if (name || value)
	{
		ft_error(5, "setenv");
		return ;
	}
	ft_puttab((const char **)enviro);
}

static void		ft_cd(char *path, char **enviro)
{
	(void)path;
	(void)enviro;
	ft_error(6, "cd");
	return ;
}

static void		ft_unsetenv(char **str, char **enviro)
{
	if (!str[1])
		ft_error(2, "unsetenv");
	else
		ft_error(7, "unsetenv");
	return ;
	enviro[0][0] = 'u';
}

int				ft_env_main(char **str, char **enviro)
{
	if (ft_strcmp(str[0], "cd") == 0)
		ft_cd(str[1], enviro);
	else if (ft_strcmp(str[0], "setenv") == 0)
	{
		if (str[3])
			ft_error(1, "setenv");
		else
			ft_setenv(str[1], str[2], enviro);
	}
	else if (ft_strcmp(str[0], "unsetenv") == 0)
		ft_unsetenv(str, enviro);
	else if (ft_strcmp(str[0], "env") == 0)
		ft_env(str, enviro);
	else
		return (1);
	return (0);
}
