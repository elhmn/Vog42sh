#include "ftsh.h"
#include <stdlib.h>

static t_tree	*free_tree(t_tree *lst)
{
	if (!lst)
		return (NULL);
	else if (lst->left)
		lst->left = free_tree(lst->left);
	else if (lst->right)
		lst->right = free_tree(lst->right);
	free(lst);
	lst = NULL;
	return (NULL);
}

t_for			*free_for(t_for *lst)
{
	if (!lst)
		return (NULL);
	else if (lst->nxt && lst->nxt->nxt)
		lst->nxt = free_for(lst->nxt);
	lst->wood = free_tree(lst->wood);
	free(lst->wood);
	free(lst);
	lst = NULL;
	return (NULL);
}
