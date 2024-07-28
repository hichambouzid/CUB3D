/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB_util_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:18:23 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/28 19:06:49 by hibouzid         ###   ########.fr       */
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

void put_pixel_to_image1(t_data *data, int x, int y, int coler)
{
    char *tmp;
    
    tmp = data->str1 + (y * data->line_lenght + 4 * x);
    *(unsigned int *)tmp = coler;
}

void draw_ceiling(t_data *data, float end_y, float x)
{
    float start_y;
    (void)end_y;
    start_y = 0;
    while (start_y < HEIGHT / 2)
    {
        put_pixel_to_image1(data,  x, start_y, 0x00FF0000);
        start_y++;
    }    
}

void draw_walls(t_data *data, float height_wall, float x)
{
    float start_y;
    float end_y;
    int i = 0;
    // start_y = height_wall / 2;
    // end = ((HEIGHT - height_wall) / 2);
    
    if (height_wall >= HEIGHT)
    {
        start_y = 0;
        end_y = HEIGHT;
    }
    else
    {
        start_y = (HEIGHT - height_wall) / 2;
        end_y = height_wall;
    }
    while (i < end_y)
    {
        put_pixel_to_image1(data,  x, start_y, 0);
        start_y++;
        i++;
    }    
}

void draw_fake_3D(t_data *data, float hit, float x)
{
    // float end_y;
    float height_wall;
    
    height_wall = CUB_SIZE / hit * data->projection_plan;
    height_wall /= CUB_SIZE;
    printf("height %f\n", height_wall * 900 / 100);
    draw_ceiling(data, hit, x);
    draw_walls(data, height_wall * HEIGHT / 100, x); 
}

void draw_fov(t_data *data)
{
    float tmp;
    float hit;
    
    float f;
    f = 0;
    tmp = data->rotationAngle - ((30 * M_PI) / 180);
    while (tmp <= data->rotationAngle + ((30 * M_PI) / 180))
    {
        hit = render_line(data, tmp);
    printf("-------------------> %f\n", hit);
        draw_fake_3D(data, hit, f);
        tmp += 0.000655;
        f++;
    }
    // printf("=======================>%d\n", f);
    // tmp = data->rotationAngle - ((30 * M_PI) / 180);
    // while (tmp < data->rotationAngle)
    // {
    //     render_line(data, tmp);
    //     tmp += 0.001;
    // }
    // render(data);
}