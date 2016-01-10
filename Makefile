# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 08:41:32 by qdegraev          #+#    #+#              #
#    Updated: 2015/12/17 18:54:02 by afillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = libft
LIB = $(LIBPATH)/libft.a

NAME= fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft

LDFLAGS = -L libft -lft

SRC = \
	ft_fill_board.c \
	ft_free.c \
	ft_lstlen.c \
	ft_small_square.c \
	ft_taballoc.c \
	list.c \
	main.c \
	make_pieces.c \
	record_check_file.c

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	make -C $(LIBPATH)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBPATH)

re: fclean all
