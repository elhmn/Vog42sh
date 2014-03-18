/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:41:29 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/18 13:26:50 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			is_spec(char *str)
{
	ft_printf("is spec\n");
	if (!ft_strcmp(str, ">"))
	{
	ft_printf("is spec 1\n");
		return (OUT);
	}
	else if (!ft_strcmp(str, "<"))
		return (IN);
	else if (!ft_strcmp(str, ">>"))
		return (APP);
	else if (!ft_strcmp(str, "|"))
		return (PIPE);
	else if (!ft_strcmp(str, ";"))
		return (SEMIC);
	else if (!ft_strcmp(str, "&&"))
		return (AND);
	else if (!ft_strcmp(str, "||"))
		return (OR);
	ft_printf("is spec end\n");
	return (0);
}
