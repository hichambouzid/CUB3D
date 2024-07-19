/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:52:42 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/19 19:07:12 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void render(t_data *data)
{
    mlx_destroy_image(data->mlx, data->mlx_img);
    data->mlx_img = mlx_new_image(data->mlx, 1600, 1000);
    get_img_data(data, 1600, 1000);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
    setup(data);
    draw_mini_square(data);
    int i = 0;
    
    float a_tmp = 11 + (data->f * 20);
    float b_tmp = 11 + (data->z * 20);
    while (i < 30)
    {
        put_pixel_to_image(data,a_tmp, b_tmp, 0x00FF0000);
        b_tmp += sin(data->rotationAngle);
        a_tmp +=  cos(data->rotationAngle);
        i++;
    }
}