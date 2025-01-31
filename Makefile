#Name of the program
NAME	:= fdf

#Compilers and flags
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3

#Library
LIBFT	:= libs/libft
LIBMLX	:= libs/mlx42
GLFW	:= libs/glfw/build/src/libglfw3.a

#Directories
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a $(GLFW) -ldl -pthread -lm $(LIBFT)/libft.a

#Source files
SRCS	:= src/error_free.c src/fdf.c src/init.c src/utils.c src/color.c src/map.c src/camera.c src/line.c src/render.c
OBJS	:= ${SRCS:.c=.o}

#Rules
all: libmlx libft $(NAME)

libft: 
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

val:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=./sup.sup ./fdf ./maps/42.fdf > valgrind.log 2>&1

#Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

#Executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

#Clean Object 
clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

#Clean all generated files
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

#Recompile everything
re: clean all

.PHONY: all, clean, fclean, re, libmlx libft
