/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:52:42 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/17 19:00:31 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_coler(t_data *data, int x, int y)
{
	char	*tmp;

	tmp = data->str + ((y * data->line_lenght + 4 * x));
	if (*(unsigned int *)tmp <= 0)
		return (0);
	return (1);
}

int	increment_x_y(t_data *data, float x, float y, float Angle)
{
	if (x > 1 && ((data->map[(int)(y / 20)][(int)((x / 20) + ((cos(Angle)
					* 0.05) * 0.4))] != '1') || data->map[(int)(y
				/ 20)][(int)((x / 20) - ((cos(Angle) * 0.05) * 0.4))] != '1'))
		return (0);
	return (1);
}

int	check_vr_hr(t_data *data, float x, float y, float Angle)
{
	if (data->map[(int)(y / 20)][(int)(x / 20)] == '1')
		return (increment_x_y(data, x, y, Angle));
	else if (data->map[((int)((y / 20) - 1))][((int)(x / 20) + 1)] == '1')
		return (increment_x_y(data, x + 1, y - 1, Angle));
	return (increment_x_y(data, x - 1, y + 1, Angle));
}

float	render_line(t_data *data, float Angle, int *v_f)
{
	float	a_tmp;
	float	b_tmp;
	float	save_a;
	float	save_b;

	a_tmp = 11 + (data->f * 20);
	b_tmp = 11 + (data->z * 20);
	save_a = 11 + (data->f * 20);
	save_b = 11 + (data->z * 20);
	while (1)
	{
		if (data->map[(int)(b_tmp / 20)][(int)(a_tmp / 20)] == '1')
			break ;
		b_tmp += (sin(Angle) * 0.05) * 5;
		a_tmp += (cos(Angle) * 0.05) * 5;
	}
	*v_f = check_vr_hr(data, a_tmp, b_tmp, Angle);
	while (data->map[(int)(b_tmp / 20)][(int)(a_tmp / 20)] == '1')
	{
		b_tmp -= (sin(Angle) * 0.05) * 2;
		a_tmp -= (cos(Angle) * 0.05) * 2;
	}
	if (*v_f == 1)
		data->params->texture_offset = fmod(a_tmp , 20);
	else
		data->params->texture_offset = fmod(b_tmp  , 20);
	return (sqrtf(powf(((a_tmp - save_a)), 2) + powf(((b_tmp - save_b)), 2)));
}

void	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlx_3D);
	data->mlx_3D = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	get_img_data(data, WIDTH, HEIGHT);
	draw_fov(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_3D, 0, 0);
}
