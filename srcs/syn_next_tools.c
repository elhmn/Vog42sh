/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_next_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 12:28:23 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/26 12:33:31 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "libft.h"
#include "tok_type.h"
#include "parse_syn.h"
#include "error_sh.h"

static char	*tok_to_char(int  tok)
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

void		parse_error(int tok_nxt)
{
	error(SYN, NULL, 0);
	ft_putstr(" \'");
	ft_putstr(tok_to_char(tok_nxt));
	ft_putstr("\'\n");
}
