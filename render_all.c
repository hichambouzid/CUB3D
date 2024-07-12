/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:52:42 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/12 18:46:07 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void render(t_data *data)
{
    // mlx_clear_window(data->mlx, data->mlx_win);
    mlx_destroy_image(data->mlx, data->mlx_img);
    data->mlx_img = mlx_new_image(data->mlx, 1600, 1000);
    get_img_data(data, 1600, 1000);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
    setup(data);
    // render rays
    // if (!data->x && !data->y)
    // { 
    //     printf("-----?\n");
    //     get_cordinate(data);
    // }
    draw_mini_square(data);
}