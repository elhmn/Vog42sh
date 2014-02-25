/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:52:07 by troussel          #+#    #+#             */
/*   Updated: 2014/02/25 14:41:21 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "error_sh.h"

static void	code_seq(int code)
{

}

void		error(int code, char *str, int esc_seq)
{
	if (str)
		puterror(str);
	if (code)
		code_seq(code);
	if (esc_seq)
		exit(1);
}
