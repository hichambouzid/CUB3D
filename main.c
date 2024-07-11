/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:55:30 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/11 19:43:08 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int get_coler(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xFBF7F4);
	if (c == '1')
		return (0);
	return (0x00808080);
	
}

void draw_square(t_data *data)
{
	int coler;
	int i;
	int j;

	coler = get_coler(data->map[data->y][data->x]);
	j = data->y * 20;
	while (j < (data->y * 20) + 20)
	{
		i = data->x * 20;
		while (i < (data->x * 20) + 20)
		{
			if (((i % 20 == 0 || j % 20 == 0)
				&& data->map[data->y][data->x] != ' '))
				put_pixel_to_image(data, i, j, 0x00808080);
			else 
				put_pixel_to_image(data, i, j, coler);
			i++;
		}
		j++;
	}
}

void setup(t_data *data)
{
	 data->y = 0;
	 while (data->y < ft_strleen(data->map))
	{
		data->x = 0;
		while (data->map[data->y][data->x])
		{
			draw_square(data);
			data->x++;
		}
		data->y++;
	}
}

void runder(t_data *data)
{
	get_cordinate(data);
	printf("---> %d\n", data->x);
	printf("-----------%d-----\n", data->y);
	// put_pixel_to_image(data, data->x * 20 + 10, data->y * 20 + 10 , 0x00FF0000);
	draw_mini_square(data);
}

int main(int ac, char **av)
{
	t_data data;
	(void)ac;
	(void)av;
	int i;
	i = 0;
	char *mapp[] = {
"        1111111111111111111111111",
"        1000000000110000000000001",
"        1011000001110000000000001",
"        1001000000000000000000001",
"111111111011000001110000000000001",
"100000000011000001110111111111111",
"11110111111111011100000010001",
"11110111111111011101010010001",
"11000000110101011100000010001",
"10000000000000001100000010001",
"10000000000000001101010010001",
"11000001110101011111011110N0111",
"11110111 1110101 101111010001",
"11111111 1111111 111111111111",
	NULL};
	data.map = mapp;
	// (void)mapp;
	init_window(&data);
	setup(&data);
	while (1)
	{
		processInput(&data);
		// printf("===========\n");
		// mlx_pixel_put(data.mlx, data.mlx_win, 1600 / 2, 1000/ 2,0xFFFFFF);
		runder(&data);
		// i++;
		// Updat();
	mlx_loop(data.mlx);
	}
}