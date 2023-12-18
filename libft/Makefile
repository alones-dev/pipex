# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 14:07:32 by kdaumont          #+#    #+#              #
#    Updated: 2023/12/06 13:00:05 by kdaumont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FILES_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_dlstadd_back.c ft_dlstadd_front.c \
				ft_dlstclear.c ft_dlstdelone.c ft_dlstiter.c ft_dlstlast.c ft_dlstmap.c ft_dlstnew.c ft_dlstsize.c
C_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c $(C_FILES_BONUS)
  

OBJS_FILES = $(C_FILES:.c=.o)
OBJS_FILES_BONUS = $(C_FILES_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME):${OBJS_FILES}
	ar rcs $(NAME) $(OBJS_FILES)

all: $(NAME)

bonus: $(OBJS_FILES) $(OBJS_FILES_BONUS)
		ar rcs $(NAME) $(OBJS_FILES) $(OBJS_FILES_BONUS)

clean:
		rm -rf $(OBJS_FILES) $(OBJS_FILES_BONUS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(C_FILES)
	gcc -nostartfiles -shared -o libft.so $(OBJS_FILES)
