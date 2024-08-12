/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:52:42 by hibouzid          #+#    #+#             */
/*   Updated: 2024/08/12 19:58:30 by hibouzid         ###   ########.fr       */
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

int increment_x_y(t_data *data, float x, float y)
{
	if (((x > 4 && check_coler(data, x - 4, y))|| check_coler(data, x + 4, y)))
		return (0);
	return (1);
}

int check_vr_hr(t_data *data, float x, float y)
{
	if (!check_coler(data, x, y))
		return (increment_x_y(data, x, y));
	else if (!check_coler(data, x - 1, y - 1))
		return (increment_x_y(data, x - 1, y -1));
	else if (!check_coler(data, x + 1, y - 1))
		return (increment_x_y(data, x + 1, y - 1));
	return (increment_x_y(data, x - 1, y + 1));
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
		if (!check_coler(data, a_tmp, b_tmp) || !check_coler(data, a_tmp - 1,
				b_tmp - 1) || !check_coler(data, a_tmp + 1, b_tmp - 1)
			|| !check_coler(data, a_tmp - 1, b_tmp + 1))
			break ;
		put_pixel_to_image(data, a_tmp, b_tmp, 0x00FF0000);
		b_tmp += (sin(Angle) * 0.05) * 5;
		a_tmp += (cos(Angle) * 0.05) * 5;
	}
	*v_f = check_vr_hr(data, a_tmp, b_tmp);
	printf("----> %d\n", *v_f);
	return (sqrtf(powf(((a_tmp - save_a)), 2) + powf(((b_tmp - save_b)), 2)));
}

void	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlx_img);
	mlx_destroy_image(data->mlx, data->mlx_3D);
	data->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->mlx_3D = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->flag != 0)
		data->mlx_tmp = data->mlx_img;
	else
		data->mlx_tmp = data->mlx_3D;
	get_img_data(data, WIDTH, HEIGHT);
	setup(data);
	draw_mini_square(data);
	draw_fov(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_tmp, 0, 0);
}
