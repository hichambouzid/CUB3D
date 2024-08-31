/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:14:02 by serraoui          #+#    #+#             */
/*   Updated: 2024/08/31 21:31:59 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

int	ft_iswhitespace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_allwhitespace(char *s)
{
	while (*s && *s != '\n')
	{
		if (!ft_iswhitespace(*s))
			return (0);
		s++;
	}
	return (1);
}
