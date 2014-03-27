/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:51:20 by troussel          #+#    #+#             */
/*   Updated: 2014/03/27 13:46:54 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_fullwhite(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!(s[i] == 32 || s[i] == '\n' || s[i] == '\t'))
			return (0);
	}
	return (1);
}

static int	ft_trailstart(const char *s, int i)
{
	if (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		return (1);
	return (0);
}

static int	ft_trailend(const char *s)
{
	int	len;

	len = ft_strlen(s);
	len = (len != 0 ? len - 1 : len);
	if (s[len] == 32 || s[len] == '\n' || s[len] == '\t')
		return (1);
	return (0);
}

static char	*ft_trimit(char const *s, int start, int end, int len)
{
	char	*scpy;
	int		i;

	i = 0;
	while (s[start] == 32 || s[start] == '\n' || s[start] == '\t')
		start++;
	i = -1;
	while (s[++i] != '\0')
	{
		len = (!(s[i] == 32 || s[i] == '\n' || s[i] == '\t') ? 1 : len);
		if ((ft_trailstart(s, i) || !s[i + 1]) && len == 1)
		{
			len = 0;
			end = (!s[i + 1] && !ft_trailstart(s, i) ? i + 1 : i);
		}
	}
	len = end - start;
	if (!(scpy = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	scpy = ft_strsub(s, start, (size_t)len);
	return (scpy);
}

char		*ft_strtrim(const char *s)
{
	int		start;
	int		end;
	int		len;
	char	*scpy;

	start = 0;
	end = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	if (ft_fullwhite(s))
	{
		scpy = (char*)malloc(sizeof(char) * 1);
		scpy[0] = '\0';
		return (scpy);
	}
	scpy = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ft_trailstart(s, 0) && !ft_trailend(s))
		return (ft_strcpy(scpy, (char*)s));
	return (ft_trimit(s, start, end, len));
}
