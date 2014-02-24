/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:27:04 by troussel          #+#    #+#             */
/*   Updated: 2013/12/19 11:19:38 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftprintf.h"

void	ft_putstr(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}
