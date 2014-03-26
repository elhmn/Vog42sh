/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_builtin.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 12:58:50 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 13:39:12 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTSH_BUILTIN_H
# define	FTSH_BUILTIN_H

int		isbuiltin(t_cmd *dat);
int		builtin(t_cmd *dat, t_env *env);

int		ft_cd(t_cmd *dat, t_env *env);
int		ft_echo(t_cmd *dat, t_env *env);
int		ft_exit(t_cmd *dat, t_env *env);
int		ft_env(t_cmd *dat, t_env *env);
int		ft_setenv(t_cmd *dat, t_env *env);
int		ft_unsetenv(t_cmd *dat, t_env *env);

#endif
