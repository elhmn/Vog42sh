/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:15:14 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/04 13:09:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "parse_syn.h"
#include "42sh.h"

t_lex	*lstadd_end(t_lex *end_lst, char *elm, int tok)
{
	t_lex	*end_tmp;

	end_tmp = lst_new(elm);
	end_lst->nxt = end_tmp;
	return (end_tmp);
}

t_lex	*lst_new(char *elm)
{
	t_lex	*new;

	if (!(new = malloc(sizeof(t_lex))))
		return (NULL);
	/*work on elem*/
	return (new);
}

t_lex	*first_elm(char *elem)
{
	t_lex  *lst;

	if (!(lst = malloc(sizeof(t_lex))))
		return (NULL);
	lst->elm = elem;
	if (!elem || !*elem)
		lst->tok = CMD;
	else if
		lst->tok = VOID;
	lst->nxt = NULL;
	return (lst);
}

int		set_lex_lst(int argc, char **argv, t_lex *lst)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		
		//stock le char* et son type
	}
	return (0);
}


int		main(int argc, char **argv)
{
	t_lex	*lst;

	if (argc > 1)
	{
		if (argc > 1)
		{
			lst = set_lex_lst(argc, argv, lst);
			parse_syn(lst);
		}
	}
	return (TRUE);
}

