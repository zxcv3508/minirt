NAME = minirt
DNAME = minrtd
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
DEBUG_FLAG = -g3 -fsanitize=address
LIBFTD = ./lib/libft
LIBFT = libft.a
SRC = minirt_2.c
SRCD = ./src
MLXD = ./lib/mlx
MLX = libmlx.a
INCLUDE = -I $(MLXD) -I $(LIBFTD) -I ./include
FRAME = -framework OpenGL -framework AppKit
MAKE = make

all : $(NAME)

clean :
		$(MAKE) -C $(LIBFTD) clean
		$(MAKE) -C $(MLXD) clean
fclean : clean
		$(MAKE) -C $(LIBFTD) fclean
		rm -rf $(NAME)
re : fclean all

debug : $(DNAME)

detest : debug
	./$(DNAME) ./rt/test.rt

test : all
	./$(NAME) ./rt/test.rt

$(NAME) : $(LIBFTD)/$(LIBFT) $(MLXD)/$(MLX)
	cd ./HEADING_42 && ./heading42.sh
	$(CC) $(CFLAGS) -L $(LIBFTD) -lft -L $(MLXD) -lmlx $(FRAME) $(INCLUDE) -o $@ $(SRCD)/$(SRC)

$(DNAME) :  $(LIBFTD)/$(LIBFT) $(MLXD)/$(MLX)
	cd ./HEADING_42 && ./heading42.sh
	$(CC) $(CFLAGS) $(DEBUG_FLAG) -L $(LIBFTD) -lft -L $(MLXD) -lmlx $(FRAME) $(INCLUDE) -o $@ $(SRCD)/$(SRC)
$(LIBFTD)/$(LIBFT) :
	$(MAKE) -C $(LIBFTD) all
$(MLXD)/$(MLX) :
	$(MAKE) -C $(MLXD) all
.PHONY : all clean fclean re test debug detest
