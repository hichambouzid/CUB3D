/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:19:15 by hibouzid          #+#    #+#             */
/*   Updated: 2024/09/05 23:10:32 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
// #include <math.h>
#include "cub3D.h"

int raycasting(t_data *data, float ang)
{
    // float angle = data->angle;
    float dx = cos(ang);
    float dy = sin(ang);
    float tmp_a = (32 + (data->f * CUB_SIZE));
    float tmp_b = (32 + (data->z * CUB_SIZE));
    float a = tmp_a;
    float b = tmp_b;
    int step_x, step_y;
    float deltax, deltay;
    float in_x, in_y;
    float distx, disty;
    // int map_x, map_y;


    deltax = fabs(1 / dx);
    deltay = fabs(1 / dy);
    if (dx < 0)
    {
        step_x = -1;
        in_x = (tmp_a - floor(tmp_a))* deltax;
    }
    else
    {
        step_x = 1;
        in_x = (ceil(tmp_a) - tmp_a) * deltax;
    }

    if (dy < 0)
    {
        step_y = -1;
        in_y = (tmp_b - floor(tmp_b)) * deltay;
    }
    else
    {
        step_y = 1;
        in_y = (ceil(tmp_b) - tmp_b) * deltay;
    }
    distx = (in_x - tmp_a) / fabs(dx);
    disty = (in_y - tmp_b) / fabs(dy);
	if (distx < 0)
		distx *=-1;
	if (disty < 0)
		disty *=-1;


    while ((data->map[(int)(tmp_b / CUB_SIZE)][(int)(tmp_a / CUB_SIZE)] != '1' &&
		data->map[(int)(tmp_b / CUB_SIZE)][(int)(tmp_a / CUB_SIZE)] != ' '))
	 {
        // map_x = (int)(tmp_a / CUB_SIZE) ;
        // map_y = (int)(tmp_b / CUB_SIZE);
		// printf("-=-= %d\n", map_y);
		// printf("-=-= %d\n", map_x);
        if (in_x <= in_y)
        {
            a = in_x;
            // b = tmp_b + (a - tmp_a) * (dy / dx);
            in_x += deltax * 0.04;
			tmp_a += step_x * 0.04;
        }
        else
        {
            b = in_y;
            in_y += deltay * 0.04;
            tmp_b += step_y * 0.04;
        }
    }
	if (in_x <= in_y)
		return (in_x);
    return in_y;
}


/**
int raycasting(t_data *data)
{
	int dx = cos(data->ang);
	int dy = sin(data->ang);
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