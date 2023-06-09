# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 22:04:57 by mevangel          #+#    #+#              #
#    Updated: 2023/06/02 23:21:49 by mevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CFLAGS := -Wall -Wextra -Werror

CC := cc

SRCS := ft_printf.c printing_functions.c

OBJS := $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
