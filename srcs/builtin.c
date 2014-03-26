/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:30:22 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 14:42:28 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh.h"
#include "ftsh_env.h"
#include "ftsh_builtin.h"

int	isbuiltin(t_cmd *dat)
{
	if (!dat->prg)
		return (0);
	if (!ft_strcmp(dat->prg, "cd"))
		return (1);
	else if (!ft_strcmp(dat->prg, "echo"))
		return (1);
	else if (!ft_strcmp(dat->prg, "exit"))
		return (1);
	else if (!ft_strcmp(dat->prg, "env"))
		return (1);
	else if (!ft_strcmp(dat->prg, "setenv"))
		return (1);
	else if (!ft_strcmp(dat->prg, "unsetenv"))
		return (1);
	else
		return (0);
}

int	builtin(t_cmd *dat, t_env *env)
{
	if (!ft_strcmp(dat->prg, "cd"))
		return (ft_cd(dat, env));
	else if (!ft_strcmp(dat->prg, "echo"))
		return (ft_echo(dat, env));
	else if (!ft_strcmp(dat->prg, "exit"))
		return (ft_exit(dat, env));
	else if (!ft_strcmp(dat->prg, "env"))
		return (ft_env(dat, env));
	else if (!ft_strcmp(dat->prg, "setenv"))
		return (ft_setenv(dat, env));
	else if (!ft_strcmp(dat->prg, "unsetenv"))
		return (ft_unsetenv(dat, env));
	else
		return (1);
}
