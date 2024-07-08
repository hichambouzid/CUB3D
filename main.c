/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:55:30 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/08 16:55:26 by hibouzid         ###   ########.fr       */
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
		ft_putstr_fd(2, "error: canno't initializ windows\n");
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "CUB3D");
	mlx_loop(data->mlx);
}

void processInput()
{
	// listing to ky board
}

int main(int ac, char **av)
{
	t_data data;
	
	init_window(&data);
	while (1)
	{
		proccesInput();
		Updat();
		runder();
	}
}