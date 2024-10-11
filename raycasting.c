/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:19:15 by hibouzid          #+#    #+#             */
/*   Updated: 2024/10/11 17:35:34 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	deltas(float *delta_x, float *delta_y, float ang)
{
	if (cos(ang) == 0)
		*delta_x = INFINITY;
	else
		*delta_x = fabs(1 / cos(ang));
	if (sin(ang) == 0)
		*delta_y = INFINITY;
	else
		*delta_y = fabs(1 / sin(ang));
}

static float	stepx(float ang, int *step, t_data *data, float delta)
{
	data->tmp_a = (32 + (data->f * CUB_SIZE));
	if (cos(ang) < 0)
	{
		*step = -1;
		return ((data->tmp_a - floor(data->tmp_a)) * delta);
	}
	*step = 1;
	return ((ceil(data->tmp_a) - data->tmp_a) * delta);
}

static float	stepy(float ang, int *step, t_data *data, float delta)
{
	data->tmp_b = (32 + (data->z * CUB_SIZE));
	if (sin(ang) < 0)
	{
		*step = -1;
		return ((data->tmp_b - floor(data->tmp_b)) * delta);
	}
	*step = 1;
	return ((ceil(data->tmp_b) - data->tmp_b) * delta);
}

static int	should_stop(float tmp_a, float tmp_b, t_data *data)
{
	if ((int)floor(tmp_b / CUB_SIZE) > 0 && (int)floor(tmp_a / CUB_SIZE) > 0
		&& (int)floor(tmp_a
			/ CUB_SIZE) < (int)ft_strlen(data->map[(int)floor(tmp_b
				/ CUB_SIZE)]) && (int)floor(tmp_b
			/ CUB_SIZE) < ft_strleen(data->map) && (data->map[(int)floor(tmp_b
				/ CUB_SIZE)][(int)floor(tmp_a / CUB_SIZE)] != '1'
			&& data->map[(int)floor(tmp_b / CUB_SIZE)][(int)floor(tmp_a
				/ CUB_SIZE)] != ' '))
		return (1);
	return (0);
}

float	raycasting(t_data *data, float ang, int *v_f)
{
	int		step_y;
	int		step_x;
	float	in_x;
	float	in_y;

	deltas(&data->deltax, &data->deltay, ang);
	in_x = stepx(ang, &step_x, data, data->deltax);
	in_y = stepy(ang, &step_y, data, data->deltay);
	while (should_stop(data->tmp_a, data->tmp_b, data))
	{
		if (in_x < in_y)
		{
			in_x += data->deltax;
			data->tmp_a += step_x;
			if (step_x == 1)
			{
				data->params->texture_offset = fmod(data->tmp_b, CUB_SIZE);
				*v_f = 1;
			}
			else
			{
				data->params->texture_offset = fmod(data->tmp_b, CUB_SIZE);
				*v_f = 2;
			}
		}
		else
		{
			in_y += data->deltay;
			data->tmp_b += step_y;
			if (step_y == 1)
			{
				data->params->texture_offset = fmod(data->tmp_a, CUB_SIZE);
				*v_f = 3;
			}
			else
			{
				data->params->texture_offset = fmod(data->tmp_a, CUB_SIZE);
				*v_f = 4;
			}
		}
	}
	return (sqrt(powf(data->tmp_a - (32 + (data->f * CUB_SIZE)), 2)
			+ powf(data->tmp_b - (32 + (data->z * CUB_SIZE)), 2)));
}
