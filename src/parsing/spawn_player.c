/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:13:04 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/07 18:16:19 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/cub3d.h" 

/**
 * Searches for player in map
 * and sets initial values for it when found.
 * Returns 1 when player was found
 */
int	init_spawning_player(t_cub *cub, int row, int column)
{
	char	orientation;

	orientation = get_node_value_at(cub, row, column);
	if (orientation == 'W')
	{
		cub->math->dirX = 0.00;
		cub->math->dirY = -1.00;
		cub->math->planeX = -0.66;
		cub->math->planeY = 0;
		return (1);
	}
	else if (orientation == 'E')
	{
		cub->math->dirX = 0.00;
		cub->math->dirY = 1.00;
		cub->math->planeX = 0.66;
		cub->math->planeY = 0;
		return (1);
	}
	else if (orientation == 'S')
	{
		cub->math->dirX = 1.00;
		cub->math->dirY = 0.00;
		cub->math->planeY = -0.66;
		cub->math->planeX = 0;
		return (1);
	}
	else if (orientation == 'N')
	{
		cub->math->dirX = -1.00;
		cub->math->dirY = 0.00;
		cub->math->planeX = 0;
		cub->math->planeY = 0.66;
		return (1);
	}
	return (0);
}

/**
 * Calculates player position in map.
 * Sets starting values for the player
 */
void	calculate_player_pos(t_cub *cub)
{
	t_map	*tmp;
    t_vec2  *player;

    player = malloc(sizeof(t_vec2));
	tmp = cub->map;
	while (tmp != NULL)
	{
		if (init_spawning_player(cub, tmp->y, tmp->x))
		{
            cub->player = player;
			cub->player->x = tmp->x;
			cub->player->y = tmp->y;
			printf("Player starting position %f %f\n", cub->player->x, cub->player->y);
		}
		tmp = tmp->next;
	}
}