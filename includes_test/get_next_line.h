/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 15:49:36 by troussel          #+#    #+#             */
/*   Updated: 2014/01/26 14:36:46 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef struct	s_chk
{
	char	*str;
	size_t	size;
}				t_chk;

int		get_next_line(int const fd, char **line);

#endif /* !GET_NEXT_LINE_H */
