NAME = cub3D

CFLAGS = -Wall -Wextra -Werror  -I ./minilibx_mms_20200219 -Imlx_linux -O3

#main.c key_h00k.c mlx_img.c
CFILS = key_h00k.c  main.c  mlx_img.c CUB_util_0.c render_all.c CUB_util_1.c 


OBJS = $(CFILS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
		cc $(OBJS) -fsanitize=address -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all