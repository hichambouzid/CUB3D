/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:52:42 by hibouzid          #+#    #+#             */
/*   Updated: 2024/07/31 15:48:19 by hibouzid         ###   ########.fr       */
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

float render_line(t_data *data, float Angle)
{
    float a_tmp = 11 + (data->f * 20);
    float b_tmp = 11 + (data->z * 20);

    float save_a = 11 + (data->f * 20);
    float save_b = 11 + (data->z * 20);

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
        b_tmp += sin(Angle) * 0.05;
        a_tmp +=  cos(Angle) * 0.05;
    }
    // a_tmp *= data->f / save_a;
    // b_tmp *= data->z / save_b;
    // float corectdis  = sqrtf(powf(((a_tmp - data->f) * CUB_SIZE), 2) + powf(((b_tmp - data->z) * CUB_SIZE), 2));
    // float newdis = corectdis * cos(data->rotationAngle * 0.5);
    
    
    return (sqrt(pow(((a_tmp - save_a)), 2) + pow(((b_tmp - save_b)), 2)));
    // return (newdis);
    
}
void render(t_data *data)
{
    mlx_destroy_image(data->mlx, data->mlx_img);
    mlx_destroy_image(data->mlx, data->mlx_3D);
    data->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->mlx_3D = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->flag != 0)
		data->mlx_tmp = data->mlx_img;
	else
		data->mlx_tmp = data->mlx_3D;        
	get_img_data(data, WIDTH, HEIGHT);
    // data->mlx_tmp = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    // get_img_data(data, WIDTH, HEIGHT);
    // mlx_put_image_to_window(data->mlx, data->mlx_win, data->tmp, 0, 0);
    setup(data);
    draw_mini_square(data);
    // int i = 0;
    // render_line(data, data->rotationAngle);
    draw_fov(data);
    // printf("data->f====%f\n", data->f);
    // printf("data->z====%f\n", data->z);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_tmp, 0, 0);
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