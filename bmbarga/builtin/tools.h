/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 14:21:02 by bmbarga           #+#    #+#             */
/*   Updated: 2014/03/22 15:53:16 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# define FALSE 1
# define TRUE 0

void	ft_putchar(char c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr(char *str);
char	*ft_strnew(size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** getarg.c
*/

int		checksyn(char **opt, char **str, int *flag);
char	**get_arg(char *arg, char *opt, char *str)

#endif /* !TOOLS_H */
