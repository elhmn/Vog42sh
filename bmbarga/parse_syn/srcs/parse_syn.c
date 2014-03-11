/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:15:31 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/11 17:38:18 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_syn.h"
#include "ftsh.h"
#include <stdio.h>

void	parse_error(int tok_nxt);

// regroupement de token par groupe

static int	convert(int tok)
{
	if (tok == CMD)
		return (CMD);
	else if (tok == ARG)
		return (ARG);
	else if (tok == FIL)
		return (FIL);
	else if (tok >= OUT && tok <= APP)
		return (OUT);
	else
		return (IN);
}

// initialisation du tableau de pointeur sur fonction

static void	set_fptr(fptr *f)
{
	f[0] = &syn_cmd;
	f[1] = &syn_arg;
	f[2] = &syn_file;
	f[3] = &syn_redir;
	f[4] = &syn_separ;
}

static int		check_syn(t_lex *lst)
{
	int		tok;
	fptr	f[5] = {NULL};

	set_fptr(f);
	tok = 0;
	while (tok != lst->tok && tok < 11)
		tok++;
	if ((lst->tok == AND || lst->tok == OR) 
			&& (lst->nxt->tok == VOID
				|| is_arg(lst->nxt->tok)
				|| is_fil(lst->nxt->tok)))
	{
		parse_error(lst->tok);
		return (FALSE);
	}
	if (tok == lst->tok)
		if (!f[convert(tok)](lst->nxt->tok)) //test if tok match with tok_nxt
			return (FALSE);
	return (TRUE);
}

// Check la syntaxe de la liste de token

int		parse_syn(t_lex *lst)
{
	t_lex	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (lst->tok == AND || lst->tok == OR) 
	{
		parse_error(lst->tok);
		return (FALSE);
	}
	while (tmp && tmp->nxt)
	{
		//printlst(tmp);
		//printf("tmp_lst_next[ i = %d ] = [ %s ]\n", i, tmp->nxt->elm);
		//printf("tmp_lst_next_tok[ i = %d ] = [ %d ]\n", i, tmp->nxt->tok);
		if (!check_syn(tmp))
			return (FALSE);
		//printf("tmp_lst[ %d ] = [ %s ]\n", i, tmp->elm);
		tmp = tmp->nxt;
		i++;
	}
	//printf("i = [ %d ]\n", i);
	return (TRUE);
}
