/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:37:29 by troussel          #+#    #+#             */
/*   Updated: 2014/02/25 15:13:28 by troussel         ###   ########.fr       */
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
	
	sig_handle();
	env = NULL;
	buf = NULL;
	env = initenv(environ, env);
	while (42)
	{
		ft_putstr("$> ");
		if (get_next_line(0, &buf) == -1)
			error(UNDEF, "input acquisition fail hard", 1);
		if (buf && buf[0])
			env = runcore(buf, env);
		ft_strdel(&buf);
	}
	return (0);
}
