/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 16:03:59 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/22 18:27:50 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_count(unsigned int n)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa_unsint(unsigned int n)
{
	char	*ret;
	int		count;

	count = 0;
	count += ft_count(n);
	ret = (char *)malloc(sizeof(char) * (count + 1));
	ret[count] = '\0';
	while (n > 0)
	{
		ret[count - 1] = n % 10 + '0';
		n = n / 10;
		count--;
	}
	if (count == 1)
		ret[0] = '-';
	return (ret);
}
