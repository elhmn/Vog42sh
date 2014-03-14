/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_run.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:06:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/14 13:49:27 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		NODERUN_H
# define 	NODERUN_H
# include	"ftsh.h"

int		execute(t_cmd *dat, t_env *env, int pip[2][2], int swtch);/*configure les fd et execute le binaire désigné par dat ou, le builtin, dans ce cas la fonction appel exit avec la valeur de retour du builtin*/

int		setpipe(t_cmd *dat, int pip[1][2][2], int swtch);
int		setfdfil(t_cmd *dat, int pip[1][2][2], int swtch);

int		seekbin(t_cmd *dat, t_path *lst);
void	run_bin(t_cmd *dat, t_env *lst);

#endif		/* !NODERUN_H */
