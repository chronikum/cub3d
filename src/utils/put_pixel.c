/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:23:01 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:07:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Put pixel at coordinate xy with color.
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	data->addr[y * (int)WIDTH + x] = color;
}
