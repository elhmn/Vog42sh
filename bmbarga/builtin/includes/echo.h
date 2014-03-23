/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 14:18:34 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/23 15:11:59 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H
# include "ftsh_env.h"
# include "ftsh.h"
# include <string.h>
# define FALSE 1
# define TRUE 0

/*
** getarg.c
*/

void	echo_print(char *str, t_env *env, int *flag);
int		ft_echo(t_cmd *cmd, t_env *env);
int		checksyn(char **opt, char **str, int *flag);
char	*get_arg(char *arg, char **opt);

#endif /* !ECHO_H */
