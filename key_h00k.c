/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_h00k.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:22:51 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/23 16:22:55 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int  ft_close(int key)
{
	(void)key;
		// todo : add  function that free all memory allocated
		exit(1);
		return (1);
}

int key_hook(int key, t_data *data)
{

	printf("key -> %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	if (key == 97 || key == 100 || key == 119 || key == 115)
		allow_render(data, key);
	else if (key == 65361)
	{
		change_angle(&data->rotationAngle, -1);
		render(data);
	}
	else if (key == 65363)
	{
		change_angle(&data->rotationAngle, 1);
		render(data);
	}
	else if (key == 65362)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	}
	return (1);
}

int processInput(t_data *data)
{
	// printf("==__+_+_+_\n");
	mlx_hook(data->mlx_win,2, 17,key_hook, data);
	mlx_mouse_hook(data->mlx_win, key_hook, data);
	// mlx_hook(data->mlx_win,3, 3,key_hook, data);
	mlx_hook(data->mlx_win,17, 0,ft_close, NULL);
	// mlx_loop_hook(data->mlx_win, );
	// mlx_loop(data->mlx);
	return (0);
}