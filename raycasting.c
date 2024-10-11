/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:19:15 by hibouzid          #+#    #+#             */
/*   Updated: 2024/10/11 15:24:32 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	raycasting(t_data *data, float ang, int *v_f)
{
	float	tmp_a;
	float	tmp_b;
	int step_x, step_y;
	float deltax, deltay;
	float in_x, in_y;

	tmp_a = (32 + (data->f * CUB_SIZE));
	tmp_b = (32 + (data->z * CUB_SIZE));
	if (cos(ang) == 0)
		deltax = INFINITY;
	else
		deltax = fabs(1 / cos(ang));
	if (sin(ang) == 0)
		deltay = INFINITY;
	else
		deltay = fabs(1 / sin(ang));
	if (cos(ang) < 0)
	{
		step_x = -1;
		in_x = (tmp_a - floor(tmp_a)) * deltax;
	}
	else
	{
		step_x = 1;
		in_x = (ceil(tmp_a) - tmp_a) * deltax;
	}
	if (sin(ang) < 0)
	{
		step_y = -1;
		in_y = (tmp_b - floor(tmp_b)) * deltay;
	}
	else
	{
		step_y = 1;
		in_y = (ceil(tmp_b) - tmp_b) * deltay;
	}
	while ((int)floor(tmp_b / CUB_SIZE) > 0 && (int)floor(tmp_a / CUB_SIZE) > 0
		&& (int)floor(tmp_a
			/ CUB_SIZE) < (int)ft_strlen(data->map[(int)floor(tmp_b
				/ CUB_SIZE)]) && (int)floor(tmp_b
			/ CUB_SIZE) < ft_strleen(data->map) && (data->map[(int)floor(tmp_b
				/ CUB_SIZE)][(int)floor(tmp_a / CUB_SIZE)] != '1'
			&& data->map[(int)floor(tmp_b / CUB_SIZE)][(int)floor(tmp_a
				/ CUB_SIZE)] != ' '))
	{
		if (in_x < in_y)
		{
			in_x += deltax;
			tmp_a += step_x;
			if (step_x == 1)
			{
				data->params->texture_offset = fmod(tmp_b, CUB_SIZE);
				*v_f = 1;
			}
			else
			{
				data->params->texture_offset = fmod(tmp_b, CUB_SIZE);
				*v_f = 2;
			}
		}
		else
		{
			in_y += deltay;
			tmp_b += step_y;
			if (step_y == 1)
			{
				data->params->texture_offset = fmod(tmp_a, CUB_SIZE);
				*v_f = 3;
			}
			else
			{
				data->params->texture_offset = fmod(tmp_a, CUB_SIZE);
				*v_f = 4;
			}
		}
	}
	return (sqrt(powf(tmp_a - (32 + (data->f * CUB_SIZE)), 2) +
		powf(tmp_b - (32 + (data->z * CUB_SIZE)), 2)));
}
