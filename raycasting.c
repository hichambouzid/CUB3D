/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:19:15 by hibouzid          #+#    #+#             */
/*   Updated: 2024/09/04 16:02:28 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
// #include <math.h>
#include "cub3D.h"

int raycasting(t_data *data)
{
    float angle = data->angle;
    float dx = cos(angle);
    float dy = sin(angle);
    float tmp_a = 32 + (data->f * CUB_SIZE);
    float tmp_b = 32 + (data->z * CUB_SIZE);
    float a = tmp_a;
    float b = tmp_b;
    float step_x, step_y;
    float deltax, deltay;
    float in_x, in_y;
    float distx, disty;
    int map_x, map_y;

    deltax = fabs(CUB_SIZE / dx);
    deltay = fabs(CUB_SIZE / dy);

    if (dx < 0)
    {
        step_x = -CUB_SIZE;
        in_x = (tmp_a - floor(tmp_a / CUB_SIZE) * CUB_SIZE) * deltax;
    }
    else
    {
        step_x = CUB_SIZE;
        in_x = (ceil(tmp_a / CUB_SIZE) * CUB_SIZE - tmp_a) * deltax;
    }

    if (dy < 0)
    {
        step_y = -CUB_SIZE;
        in_y = (tmp_b - floor(tmp_b / CUB_SIZE) * CUB_SIZE) * deltay;
    }
    else
    {
        step_y = CUB_SIZE;
        in_y = (ceil(tmp_b / CUB_SIZE) * CUB_SIZE - tmp_b) * deltay;
    }

    distx = (in_x - tmp_a) / fabs(dx);
    disty = (in_y - tmp_b) / fabs(dy);

    while (1)
    {
        map_x = (int)(in_x / CUB_SIZE);
        map_y = (int)(in_y / CUB_SIZE);

        if (data->map[map_y][map_x] == '1' || data->map[map_y][map_x] == ' ')
            break;

        if (distx < disty)
        {
            a = in_x;
            b = tmp_b + (a - tmp_a) * (dy / dx);
            in_x += step_x;
            distx += deltax;
        }
        else
        {
            b = in_y;
            a = tmp_a + (b - tmp_b) * (dx / dy);
            in_y += step_y;
            disty += deltay;
        }
    }

    // Calculate the distance from the player's position to the wall
    float distance = sqrtf(powf(a - tmp_a, 2) + powf(b - tmp_b, 2));
    return distance;
}


/**
int raycasting(t_data *data)
{
	int dx = cos(data->angle);
	int dy = sin(data->angle);
	int tmp_a = 32 + (data->f * (CUB_SIZE));
	int tmp_b = 32 + (data->z * (CUB_SIZE));
	int a = 32 + (data->f * (CUB_SIZE));
	int b = 32 + (data->z * (CUB_SIZE));
	int step_x;
	int step_y;
	float deltax;
	float deltay;
	float in_x;
	float in_y;
	float distx;
	float disty;
	deltax = fabs(CUB_SIZE / cos(data->angle));
	deltay = fabs(CUB_SIZE / sin(data->angle));

	if (cos(data->angle) < 0)
	{
		step_x = -CUB_SIZE;
		in_x = (tmp_a - floor(tmp_a) * deltax) ;	
	}
	else
	{
		step_x = CUB_SIZE;
		in_x = ((ceil(tmp_a) - tmp_a) * deltax);	
	}
	if (sin(data->angle) < 0)
	{
		step_y = -CUB_SIZE;
		in_y = (tmp_b - floor(tmp_b) * deltay) ;	
	}
	else
	{
		step_y = CUB_SIZE;
		in_y = ((ceil(tmp_b) - tmp_b) * deltay);	
	}
	distx = (in_x - tmp_a) / fabs(dx);
	disty = (in_y - tmp_b) / fabs(dy);
	while (1)
	{
		if (data->map[(int)in_y / CUB_SIZE][(int)in_y / CUB_SIZE] == '1' ||
			data->map[(int)in_y / CUB_SIZE][(int)in_y / CUB_SIZE] == ' ')
			break ;
			if (distx < disty)
			{
				a = in_x;
				b = tmp_b + (a - tmp_a) * (dy / dx);
				in_x += step_x;
				distx += deltax;
			}
			else 
			{
				
				b = in_y;
				a = tmp_a + (b - tmp_b) * (dy / dx);
				in_y += deltay;
				disty += step_y;
			}
	}
	return (sqrt(a - tmp_a) * (a - tmp_a) * (b - tmp_b) * (b - tmp_b));
}
*/