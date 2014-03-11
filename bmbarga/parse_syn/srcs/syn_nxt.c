/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_nxt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:10:04 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/11 16:46:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "tok_type.h"
#include <stdio.h>
#include "parse_syn.h"
#include "error_sh.h"

//put ft_putstr.c in a file

void	ft_putstr(char *str);

char	*tok_to_char(int  tok)
{
	if (tok == IN)
		return ("<");
	else if (tok == OUT)
		return (">");
	else if (tok == APP)
		return (">>");
	else if (tok == PIPE)
		return ("|");
	else if (tok == SEMIC)
		return (";");
	else if (tok == AND)
		return ("&&");
	else if (tok == PIPE)
		return ("|");
	else if (tok == OR)
		return ("||");
	else 
		return ("newline");
}

void	parse_error(int tok_nxt)
{
	error(SYN, NULL, 0);
	ft_putstr(" \'");
	ft_putstr(tok_to_char(tok_nxt));
	ft_putstr("\'\n");
}

// syn after commande

int		syn_cmd(int tok_nxt)
{
	if (!is_separ(tok_nxt)
		&& !is_redir(tok_nxt)
		&& !is_arg(tok_nxt)
		&& !is_fil(tok_nxt)
		&& tok_nxt != VOID)
	{

		return (FALSE);
	}
	return (TRUE);
}

// syn after separateur && || ; |

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

// syn after file

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

// syn after redirection  < > >> << 

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

// syn after argument

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
