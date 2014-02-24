# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 12:42:57 by jblanche          #+#    #+#              #
#    Updated: 2014/01/04 11:09:49 by jblanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJDIR = ./
SRCDIR = srcs/
BINDIR = ./
SRCS = 	ft_putchar.c ft_putnbr.c ft_putstr.c ft_isdigit.c ft_strclr.c \
		ft_strcmp.c ft_strlen.c ft_putendl.c ft_strchr.c ft_atoi.c \
		ft_isalpha.c ft_isalnum.c ft_strdup.c ft_isascii.c ft_isprint.c \
		ft_strncat.c ft_strcat.c ft_tolower.c ft_strcmp.c ft_toupper.c \
		ft_strncmp.c ft_strstr.c ft_strcpy.c ft_strncpy.c ft_strnstr.c \
		ft_strrchr.c ft_strlcat.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memccpy.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_strsub.c \
		ft_strjoin.c ft_realloc.c ft_strchclr.c ft_strnclr.c ft_strtrim.c \
		ft_puttab.c ft_strsplit.c ft_tabcpy.c ft_puterror.c ft_delnextchars.c
FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
CSRCS = $(addprefix $(SRCDIR), $(SRCS))
COBJS = $(addprefix $(OBJDIR), $(OBJS))
CEXEC = $(addprefix $(BINDIR), $(NAME))

all: $(NAME)

$(NAME): $(CSRCS) ./includes/
	gcc $(FLAGS) -c $(CSRCS) -I.
	ar rc $(NAME) $(COBJS)
	ranlib $(NAME)

debug: $(CSRCS) ./includes/
	gcc $(FLAGS) -g -c $(CSRCS) -I.
	ar rc $(NAME) $(COBJS)
	ranlib $(NAME)

clean:
	rm -f $(COBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
