/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:58:19 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 19:58:21 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void**) alst);
	}
}
