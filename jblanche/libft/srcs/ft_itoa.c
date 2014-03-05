/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:53:21 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/08 17:36:52 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_count(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		count;

	count = 0;
	if (n < 0)
	{
		n = -1 * n;
		count++;
	}
	count += ft_count(n);
	ret = (char *) malloc(sizeof (char) * (count + 1));
	ret[count] = '\0';
	while (n > 0)
	{
		ret[count - 1] = n % 10 + '0';
		n = n / 10;
		count--;
	}
	if (digit_count == 1)
		str[0] = '-';
	return (str);
}
