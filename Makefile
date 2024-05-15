# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:56:58 by akeldiya          #+#    #+#              #
#    Updated: 2024/05/13 01:33:10 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Folders
FUNC = functions

# Files
SRCS	= main.c   $(FUNC)/stack_func.c    $(FUNC)/error_n_free.c \
		$(FUNC)/make_stack.c    $(FUNC)/commands.c  $(FUNC)/commands2.c \
		$(FUNC)/tiny_sort.c     $(FUNC)/push_swap.c $(FUNC)/push_swap_func.c

# Sources and objects
OBJS	:= $(SRCS:%.c=%.o)

# Constant strings

NAME	= push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

INCLULIBFT = -Ilibft

# Rules

all: $(NAME)

%.o:	%.c
		${CC} ${CFLAGS} $(INCLULIBFT) -c $< -o $@

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(INCLULIBFT) -o $(NAME) $(OBJS) -Llibft -lft

libft:
	make -C libft

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean:		clean
	make fclean -C libft
	${RM} $(NAME)

re: fclean all

.PHONY:	 all clean fclean re libft
