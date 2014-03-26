/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_builtin.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 12:58:50 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 14:39:02 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTSH_BUILTIN_H
# define	FTSH_BUILTIN_H

int		ft_cd(t_cmd *dat, t_env *env);
int		ft_echo(t_cmd *dat, t_env *env);
int		ft_exit(t_cmd *dat, t_env *env);
int		ft_env(t_cmd *dat, t_env *env);
int		ft_setenv(t_cmd *dat, t_env *env);
int		ft_unsetenv(t_cmd *dat, t_env *env);

#endif
