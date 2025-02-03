# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 12:12:28 by cayamash          #+#    #+#              #
#    Updated: 2025/02/03 17:25:45 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the program
NAME		:= fdf
NAME_BONUS	:= fdf_bonus

#Compilers and flags
CC			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3

#Library
LIBFT		:= libs/libft
LIBMLX		:= libs/MLX42

#Directories
HEADERS		:= -I include/ -I $(LIBMLX)/include -I $(LIBFT)
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

#Source files
SRCS		:= mandatory/error_free.c mandatory/init.c mandatory/utils.c \
				mandatory/color_utils.c mandatory/color.c mandatory/map.c\
				mandatory/camera.c mandatory/line.c mandatory/render.c \
				mandatory/main.c
SRCS_BONUS	:= bonus/key_handler_bonus.c bonus/error_free_bonus.c bonus/init_bonus.c \
				bonus/utils_bonus.c bonus/color_utils_bonus.c bonus/color_bonus.c \
				bonus/map_bonus.c bonus/camera_bonus.c bonus/line_bonus.c bonus/rotate_bonus.c \
				bonus/projections1_bonus.c bonus/projections2_bonus.c bonus/render_bonus.c \
				bonus/main_bonus.c
OBJS		:= ${SRCS:.c=.o}
OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}

#Valgrind
VALGRIND	:= valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=./sup.sup

#Rules
all: libmlx libft $(NAME)

libft: 
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

bonus: $(NAME_BONUS)

val:
	$(VALGRIND) ./fdf ./maps/42.fdf > valgrind.log 2>&1

val_bonus:
	$(VALGRIND) ./fdf_bonus ./maps/42.fdf > valgrind.log 2>&1

#Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

#Executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

#Clean Object 
clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

#Clean all generated files
fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT) fclean

#Recompile everything
re: fclean all

.PHONY: all, clean, fclean, re, libmlx libft
