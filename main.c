/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:55:30 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/09 23:26:00 by hibouzid         ###   ########.fr       */
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
	
	// mlx_loop(data->mlx);
}

// int get_coler(char c)
// {
// 	if (c == '0')
// 		return (0x808080);
// 	// else if (c == '1')
// 	return (0);
	
// }

void ft_put_pixel(t_data *data, int c)
{
	int i;
	int j;
	// int coler;

	i = data->y * 30;
	j = data->x * 30;
	// coler  = get_coler(c);
	printf("%d\n", c);
	while (i < (data->y * 30) + 30)
	{
		j = 0;
		while (j < (data->x * 30) + 30)
		{
			//  if (c == '1')
				mlx_pixel_put(data->mlx, data->mlx_win, i , j,c);
			//  if (c == '0')
			// 	 mlx_pixel_put(data->mlx, data->mlx_win,i, j , 0x00A0A0A0);
			j++;
		}
		usleep(2000);
		i++;
	}
}

void setup(t_data *data)
{
	data->y = 0;
	while (data->y < 5)
	{
		data->x = 0;
		while (data->x < ft_strlen(data->map[data->y]))
		{
			if (data->map[data->y][data->x] == '0')
			ft_put_pixel(data, 0x00A0A0A0);
			// else
			// ft_put_pixel(data, 0x00A0A0A0);
			
			data->x++;		
		}
		data->y++;
	}
	// data->x = 0;
	// data->y = 0;
	// mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	t_data data;
	(void)ac;
	(void)av;
	int i;
	i = 0;
	char *mapp[5] = {"111111",
					"100101",
					"101001",
					"1100N1",
					"111111"};
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