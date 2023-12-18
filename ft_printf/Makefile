# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:24:46 by kdaumont          #+#    #+#              #
#    Updated: 2023/11/14 09:36:31 by kdaumont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_FILES = ft_printf.c utils_printf.c utils_2_printf.c
  

OBJS_FILES = $(C_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME):${OBJS_FILES}
	ar rcs $(NAME) $(OBJS_FILES)

all: $(NAME)

clean:
		rm -rf $(OBJS_FILES)

fclean: clean
		rm -rf $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(C_FILES)
	gcc -nostartfiles -shared -o libft.so $(OBJS_FILES)