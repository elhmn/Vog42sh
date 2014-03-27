/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 13:07:14 by troussel          #+#    #+#             */
/*   Updated: 2013/12/19 13:13:57 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ftprintf.h"

void	ft_putnbrui(unsigned int n)
{
	ft_putstr(ft_uitoa(n));
}