# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 12:12:28 by cayamash          #+#    #+#              #
#    Updated: 2025/02/04 14:30:30 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the program
NAME			:= fdf
NAME_BONUS		:= fdf_bonus

#Compilers and flags
CC				:= cc
CFLAGS			:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3

#Library
LIBFT			:= libs/libft
LIBMLX			:= libs/MLX42

#Directories
HEADERS			:= -I include/ -I $(LIBMLX)/include -I $(LIBFT)
LIBS			:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

#Source files
SRCS_DIR		:= mandatory/
SRCS_BONUS_DIR	:= bonus/
SRCS			:= $(addprefix $(SRCS_DIR), error_free.c init.c utils.c \
				color_utils.c color.c map.c	camera.c line.c render.c main.c)
SRCS_BONUS		:= $(addprefix $(SRCS_BONUS_DIR), key_handler_bonus.c \
				error_free_bonus.c init_bonus.c utils_bonus.c color_utils_bonus.c \
				color_bonus.c map_bonus.c camera_bonus.c line_bonus.c rotate_bonus.c \
				projections1_bonus.c projections2_bonus.c render_bonus.c main_bonus.c)
OBJ_DIR			:= obj
OBJ_BONUS_DIR	:= obj_bonus
OBJS			:= $(SRCS:$(SRCS_DIR)%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS		:= $(SRCS_BONUS:$(SRCS_BONUS_DIR)%.c=$(OBJ_BONUS_DIR)/%.o)

#Valgrind
VALGRIND		:= valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=./sup.sup

#Style
NO_PRINT		:= --no-print-directory
CYAN			:= \033[1;36m
GREEN			:= \033[1;32m
RED     		:= \033[1;31m
YELLOW  		:= \033[1;33m
MAGENTA 		:= \033[1;35m
BLUE    		:= \033[1;34m
END				:= \033[0m

#Rules
all: libmlx libft $(NAME)

libft: 
	@make -C $(LIBFT) $(NO_PRINT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 $(NO_PRINT)

bonus: libmlx libft $(NAME_BONUS)

val:
	$(VALGRIND) ./fdf ./maps/teste.fdf > valgrind.log 2>&1

val_bonus:
	$(VALGRIND) ./fdf_bonus ./maps/teste.fdf > valgrind.log 2>&1

norm:
	@echo "\n$(CYAN)======= LIBFT =======$(END)"
	@norminette libs/libft | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(YELLOW)======= MANDATORY =======$(END)"
	@norminette mandatory | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(MAGENTA)======= BONUS =======$(END)"
	@norminette bonus | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(BLUE)======= INCLUDES =======$(END)"
	@norminette include | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/Error/\x1b[1;31m&\x1b[0m/g'

#Compile object files
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(OBJ_BONUS_DIR)/%.o: $(SRCS_BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

#Executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)Mandatory Compiled!$(END)"	

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)
	@echo "$(GREEN)Bonus Compiled!$(END)"

#Clean Object 
clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean $(NO_PRINT)
	@echo "$(GREEN)Cleaned$(END)"

#Clean all generated files
fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT) fclean $(NO_PRINT)
	@rm -f valgrind.log
	@echo "$(GREEN)All!$(END)"

#Recompile everything
re: fclean all

.PHONY: all clean fclean re libmlx libft
