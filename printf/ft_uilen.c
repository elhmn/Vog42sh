/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uilen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 13:11:38 by troussel          #+#    #+#             */
/*   Updated: 2013/12/19 13:14:19 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_uilen(unsigned int n)
{
	int	size;
	int	i;

	size = 0;
	if (n == 0)
		return (1);
	i = 1;
	while (n != 0)
	{
		n = n / 10;
		size++;
		i++;
	}
	return (size);
}