/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_player_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:29:16 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:31:02 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/cub3d.h"

/**
 * Spawn player with west presets
 */
int	spawn_west(t_cub *cub)
{
	cub->math->dirX = 0.00;
	cub->math->dirY = -1.00;
	cub->math->planeX = -0.66;
	cub->math->planeY = 0;
	return (1);
}

/**
 * Spawn player with east presets
 */
int spawn_east(t_cub *cub)
{
	cub->math->dirX = 0.00;
	cub->math->dirY = 1.00;
	cub->math->planeX = 0.66;
	cub->math->planeY = 0;
	return (1);
}

/**
 * Spawn player with north presets
 */
int spawn_north(t_cub *cub)
{
	cub->math->dirX = -1.00;
	cub->math->dirY = 0.00;
	cub->math->planeX = 0;
	cub->math->planeY = 0.66;
	return (1);
}

/**
 * Spawn player with south presets
 */
int spawn_south(t_cub *cub)
{
	cub->math->dirX = 1.00;
	cub->math->dirY = 0.00;
	cub->math->planeY = -0.66;
	cub->math->planeX = 0;
	return (1);
}