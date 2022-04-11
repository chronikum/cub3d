/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:14:10 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/11 10:36:10 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 

/**
 * Moves forward if possible
 */
void	move_forward(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x + cub->math->dirX * cub->math->moveSpeed;
	new_y = cub->player->y + cub->math->dirY * cub->math->moveSpeed;
	if (get_node_value_at(cub, new_y, new_x) != '1')
	{
		cub->player->x = new_x;
		cub->player->y = new_y;
	}
}

/**
 * Moves player backward if no wall
 */
void	move_backward(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x - cub->math->dirX * cub->math->moveSpeed;
	new_y = cub->player->y - cub->math->dirY * cub->math->moveSpeed;
	if (get_node_value_at(cub, new_y, new_x) != '1')
	{
		cub->player->x = new_x;
		cub->player->y = new_y;
	}
}

/**
 * Move left if no wall
 */
void	move_left(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x - cub->math->planeX * cub->math->moveSpeed;
	new_y = cub->player->y - cub->math->planeY * cub->math->moveSpeed;
	if (get_node_value_at(cub, new_y, new_x) != '1')
	{
		cub->player->x = new_x;
		cub->player->y = new_y;
	}
}

/**
 * Move right if no wall
 */
void	move_right(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x + cub->math->planeX * cub->math->moveSpeed;
	new_y = cub->player->y + cub->math->planeY * cub->math->moveSpeed;
	if (get_node_value_at(cub, new_y, new_x) != '1')
	{
		cub->player->x = new_x;
		cub->player->y = new_y;
	}
}

/**
 * Calculates movement of player.
 * Gets called every frame
 */
void	move(t_cub *cub)
{
	if (cub->movetrigger->is_moving_up)
		move_forward(cub);
	if (cub->movetrigger->is_moving_down)
		move_backward(cub);
	if (cub->movetrigger->is_moving_left)
		move_left(cub);
	if (cub->movetrigger->is_moving_right)
		move_right(cub);
	if (cub->movetrigger->is_rotating_left)
		rotate_left(cub);
	if (cub->movetrigger->is_rotating_right)
		rotate_right(cub);
}
