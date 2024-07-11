/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_h00k.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:22:51 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/11 17:24:36 by hibouzid         ###   ########.fr       */
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
	if (key == 65362)
	{
		// mlx_clear_window(data->mlx, data->mlx_win);
		// mlx_destroy_image(data->mlx, data->mlx_img);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
	}
	return (1);
}

void processInput(t_data *data)
{
	mlx_hook(data->mlx_win,2, 17,key_hook, data);
	mlx_hook(data->mlx_win,17, 0,ft_close, NULL);

	// mlx_loop(data->mlx);
}