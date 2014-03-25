/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_builtin.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 12:58:50 by troussel          #+#    #+#             */
/*   Updated: 2014/03/17 13:05:35 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FTSHBUILTIN_H
# define	FTSHBUILTIN_H

int		isbuiltin(t_cmd *dat);/*renvoie 1 si dat->prg est un builtin, 0 sinon*/
int		builtin(t_cmd *dat, t_env *env);/*execute le builtin approprié et renvoi le return de ce dernier*/

int		ft_cd(t_cmd *dat, t_env *env);
int		ft_echo(t_cmd *dat, t_env *env);
int		ft_exit(t_cmd *dat, t_env *env);
int		ft_env(t_cmd *dat, t_env *env);
int		ft_setenv(t_cmd *dat, t_env *env);
int		ft_unsetenv(t_cmd *dat, t_env *env);

#endif		/* !FTSHBUILTIN_H */
