/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_h00k.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:22:51 by hibouzid          #+#    #+#             */
/*   Updated: 2024/09/02 10:38:38 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_close(int key)
{
	(void)key;
	exit(1);
	return (1);
}

int	key_hook(int key, t_data *data)
{
	if (key == 65307)
	{
		ft_free_table(data->map);
		mlx_destroy_image(data->mlx, data->mlx_3d);
		mlx_destroy_image(data->mlx, data->params->northh);
		mlx_destroy_image(data->mlx, data->params->eastt);
		mlx_destroy_image(data->mlx, data->params->westt);
		mlx_destroy_image(data->mlx, data->params->southh);
		mlx_destroy_window(data->mlx, data->mlx_win);
		// free(data->params->southh);
		// free(data->params->eastt);
		// free(data->params->northh);
		free(data->params);
		free(data);
		exit(1);
	}
	if (key == 97 || key == 100 || key == 119 || key == 115)
		allow_render(data, key);
	else if (key == 65361)
		change_angle(&data->rotation_angle, -1, data);
	else if (key == 65363)
		change_angle(&data->rotation_angle, 1, data);
	else if (key == 65505)
	{
		if (data->flag == 0)
			data->flag = 1;
		else
			data->flag = 0;
		render(data);
	}
	return (1);
}

int	key_releas(int key, t_data *data)
{
	(void)data;
	printf("key %d\n", key);
	if (key == 119)
		return (0);
	return (1);
}

int	processinput(t_data *data)
{
	mlx_hook(data->mlx_win, 02, 17, key_hook, data);
	mlx_mouse_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, NULL);
	return (0);
}
