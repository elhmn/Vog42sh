/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 13:23:35 by jblanche          #+#    #+#             */
/*   Updated: 2014/02/25 13:49:12 by troussel         ###   ########.fr       */
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