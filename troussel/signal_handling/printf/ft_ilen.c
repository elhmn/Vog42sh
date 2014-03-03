/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 10:39:26 by troussel          #+#    #+#             */
/*   Updated: 2013/12/19 10:43:30 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_ilen(int n)
{
	int	size;
	int	i;

	if (n == 0)
		return (1);
	size = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	i = 1;
	while (n != 0)
	{
		n = n / 10;
		size++;
		i++;
	}
	return (size);
}