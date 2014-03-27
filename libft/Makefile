#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troussel <troussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 14:55:43 by troussel          #+#    #+#              #
#    Updated: 2014/03/27 11:53:32 by troussel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
.PHONY: all $(NAME) clean fclean re
NAME = libft.a
SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
		ft_memcpy.c ft_memmove.c ft_strcat.c ft_strchr.c\
		ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c\
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c\
		ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c\
		ft_putchar.c ft_putstr.c ft_memset.c ft_putendl.c ft_freetabc.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr.c ft_putstr_fd.c\
		ft_putnbr_fd.c ft_strnew.c ft_strclr.c ft_strequ.c ft_strnequ.c\
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_dimgridc.c ft_strsplit.c\
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strdel.c\
		ft_memalloc.c ft_memdel.c ft_realloc_c.c ft_whitestr.c\
		ft_strcpytab.c ft_itoa.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRC)
		gcc $(CFLAGS) $(SRC) -I ../includes
		ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
