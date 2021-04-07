NAME	 = minrt
DNAME	= minrtd
CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror
INCLUDE  = -I ./
MAKE 	 = make
LIBFT	 = ../../libft/libft.a
GNL	= libgnl.a
GNLF	= get_next_line_utils.c\
get_next_line.c\

MLXD	= ../mlx
LIBFTD	= ../../libft
GNLD	= ./
DEBUG	= -g3 -fsanitize=address
FRAME	= -lmlx -framework OpenGL -framework AppKit

GNLO	= $(GNLF:.c=.o)

all : $(NAME)

debug : $(DNAME)

$(NAME) :  $(LIBFT) $(GNL) $(MLXD)
	$(CC)  -L $(LIBFTD) -lft -L $(GNLD) -lgnl -L $(MLXD)  $(FRAME)  minirt_2.c 

$(DNAME) : $(GNL) $(LIBFT) $(MLXD)
	$(CC) $(CFLAGS) $(DEBUG) -L $(LIBFTD) -lft -L $(GNLD) -lgnl -L $(MLXD)  $(FRAME)  minirt_2.c 
	
clean :
		$(MAKE) -C ../../libft clean
		rm -rf $(GNLO)
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

$(LIBFT) :
		$(MAKE) -C ../../libft all
		cp $(LIBFT) ./$(NAME)
.c.o : $(GNLF)
	$(CC) $(CFLAGS) -c -o $@ $<

$(GNL) : $(GNLO)
	ar rc $(GNL) $(GNLO) 

fclean : clean
		$(MAKE) -C ../../libft fclean
		rm -rf $(NAME)
re : fclean all

test : all
	./a.out test.rt

de : debug
	$(DNAME) test.rt get_next_line.c get_next_line_utils.c get_next_line.h
.PHONY : all clean fclean re test
