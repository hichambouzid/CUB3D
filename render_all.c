/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:52:42 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/24 14:35:58 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_coler(t_data *data, int x, int y)
{
    char *tmp;

    tmp = data->str + ((y * data->line_lenght + 4 * x));
    if (*(unsigned int *)tmp <= 0)
        return (0);
    return (1);
}

void render_line(t_data *data, float Angle)
{
    float a_tmp = 11 + (data->f * 20);
    float b_tmp = 11 + (data->z * 20);
    while (1)
    {
        if (!check_coler(data, a_tmp, b_tmp))
            break ;
        if (!check_coler(data, a_tmp + 1, b_tmp + 1))
           break ;
        if (!check_coler(data, a_tmp - 1, b_tmp - 1))
           break ;
        if (!check_coler(data, a_tmp + 1, b_tmp - 1))
           break ;
        if (!check_coler(data, a_tmp - 1, b_tmp + 1))
                    break ;
        put_pixel_to_image(data,a_tmp, b_tmp, 0x00FF0000);
        b_tmp += sin(Angle);
        a_tmp +=  cos(Angle);
    }

    
}
void render(t_data *data)
{
    mlx_destroy_image(data->mlx, data->mlx_img);
    data->mlx_img = mlx_new_image(data->mlx, 1600, 1000);
    get_img_data(data, 1600, 1000);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
    setup(data);
    draw_mini_square(data);
    // int i = 0;
    // render_line(data, data->rotationAngle);
    draw_fov(data);
    // float a_tmp = 11 + (data->f * 20);
    // float b_tmp = 11 + (data->z * 20);
    // while (1)
    // {
    //     if (!check_coler(data, a_tmp, b_tmp))
    //         break ;
    //     put_pixel_to_image(data,a_tmp, b_tmp, 0x00FF0000);
    //     b_tmp += sin(data->rotationAngle);
    //     a_tmp +=  cos(data->rotationAngle);
    // }
}