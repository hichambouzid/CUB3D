/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:55:30 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:24 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

void init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("error: canno't initializ windows\n", 2);
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx, 1600, 1000, "CUB3D");
	data->mlx_img = mlx_new_image(data->mlx, 1600, 1000);
	get_img_data(data, 1600, 1000);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	// mlx_loop(data->mlx);
}

// int get_coler(char c)
// {
// 	if (c == '0')
// 		return (0x808080);
// 	// else if (c == '1')
// 	return (0);
	
// }

void draw_square(t_data *data)
{
	int coler;
	int i;
	int j;

	if (data->map[data->x] == '1')
		coler = 0;
	else if (data->map[data->x] == '0')
		coler = 0xFBF7F4;
	else
		coler = 0x00808080;
	j = data->y * 20;
	while (j < (data->y * 20) + 20)
	{
		i = data->x * 20;
		while (i < (data->x * 20) + 20)
		{
			put_pixel_to_image(data, i, j, coler);
			i++;
		}
		j++;
	}
}

void setup(t_data *data)
{
	 data->y = 0;
	 while (data->y < 14)
	{
		data->x = 0;
		while (data->map[data->x] != '\n' && data->map[data->x])
		{
			draw_square(data);
			data->x++;
		}
		data->map += data->x + 1;
		data->y++;
	}
}

int main(int ac, char **av)
{
	t_data data;
	(void)ac;
	(void)av;
	int i;
	i = 0;
	char *mapp = 
"       1111111111111111111111111\n       1000000000110000000000001\n       1011000001110000000000001\n       1001000000000000000000001\n111111111011000001110000000000001\n100000000011000001110111111111111\n11110111111111011100000010001\n11110111111111011101010010001\n11000000110101011100000010001\n10000000000000001100000010001\n10000000000000001101010010001\n11000001110101011111011110N0111\n11110111 1110101 101111010001\n11111111 1111111 111111111111";

	data.map = mapp;
	// (void)mapp;
	init_window(&data);
	setup(&data);
	while (1)
	{
		processInput(&data);
		// mlx_pixel_put(data.mlx, data.mlx_win, 1600 / 2, 1000/ 2,0xFFFFFF);
		i++;
		// Updat();
		// runder();
	}
	mlx_loop(data.mlx);
}