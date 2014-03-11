/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:15:14 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/07 16:36:03 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libft.h>

#include "parse_syn.h"
#include "ftsh.h"
#include <stdio.h>
#include <stdlib.h>

/*
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
	//work elem
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
*/

typedef struct s_elem
{
	char	*cara;
	int		tok;
}			t_elem;


t_lex *lstnew(t_elem elem)
{
	t_lex	*new;

	if (!(new = malloc(sizeof(t_lex))))
		return (NULL);
	new->tok = elem.tok;
	//printf("elem.tok = [%d]\n", elem.tok);
	//printf("elem.cara = [%s]\n\n", elem.cara);
	new->elm = elem.cara;
//	printf("new.tok = [%d]\n", new->tok);
//	printf("new.cara = [%s]\n\n\n", new->elm);
	new->nxt = NULL;
	return (new);
}

t_lex	*addend(t_elem elem, t_lex *end_lst)
{
	t_lex	*new;

	if (!(new = lstnew(elem)))
		return (NULL);
//	printf("ADD_END_TEST\nnew.tok = [%d]\n", new->tok);
//	printf("new.cara = [%s]\n\n\n", new->elm);
	end_lst->nxt = new;	
	return (new);
}


t_lex	*set_lex_lst(t_lex *begin_lst)
{
	t_elem	tab[12];
	t_lex	*end_lst;
	int		i;
	
	tab[0].tok = CMD;
	tab[0].cara = "cat";
	
	tab[1].tok = SEMIC;
	tab[1].cara = ";";
	
	tab[2].tok = SEMIC;
	tab[2].cara = ";";
	
	tab[3].tok = VOID;
	tab[3].cara = "void";
	
	tab[4].tok = VOID;
	tab[4].cara = "";
	
	tab[5].tok = VOID;
	tab[5].cara = "";

	tab[7].tok = VOID;
	tab[7].cara = "";
	
	tab[8].tok = VOID;
	tab[8].cara = "";
	
	tab[9].tok = VOID;
	tab[9].cara = "";
	
	tab[10].tok = VOID;
	tab[10].cara = "";
	
	tab[11].tok = VOID;
	tab[11].cara = "";

	i = 1;

	begin_lst = lstnew(tab[0]); //first elem
	end_lst = begin_lst;
	while (i < 12 && tab[i].tok != VOID)
		end_lst = addend(tab[i++], end_lst); //add last elem
	end_lst = addend(tab[i++], end_lst); //add last elem
	//end_lst = addend(tab[i], end_lst); //add last elem
	printf("TEST_BEGIN_LST\n begin_lst = tok[%d] begin_lst = tok[%s]\n\n", begin_lst->tok, begin_lst->elm);
	return (begin_lst);
}

void	printlst(t_lex *lst)
{
	int		i;
	t_lex	*tmp;

	tmp = lst;
	i = 0;
	while (tmp->nxt)
	{
		printf("lex[%d].tok = [ %d ]\n", i , tmp->tok);
		printf("lex[%d].elm = [ %s ]\n\n", i++ , tmp->elm);
		tmp = tmp->nxt;
	}
	printf("lex[%d].tok = [ %d ]\n", i , tmp->tok);
	printf("lex[%d].elm = [ %s ]\n\n", i++ , tmp->elm);
}

int 		main(void)//int argc, char **argv)
{
	t_lex	*lst;

	lst = NULL;
//	if (argc > 1)
//	{
		lst = set_lex_lst(lst);
		printf("\n************ PRINT LST ***************\n\n");
		printlst(lst);
		if (!parse_syn(lst))
			printf("ERROR\n");
		else
			printf("OK\n");
//	}
	return (TRUE);
}
