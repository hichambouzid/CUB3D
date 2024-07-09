/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:55:30 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/09 12:25:10 by hibouzid         ###   ########.fr       */
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
	data->mlx_win = mlx_new_window(data->mlx, 600, 1080, "CUB3D");
	// mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	t_data data;
	(void)ac;
	(void)av;
	init_window(&data);
	while (1)
	{
		processInput(&data);
		// Updat();
		// runder();
	}
	mlx_loop(data.mlx);
}