/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:11:06 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/12 16:22:18 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void put_pixel_to_image(t_data *data, int x, int y, int coler)
{
    char *tmp;

    tmp = data->str + (y * data->line_lenght + 4 * x);
    *(unsigned int *)tmp = coler;
}

void  get_img_data(t_data *data, int width, int height)
{
    int bits_per_pixel;
    int endian;
    int i;

    i = 0;    
    data->str = mlx_get_data_addr(data->mlx_img,  &bits_per_pixel, &data->line_lenght, &endian);
    while (i < height * width)
    {
        *((unsigned int *)data->str + i) = 0x00808080;
        i++;
    }
}