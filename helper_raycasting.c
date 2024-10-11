/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:37:53 by hibouzid          #+#    #+#             */
/*   Updated: 2024/10/11 18:58:02 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	get_offset(t_data *data, int flag, int step, int *v_f)
{
	if (flag == 1)
	{
		if (step == 1)
			*v_f = 1;
		else
			*v_f = 2;
		return (fmod(data->tmp_b, CUB_SIZE));
	}
	else
	{
		if (step == 1)
			*v_f = 3;
		else
			*v_f = 4;
		return (fmod(data->tmp_a, CUB_SIZE));
	}
}
