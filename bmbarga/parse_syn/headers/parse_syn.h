/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syn.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:25:08 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/04 13:07:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_SYN_H
# define PARSE_SYN_H

# define TRUE 0
# define FALSE 1
# include <stdlib.h>
# include "tok_type.h"
# include "42sh.h"

typedef int	(*fptr)(int);
int			parse_syn(t_lex *lst);
static int	convert(int tok);
static int	set_fptr(fptr *f);
static int	check_syn(t_lex *lst);

#endif /* !PARSE_SYN_H */
