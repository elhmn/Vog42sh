/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tak.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriclet <mriclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 14:53:53 by mriclet           #+#    #+#             */
/*   Updated: 2014/03/07 16:54:12 by mriclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_for		*alloc_new_tree(t_takl *lst, int opt, t_for *prev, int prev_pipe_w)
{
	t_for	*ret;

	ret = ft_memalloc(sizeof(t_for *));
	ret->wood = ft_memalloc(sizeof(t_tree *));
	if (opt == 0)
		ret->wood = parse_tree(lst->lst, NULL, 0);
	else
		ret->nxt->wood = parse_tree(lst->lst, prev->wood->data , prev_pipe_w);
	return (ret);
}

t_for		*pars_for(t_tokl *lst)
{
	t_for	*ret;
	t_for	*elem;
	int		loop;
	int		prev_pipe_w;

	loop = 1;
	elem = alloc_new_tree(lst, 0, NULL, 0);
	first = elem;
	prev_pipe_w = elem->wood->data->pipe_w;
	while (loop)
	{
		prev_pipe_w = elem->wood->data->pipe_w;
		elem->nxt = alloc_new_tree(lst, 1, elem, prev_pipe_w);
		if (!elem->wood->nxt || !lst->nxt)
			loop = 0;
		else
		{
			elem->wood = elem->wood->nxt;
			lst = lst->nxt;
			elem = elem->nxt;
		}
	}
	elem->nxt = NULL;
	return (first);
}

void		*ft_memalloc(size_t size)
{
	void	ret;

	ret = malloc(size);
	if (!ret)
		exit(1);
	return (ret);
}
