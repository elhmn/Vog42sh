/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:03:56 by troussel          #+#    #+#             */
/*   Updated: 2014/03/27 14:28:34 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftsh.h"
#include "parse_tree.h"
#include "error_sh.h"
#include "libft.h"

static t_tree	*load_argo(t_tree *leaf)
{
	if (!leaf->data->prg)
		return (leaf);
	if (!leaf->data->arg)
	{
		if (!(leaf->data->arg = (char**)malloc(sizeof(char*) * 2)))
		{
			error(0, "Out of memory", 0);
			return (NULL);
		}
		leaf->data->arg[1] = 0;
	}
	leaf->data->arg[0] = ft_strdup(leaf->data->prg);
	return (leaf);
}

static t_tree	*parse_tree_aux(t_lex *lst, t_cmd *node, t_tree *leaf)
{
	if (!lst)
		return (load_argo(leaf));
	if (lst->tok == ARG)
		lst = treat_arg(&node->arg, lst);
	if (!lst)
		return (load_argo(leaf));
	if (lst->tok == IN || lst->tok == OUT || lst->tok == APP)
		lst = treat_redir(&node, lst);
	if (!lst)
		return (load_argo(leaf));
	if (lst->tok == PIPE)
	{
		lst = treat_pipe(&node->pipe_w, lst);
		leaf->left = parse_tree(lst, node, 1);
	}
	else if (lst && lst->tok == OR)
		leaf->right = parse_tree(lst->nxt, node, 0);
	else if (lst && lst->tok == AND)
		leaf->left = parse_tree(lst->nxt, node, 0);
	return (load_argo(leaf));
}

static t_lex	*inf_outf_frst(t_lex *lst, t_cmd *node)
{
	lst = treat_redir(&node, lst);
	if (lst && lst->tok == CMD)
		lst = treat_cmd(&node->prg, lst);
	else if (!lst || lst->tok == PIPE || lst->tok == AND || lst->tok == OR)
		return (lst);
	else
		error(0, "Parse error", 1);
	return (lst);
}

t_tree			*parse_tree(t_lex *lst, t_cmd *prv, int flg_pipe)
{
	t_cmd	*node;
	t_tree	*leaf;

	if (!(node = add_cmdd(prv)))
		return (NULL);
	node->pipe_r = (flg_pipe ? 1 : 0);
	if (!(leaf = add_leaf(node)))
		return (NULL);
	if (lst->tok == IN || lst->tok == OUT || lst->tok == APP)
		lst = inf_outf_frst(lst, node);
	else if (lst->tok == CMD)
		lst = treat_cmd(&node->prg, lst);
	else
		error(0, "Parse error", 1);
	return (parse_tree_aux(lst, node, leaf));
}
