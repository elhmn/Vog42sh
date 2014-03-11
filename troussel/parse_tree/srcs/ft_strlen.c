/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:40:49 by troussel          #+#    #+#             */
/*   Updated: 2014/03/11 16:43:56 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(const char *s)
{
	int		sizeout;
	int		i;

	i = 0;
	sizeout = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		sizeout++;
		i++;
	}
	return (sizeout);
}
