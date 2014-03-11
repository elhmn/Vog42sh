/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syn.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:25:08 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/04 16:21:14 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_SYN_H
# define PARSE_SYN_H

# define TRUE 1
# define FALSE 0
# include <stdlib.h>
# include "tok_type.h"
# include "syn_nxt.h"
# include "ftsh.h"

typedef int	(*fptr)(int);
int			parse_syn(t_lex *lst);

#endif /* !PARSE_SYN_H */
