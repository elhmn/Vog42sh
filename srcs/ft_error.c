/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 15:13:51 by jblanche          #+#    #+#             */
/*   Updated: 2014/01/04 11:59:38 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static void		ft_error_aux(int code, char *str)
{
	if (code == 10)
	{
		ft_puterror("env: ");
		ft_puterror(str);
		ft_puterror(": No such file or directory\n");
	}
	kill(1, SIGUSR2);
}

void			ft_error(int code, char *str)
{
	if (code < 10)
	{
		ft_puterror("sh: ");
		ft_puterror(str);
	}
	if (code == 0)
		ft_puterror(": command not found\n");
	else if (code == 1)
		ft_puterror(": Too many arguments.\n");
	else if (code == 2)
		ft_puterror(": Too few arguments.\n");
	else if (code == 3)
		ft_puterror(": Adding environment variable is not yet supported.\n");
	else if (code == 4)
		ft_puterror(": Utilities are not yet supported.\n");
	else if (code == 5)
		ft_puterror(": setenv is not yet supported.\n");
	else if (code == 6)
		ft_puterror(": cd is not yet supported.\n");
	else if (code == 7)
		ft_puterror(": unsetenv is not yet supported.\n");
	else if (code == 7)
		ft_puterror(": permission denied.\n");
	ft_error_aux(code, str);
}
