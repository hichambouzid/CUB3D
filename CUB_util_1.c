/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:18:23 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/20 12:22:45 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


float get_pi_Angle(char c)
{
    if (c == 'N')
        return (3 * M_PI / 2);
    if (c == 'S')
        return (M_PI / 2);
    if (c == 'W')
    return (M_PI);
        return (2 * M_PI);
}

void change_angle(float *angle, int flag)
{
    if (flag == 1)
    {
        *angle += 5 * (M_PI / 180);
        if (*angle > 2 * M_PI)
            *angle = 0;
    }
    else
    {
        *angle -= 4 * (M_PI / 180);
        if (*angle < 0)
            *angle = 2 * M_PI;
    }
    
}

// void get_s(float Angle, float *start)
// {
//     float tmp;

//     tmp = (30 * PI) / 180;
//     *start = Angle;
    
    
// }

void draw_fov(t_data *data)
{
    float tmp;
    float i;
    
    i = data->rotationAngle;
    tmp = ((30 * M_PI) / 180) + i;
    while (i < tmp)
    {
        render_line(data, i);
        i += 0.001;
    }
    tmp = data->rotationAngle - ((30 * M_PI) / 180);
    while (tmp <= data->rotationAngle)
    {
        render_line(data, tmp);
        tmp += 0.001;
    }
    // render(data);
}