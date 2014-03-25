/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 15:44:42 by troussel          #+#    #+#             */
/*   Updated: 2014/03/25 16:08:37 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "ftsh_env.h"
#include "libft.h"
#include <unistd.h>

int			ft_exit(t_cmd *dat, t_env *env)
{
	if (!dat->arg[1] || unconvertible(dat->arg[1]))/*******/
exit
}
