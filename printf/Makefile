#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troussel <troussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/19 11:09:08 by troussel          #+#    #+#              #
#    Updated: 2014/03/27 12:02:58 by troussel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
.PHONY: all $(NAME) clean fclean re
NAME = libftprintf.a
SRC =	ft_printf.c ft_ilen.c ft_itoa.c ft_putchar.c ft_putnbr.c ft_putstr.c\
		ft_strlen.c ft_putnbrui.c ft_uilen.c ft_uitoa.c ft_printer.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -c
HDPATH = ../includes

all: $(NAME)

$(NAME): $(SRC)
			gcc $(CFLAGS) $(SRC) -I $(HDPATH)
			ar rc $(NAME) $(OBJ)

clean:
			rm -rf $(OBJ)

fclean: clean
			rm -rf $(NAME)
re: fclean all
