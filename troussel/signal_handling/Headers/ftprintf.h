/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troussel <troussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 09:38:43 by troussel          #+#    #+#             */
/*   Updated: 2014/01/29 10:59:14 by troussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_ilen(int n);
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_uitoa(unsigned int n);
int		ft_uilen(unsigned int n);
void	ft_putnbrui(unsigned int n);
int		ft_puint(char c, unsigned int num);
int		ft_putstri(char c, char *str);
int		ft_pint(char c, int num);
int		ft_putcar(char c);

#endif /* !FTPRINTF_H */
