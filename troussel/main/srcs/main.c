/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:37:29 by troussel          #+#    #+#             */
/*   Updated: 2014/03/25 18:16:06 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_sh.h"
#include "error_sh.h"
#include "get_next_line.h"
#include "libft.h"

extern char	**environ;

int		main(void)
{
	t_env		*env;
	char		*buf;
	int			getret;
	
	sig_handle();
	env = NULL;
	buf = NULL;
	env = initenv(environ, env);
	while (42)
	{
		ft_putstr("$> ");
		if ((getret = get_next_line(0, &buf)) == -1)
			error(UNDEF, "input acquisition fail hard", 1);
		else if (getret == 0)
			break ;
		if (buf && buf[0])
			env = runcore(buf, env);
		ft_strdel(&buf);
	}
	ft_putendl("exit");
	return (0);
}
