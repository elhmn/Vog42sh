/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 13:23:35 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/28 12:22:57 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_puterror(char const *s)
{
	int	loc;

	loc = 0;
	while (s[loc])
		loc++;
	write(2, s, loc);
}

