/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:53:26 by jblanche          #+#    #+#             */
/*   Updated: 2014/02/28 18:59:53 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lex			*init_lex(t_lex *lex)
{
	lex = (t_lex *)malloc(sizeof(t_lex));
	lex->elm = NULL;
	lex->tok = 0;
	lex->nxt = NULL;
	return (lex);
}

t_lex			*add_lex(t_lex *lex, char *elm, int tok)
{
	t_lex		*tmp;
	t_lex		*new_node;

	tmp = lex;
	while (tmp->nxt)
		tmp = tmp->nxt;
	new_node = init_lex(lex);
	new_node->elm = ft_strdup(elm);
	new_node->tok = tok;
	tmp->nxt = new_node;
	return (lex);
}

t_lex			*free_lex(t_lex *lex)
{
	t_lex		*tmp;
	t_lex		*bak;

	while (lex->nxt && lex->nxt->nxt)
	{
		tmp = lex->nxt;
		bak = lex->nxt->nxt;
		free(tmp->elm);
		tmp->tok = 0;
		free(tmp);
		lex->nxt = bak;
	}
	free(lex->nxt->elm);
	lex->nxt->tok = 0;
	free(lex->nxt);
	free(lex->elm);
	lex->tok = 0;
	free(lex);
	return (NULL);
}
