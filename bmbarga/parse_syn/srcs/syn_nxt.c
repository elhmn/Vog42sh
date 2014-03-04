/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_nxt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:10:04 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/04 13:09:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "tok_type.h"
#include "parse_syn.h"

//syn after commande

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

//syn after separateur && || ; |

int		syn_separ(int tok_nxt)
{
	if (!is_cmd(tok_nxt) && tok_nxt != VOID)
		return (FALSE);
	return (TRUE);
}

//syn after file

int		syn_file(int tok_nxt)
{
	if (!is_separ(tok_nxt)
			&& !is_redir(tok_nxt)
			&& tok_nxt != VOID)
		return (FALSE);
	return (TRUE);
}

//syn after redirection  < > >> << 

int		syn_redir(int tok_nxt)
{
	if (!is_file(tok_nxt) && tok_nxt == VOID)
		return (FALSE);
	else
		return (TRUE);
}

//syn after argument

int		syn_arg(int tok_nxt)
{
	if (!is_cmd(tok_nxt)
			&& !is_redir(tok_nxt)
			&& !is_separ(tok_nxt)
			&& tok_nxt != VOID)
		return (FALSE);
	else	
		return (TRUE);
}


