/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_nxt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:11:07 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/04 11:14:59 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define SYN_NXT_H

int		syn_cmd(int tok_nxt);
int		syn_separ(int tok_nxt);
int		syn_file(int tok_nxt);
int		syn_redir(int tok_nxt);
int		syn_arg(int tok_nxt);

#endif /* !SYN_NXT_H */
