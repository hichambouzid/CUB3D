/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:52:42 by hibouzid          #+#    #+#             */
/*   Updated: 2024/10/11 15:07:50 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	increment_x_y(t_data *data, float x, float y, float Angle)
{
	if (x > 1 && ((data->map[(int)(y / CUB_SIZE)][(int)((x / CUB_SIZE)
			+ ((cos(Angle) * 0.05) * 0.01))] != '1')
			|| data->map[(int)(y / CUB_SIZE)][(int)((x / CUB_SIZE)
				- ((cos(Angle) * 0.05) * 0.01))] != '1'))
		return (0);
	return (1);
}

int	check_vr_hr(t_data *data, float x, float y, float Angle)
{
	if (data->map[(int)(y / CUB_SIZE)][(int)(x / CUB_SIZE)] == '1')
		return (increment_x_y(data, x, y, Angle));
	else if (data->map[((int)((y / CUB_SIZE) - 1))][((int)(x / CUB_SIZE)
			+ 1)] == '1')
		return (increment_x_y(data, x + 1, y - 1, Angle));
	return (increment_x_y(data, x - 1, y + 1, Angle));
}

float	render_line(t_data *data, float Angle, int *v_f)
{
	float	distence;

	distence = raycasting(data, Angle, v_f);
	return ((distence));
}

void	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlx_3d);
	data->mlx_3d = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	get_img_data(data, WIDTH, HEIGHT);
	draw_fov(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_3d, 0, 0);
}
