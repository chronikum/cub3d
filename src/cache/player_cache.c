/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_cache.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:26:56 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 10:22:48 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Check if the player position changed
 */
static bool	check_player_position(t_cub *cub)
{
	static double	old_playery = 0;
	static double	old_playerx = 0;

	if (cub->player->x == old_playerx && cub->player->y == old_playery)
		return (true);
	old_playerx = cub->player->x;
	old_playery = cub->player->y;
	return (false);
}

/**
 * Returns true if the current frame does not have any new information.
 * Means, the frame does not change and the rays stay at the same distance.
 * For implementing this, we need a so called cache-map.
 */
bool	is_player_in_cache(t_cub *cub)
{
	static double	old_planex = 0;
	static double	old_planey = 0;
	static double	old_olddirx = 0;
	static double	old_olddiry = 0;

	if (check_player_position(cub)
		&& old_planex == cub->math->planex && old_planey == cub->math->planey
		&& old_olddiry == cub->math->diry && old_olddirx == cub->math->dirx)
	{
		return (true);
	}
	old_planex = cub->math->planex;
	old_planey = cub->math->planey;
	old_olddirx = cub->math->dirx;
	old_olddiry = cub->math->diry;
	return (false);
}
