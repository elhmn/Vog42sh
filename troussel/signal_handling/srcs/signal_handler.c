/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:23:31 by troussel          #+#    #+#             */
/*   Updated: 2014/03/25 17:03:38 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

static void	sig_resp(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		ft_putstr("\nexit\n");
		exit(0);
	}
	else if (sig == SIGSEGV || sig == SIGBUS)
	{
		ft_putstr("something went wrong, escape sequence initiate\n");
		exit(-1);
	}
	else if (sig == SIGINFO)
		ft_putstr("$> ");
	else
		ft_putstr("\n$> ");
}

void		sig_handle(void)
{
	signal(SIGINT, sig_resp);
	signal(SIGINFO, sig_resp);
	signal(SIGUSR1, sig_resp);
	signal(SIGUSR2, sig_resp);
	signal(SIGQUIT, SIG_IGN);
	//	signal(SIGSEGV, sig_resp);
	//	signal(SIGBUS, sig_resp);
	signal(SIGTSTP, SIG_IGN);
}
