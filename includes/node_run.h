/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_run.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:06:14 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 13:43:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		NODE_RUN_H
# define 	NODE_RUN_H
# include	"ftsh.h"

void	execute(t_cmd *dat, t_env *env, int pip[2][2], int swtch);

int		setpipe(t_cmd *dat, int pip[1][2][2], int swtch);
int		setfdfil(t_cmd *dat, int pip[1][2][2], int swtch);

int		*save_fd(int *sav_fd);
int		*dup_exec(t_cmd *dat, int pip[2][2], int swtch, int *sav_fd);
void	restore_fd(int *fd);

int		seekbin(t_cmd *dat, t_path *lst);
void	run_bin(t_cmd *dat, t_env *lst);

#endif
