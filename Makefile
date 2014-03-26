#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troussel <troussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/26 13:03:46 by troussel          #+#    #+#              #
#    Updated: 2014/03/26 13:05:21 by troussel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME =	42sh

SRCDIR = srcs/

CFILES =	

SRC = $(addprefix $(SRCDIR), $(CFILES))
GCC = gcc -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
HDDIR = includes/

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		make -C printf/
		$(GCC) -o $(NAME) $(OBJ) libft/libft.a printf/libftprintf.a

%.o: %.c
	$(GCC) -c -o $@ $^  -I $(HDDIR)

clean:
		make -C libft/ clean
		make -C printf/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		make -C printf/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
