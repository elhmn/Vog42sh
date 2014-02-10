/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblanche <jblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:56:27 by jblanche          #+#    #+#             */
/*   Updated: 2013/12/29 20:02:01 by jblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 200
# define MY_EOF -1
# define MAX_NBR 2147483647
# define MIN_NBR -2147483648
# define MOD_SIZE 500000000
# define TRUE 1
# define FALSE 0
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "../libs/libft/includes/libft.h"
int		get_next_line(int const fd, char **line);
enum	e_str
{
	TMP,
	STR,
	BUFF
};
#endif /* !GET_NEXT_LINE_H */
