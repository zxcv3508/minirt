NAME = minirt
DNAME = minrtd
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
DEBUG_FLAG = -g3 -fsanitize=address
LIBFTD = ./lib/libft
LIBFT = libft.a
SRC = main.c\
	minirt.c\
	vec_util.c\
	parsing.c\
	parsing_type_1.c\
	parsing_type_2.c\
	parsing_util_tool.c\
	parsing_util_save.c\
	parsing_util_init.c\
	parsing_util_free.c\
	render.c\
	render_cam.c\
	render_util.c\
	hit.c\
	hit_type.c\
	lighting.c\
	ray_color.c\




SRCD = ./src/
SRCM = $(addprefix $(SRCD), $(SRC))
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

dtest : debug
	./$(DNAME) ./rt/test.rt

test : all
	./$(NAME) ./rt/test.rt

$(NAME) : $(LIBFTD)/$(LIBFT) $(MLXD)/$(MLX)
	cd ./HEADING_42 && ./heading42.sh
	$(CC) $(CFLAGS) -L $(LIBFTD) -lft -L $(MLXD) -lmlx $(FRAME) $(INCLUDE) -o $@ $(SRCM)

$(DNAME) :  $(LIBFTD)/$(LIBFT) $(MLXD)/$(MLX)
	cd ./HEADING_42 && ./heading42.sh
	$(CC) $(CFLAGS) $(DEBUG_FLAG) -L $(LIBFTD) -lft -L $(MLXD) -lmlx $(FRAME) $(INCLUDE) -o $@ $(SRCM)
$(LIBFTD)/$(LIBFT) :
	$(MAKE) -C $(LIBFTD) all
$(MLXD)/$(MLX) :
	$(MAKE) -C $(MLXD) all
.PHONY : all clean fclean re test debug detest
