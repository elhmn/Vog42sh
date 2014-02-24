/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 17:01:22 by bmbarga           #+#    #+#             */
/*   Updated: 2014/02/24 17:06:58 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_tok
{
	char	*cmd;
	char	*opt;
	char	*arg;
	int		pip;
	int		pipr;
	int		type;
} t_tok;

#endif
