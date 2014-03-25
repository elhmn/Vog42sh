/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:34:39 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/11 17:44:58 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		is_cmd(int token)
{
	return (token == CMD);
}

int		is_fil(int token)
{
	return (token == FIL);
}

int		is_arg(int token)
{
	return (token == ARG);
}

int		is_redir(int token)
{
	return (token == IN || token == OUT 
			|| token == APP);
}

int		is_separ(int token)
{
	return (token == PIPE || token == SEMIC 
			|| token == OR || token == AND);
}
