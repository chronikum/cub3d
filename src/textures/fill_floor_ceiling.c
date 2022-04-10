/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:13:23 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:02:05 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Fills the whole image with floor and ceiling
 */
void	fill_floor_ceiling(t_cub *cub, int x)
{
	int	fc;

	fc = 0;
	while (fc < cub->math->drawStart)
	{
		cub->math->buff[fc][x] = cub->ceiling;
		fc++;
	}
	fc = cub->math->drawEnd;
	while (fc < HEIGHT)
	{
		cub->math->buff[fc][x] = 432423;
		fc++;
	}
}
