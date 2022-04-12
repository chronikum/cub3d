/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_player_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:29:16 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 10:22:48 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Spawn player with west presets
 */
int	spawn_west(t_cub *cub)
{
	cub->math->dirx = 0.00;
	cub->math->diry = -1.00;
	cub->math->planex = -0.66;
	cub->math->planey = 0;
	return (1);
}

/**
 * Spawn player with east presets
 */
int	spawn_east(t_cub *cub)
{
	cub->math->dirx = 0.00;
	cub->math->diry = 1.00;
	cub->math->planex = 0.66;
	cub->math->planey = 0;
	return (1);
}

/**
 * Spawn player with north presets
 */
int	spawn_north(t_cub *cub)
{
	cub->math->dirx = -1.00;
	cub->math->diry = 0.00;
	cub->math->planex = 0;
	cub->math->planey = 0.66;
	return (1);
}

/**
 * Spawn player with south presets
 */
int	spawn_south(t_cub *cub)
{
	cub->math->dirx = 1.00;
	cub->math->diry = 0.00;
	cub->math->planey = -0.66;
	cub->math->planex = 0;
	return (1);
}
