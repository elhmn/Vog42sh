/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:55:38 by troussel          #+#    #+#             */
/*   Updated: 2014/03/24 14:55:40 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		puterror(char const *s)
{
	int	loc;

	loc = 0;
	while (s[loc])
		loc++;
	write(2, s, loc);
}
