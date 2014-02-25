/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:37:29 by troussel          #+#    #+#             */
/*   Updated: 2014/02/25 15:11:54 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main_sh.h"

extern char	**environ;

int		main(void)
{
	if (!environ[0])
		puterror(0, "Environment data is empty", 1);

	return (0);
}
