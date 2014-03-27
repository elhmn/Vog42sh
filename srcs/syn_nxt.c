/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_nxt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:10:04 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/27 13:15:43 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "libft.h"
#include "tok_type.h"
#include "parse_syn.h"
#include "error_sh.h"

int		syn_cmd(int tok_nxt)
{
	if (!is_separ(tok_nxt)
		&& !is_redir(tok_nxt)
		&& !is_arg(tok_nxt)
		&& !is_fil(tok_nxt)
		&& tok_nxt != VOID)
		return (FALSE);
	return (TRUE);
}

int		syn_separ(int tok_nxt)
{
	if (!is_cmd(tok_nxt)
		&& !is_redir(tok_nxt)
		&& tok_nxt != VOID)
	{
		if (is_separ(tok_nxt))
			parse_error(tok_nxt);
		return (FALSE);
	}
	return (TRUE);
}

int		syn_file(int tok_nxt)
{
	if (!is_fil(tok_nxt)
		&& !is_arg(tok_nxt)
		&& !is_separ(tok_nxt)
		&& !is_redir(tok_nxt)
		&& !is_cmd(tok_nxt)
		&& tok_nxt != VOID)
	{
		return (FALSE);
	}
	return (TRUE);
}

int		syn_redir(int tok_nxt)
{
	if (!is_fil(tok_nxt) && tok_nxt == VOID)
	{
		if (is_redir(tok_nxt))
			parse_error(tok_nxt);
		else if (tok_nxt == VOID)
			parse_error(tok_nxt);
		return (FALSE);
	}
	else
		return (TRUE);
}

int		syn_arg(int tok_nxt)
{
	if (!is_fil(tok_nxt)
		&& !is_cmd(tok_nxt)
		&& !is_arg(tok_nxt)
		&& !is_redir(tok_nxt)
		&& !is_separ(tok_nxt)
		&& tok_nxt != VOID)
		return (FALSE);
	else
		return (TRUE);
}
