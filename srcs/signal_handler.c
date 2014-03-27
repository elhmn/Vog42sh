/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:23:31 by troussel          #+#    #+#             */
/*   Updated: 2014/03/27 13:56:34 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
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
		ft_putstr("\033[32m$> \033[0m");
	else
		ft_putstr("\n\033[32m$> \033[0m");
}

void		sig_handle(void)
{
	signal(SIGINT, sig_resp);
	signal(SIGHUP, sig_resp);
	signal(SIGINFO, sig_resp);
	signal(SIGUSR1, sig_resp);
	signal(SIGUSR2, sig_resp);
	signal(SIGQUIT, sig_resp);
	signal(SIGSEGV, sig_resp);
	signal(SIGBUS, sig_resp);
	signal(SIGTSTP, SIG_IGN);
}
