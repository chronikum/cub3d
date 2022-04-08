/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:13:23 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 14:14:35 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Fills the whole image with floor and ceiling
 */
void	fill_floor_ceiling(t_cub *cub, int x)
{
	int	u;
	int	z;

	u = 0;
	while (u < cub->math->drawStart)
	{
		cub->math->buff[u][x] = cub->ceiling;
		u++;
	}
	z = cub->math->drawEnd;
	while (z < HEIGHT)
	{
		cub->math->buff[z][x] = cub->floor;
		z++;
	}
}