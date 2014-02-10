# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 12:42:57 by jblanche          #+#    #+#              #
#    Updated: 2013/12/22 18:18:36 by jblanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJDIR = ./
SRCDIR = ./srcs/
BINDIR = ./
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c \
	   ft_convert_hex.c ft_convert_oct.c ft_strlen.c ft_itoa.c ft_putuint.c \
	   ft_itoa_unsint.c
FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
CSRCS = $(addprefix $(SRCDIR), $(SRCS))
COBJS = $(addprefix $(OBJDIR), $(OBJS))
CEXEC = $(addprefix $(BINDIR), $(NAME))

all: $(NAME)

$(NAME): $(CSRCS) ./includes/
	gcc $(FLAGS) -I./includes/ -c $(CSRCS)
	ar rc $(NAME) $(COBJS)
	ranlib $(NAME)

clean:
	rm -rf $(COBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean
