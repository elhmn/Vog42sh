/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:16:44 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/21 15:34:12 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}


static char		*cpy_opt(char *arg, char **opt)
{
	int		len;
	char	*tmp;
	char	*opt_tmp;

	len = 0;
	while (*arg && *arg != '-')
		arg++;
	if (!*arg)
		return (NULL);
	tmp = arg;
	while (*arg && *arg != '\t' && *arg != ' ')
	{
		arg++;
		len++;
	}
	*opt = (char*)malloc(sizeof(char) * (len + 1));
	if (!opt)
		return (NULL);
	opt_tmp = *opt;
	while (*tmp && *tmp != '\t' && *tmp != ' ')
		*opt_tmp++ = *tmp++;
	*opt_tmp = '\0';
	return (tmp);
}

static char		*cpy_arg(char *arg)
{
	char	*str;
	int		len;

	len = ft_strlen(arg);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*arg)
		*str++ = arg++;
	return (str);
}

char	**get_opt(char *arg, char *opt, char *str)
{
	char	*tmp;
	int		len;

	len = 0;
	if (arg)
	{
		if (!(arg = cpy_opt(arg, &opt)))
			return (NULL);
		if (!(*str = cpy_arg(arg)))
			retutn (NULL);
	}
	return (NULL);
}

int		checksyn(char *opt)
{
	while (opt && *opt && *opt != 'n' && *opt != 'e' && *opt != 'E')
		opt++;
	if (!opt)
		return (1);
	return (0);
}
