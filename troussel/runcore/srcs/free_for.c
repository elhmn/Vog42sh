#include "ftsh.h"
#include <stdlib.h>

static char		**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
	tab = NULL;
	return (NULL);
}

static t_cmd	*free_cmd(t_cmd *cmd)
{
	char		*str;
	char		**tab;

	str = cmd->prg;
	free(str);
	if (cmd->ifile)
	{
		str = cmd->ifile;
		free(str);
	}
	if (cmd->ofile)
	{
		str = cmd->ofile;
		free(str);
	}
	str = NULL;
	tab = cmd->arg;
	tab = free_tab(tab);
	free(cmd);
	cmd = NULL;
	return (NULL);
}

static t_tree	*free_tree(t_tree *lst)
{
	if (lst->left)
		lst->left = free_tree(lst->left);
	if (lst->right)
		lst->right = free_tree(lst->right);
	if (lst->data)
		lst->data = free_cmd(lst->data);
	free(lst);
	lst = NULL;
	return (NULL);
}

t_for			*free_for(t_for *lst)
{
	if (lst->nxt)
		lst->nxt = free_for(lst->nxt);
	if (lst->wood)
		lst->wood = free_tree(lst->wood);
	free(lst);
	lst = NULL;
	return (NULL);
}
