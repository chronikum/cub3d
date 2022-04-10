/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:13:04 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:31:58 by jfritz           ###   ########.fr       */
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
		return (spawn_west(cub));
	else if (orientation == 'E')
		return (spawn_east(cub));
	else if (orientation == 'S')
		return (spawn_south(cub));
	else if (orientation == 'N')
		return (spawn_north(cub));
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