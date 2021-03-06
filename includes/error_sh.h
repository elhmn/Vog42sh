/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_sh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:46:37 by troussel          #+#    #+#             */
/*   Updated: 2014/03/26 13:33:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		ERROR_SH_H
# define	ERROR_SH_H
# include	<stdlib.h>

# define	CMDNF	1
# define	ARG_M	2
# define	ARG_F	3
# define	PERM	4
# define	SYN		5
# define	NSFOD	6
# define	UNKOP	7
# define	UNDEF	8

void	puterror(char const *s);
void	error(int code, char *str, int esc_seq);

#endif
