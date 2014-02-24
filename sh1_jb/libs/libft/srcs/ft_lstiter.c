/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:58:35 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 19:58:37 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	if (lst)
	{
		if (lst->next == NULL)
			f(lst);
		else
		{
			f(lst);
			ft_lstiter(lst->next, f);
		}
	}
}
