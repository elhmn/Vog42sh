/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 10:35:51 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/26 13:47:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_TYPE_H
# define TOK_TYPE_H

int		is_cmd(int token);
int		is_fil(int token);
int		is_arg(int token);
int		is_redir(int token);
int		is_separ(int token);

#endif
