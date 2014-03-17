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

void			print_lex(t_lex *lex)
{
	if (!lex || !lex->elm)
		ft_printf("pas de lex !\n");
	while (lex)
	{
		ft_printf("\n/------------------\n");
		ft_printf("elm = %s\n", lex->elm);
		ft_printf("tok = %d\n", lex->tok);
		ft_printf("------------------/\n");
		lex = lex->nxt;
	}
}

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
	new_node = NULL;
	new_node = init_lex(new_node);
	new_node->tok = tok;
	if (elm)
		new_node->elm = ft_strdup(elm);
	if (!lex)
		return (new_node);
	else
	{
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = new_node;
	}
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
