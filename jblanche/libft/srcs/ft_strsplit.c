/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:36:49 by jblanche          #+#    #+#             */
/*   Updated: 2014/03/25 14:01:24 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_strsplit_init(int *i, int *j, int *count)
{
	*count = 0;
	*i = 0;
	*j = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	int		i;
	int		j;
	char	**ret;

	ret = NULL;
	if (s)
	ft_putendl(s);
	ft_strsplit_init(&i, &j, &count);
	while (s[i++])
	{
		while (s[i++])
		{
			if (s[i] == c)
				count++;
		}
		ret = (char **)malloc(sizeof(ret) * (count + 2));
		ret[count + 1] = NULL;
		i = 0;
		while (s[0])
		{
			while (s[i] && s[i] != c)
				i++;
			ret[j++] = (char *)malloc(sizeof(ret[j]) * i);
			ft_strncpy(ret[j - 1], s, i);
			s = ft_strnclr((char *)s, i + 1);
			i = 0;
		}
	}
	return (ret);
}
