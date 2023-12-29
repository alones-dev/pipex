# Base
NAME		=	pipex
CC			=	cc
FLAGS		=	-g3 -Wall -Wextra -Werror

# Base compiled files
INC_FOLDER	=	inc/
SRC_FOLDER	=	srcs/
SRC_FILES	=	path.c main.c
OBJS		=	$(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))

# Printf part
PRINTF_PATH =	ft_printf/
PRINTF_LIB	=	$(PRINTF_PATH)libftprintf.a

# Libft part
LIBFT_PATH	=	libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a

# Colors
DEFAULT		=	\033[0;39m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

# Compile part
%.o: %.c
	@echo "$(YELLOW)- Compiling $<$(DEFAULT)"
	@$(CC) $(FLAGS) -I$(INC_FOLDER) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -c $< -o $@

$(NAME): 	$(OBJS)
	@make -C $(LIBFT_PATH) --no-print-directory -s
	@make -C $(PRINTF_PATH) --no-print-directory -s
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)
	@echo "$(GREEN)♫ $(NAME) compiled successfully! ♫$(DEFAULT)"

# Mandatory rules
all:		$(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_PATH) --no-print-directory -s
	@make clean -C $(PRINTF_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) cleaned successfully! ♫$(DEFAULT)"

fclean:		clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) --no-print-directory -s
	@make fclean -C $(PRINTF_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) executable files cleaned! ♫$(DEFAULT)"

re:			fclean all
			@echo "$(GREEN)♫ $(NAME) recompiled successfully! ♫$(DEFAULT)"

.PHONY:		all clean fclean re norm