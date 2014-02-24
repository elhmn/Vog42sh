/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:23:31 by troussel          #+#    #+#             */
/*   Updated: 2014/02/24 14:54:27 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sig_handle.h"

static

void		sig_handle(void)
{
	signal(SIGINT, sig_resp);
	signal(SIGINFO, sig_resp);
	signal(SIGUSR1, sig_resp);
	signal(SIGUSR2, sig_resp);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGSEGV, sig_resp);
	signal(SIGBUS, sig_resp);
	signal(SIGTSTP, SIG_IGN);
}
