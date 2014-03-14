/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:01:26 by troussel          #+#    #+#             */
/*   Updated: 2014/03/14 13:02:11 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HDEMERDE_H
# define HDEMERDE_H

int		isbuiltin(t_cmd *dat);/*renvoie 1 si dat->prg est un builtin, 0 sinon*/
int		builtin(t_cmd *dat, t_env *env);/*execute le builtin approprié et renvoi le return de ce dernier*/

#endif /* !HDEMERDE_H */
