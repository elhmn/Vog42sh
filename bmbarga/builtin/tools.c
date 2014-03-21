/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:16:44 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/21 17:17:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
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

int		checksyn(char **opt, char **str, int *flag)
{
	char	*tmp1;
	char	*tmp2;
	char	*opt_tmp;

	opt_tmp = *opt;
	tmp1 = NULL;
	tmp2 = NULL;
	while (opt_tmp && *opt_tmp && *opt_tmp != 'n'
			&& *opt_tmp != 'e' && *opt_tmp != 'E')
		opt_tmp++;
	if (!opt_tmp) //strjoin "-opt" && "str"
	{
		tmp1 = ft_strjoin(opt_tmp, "-");
		tmp2 = ft_strjoin(tmp1, *str);
		free(*str);
		*str = tmp2;
		free(tmp1);
		free(opt_tmp);
		return (TRUE);
	}
	opt_tmp = *opt;
	while (*opt_tmp && opt - opt_tmp < 3)
	{
		if (*opt_tmp == 'n')
			flag += 1;
		else if (*opt_tmp == 'e')
			flag += 2;
		else if (*opt_tmp == 'E')
			flag += 3;
		opt_tmp++;
	}
	return (TRUE);
}
