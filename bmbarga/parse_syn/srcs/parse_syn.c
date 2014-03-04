/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:15:31 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/04 13:07:51 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse_syn.h"

//Check la syntaxe de la liste de token

typedef int		(*fptr)(int);

int		parse_syn(t_lex *lst)
{
	while (lst && lst->new)
		if (check_syn(lst))
			return (TRUE);
	return (FALSE);
}

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
		return (PIPE);
}

// initialisation du tableau de pointeur sur fonction

static int	set_fptr(fptr *f)
{
	f[0] = &syn_cmd;
	f[1] = &syn_arg;
	f[2] = &syn_file;
	f[3] = &syn_redir;
	f[4] = &syn_separ;
	return (TRUE);
}

static int		check_syn(t_lex *lst)
{
	int		tok;
	fptr	f[5] = {NULL};

	set_fptr(f);
	tok = 0;
	while (tok != lst->tok && tok < 11)
		tok++;
	if (tok == lst->tok)
		if (f[convert(tok)](lst->next->tok))
			return (TRUE);
	return (FALSE);
}
