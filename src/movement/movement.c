/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:14:10 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 14:59:40 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 

# define MOVESPEED 0.2

/**
 * Moves forward if possible
 */
void	move_forward(t_cub *cub)
{
	double newX;
	double newY;
	
	newX = cub->player->x + cub->math->dirX * MOVESPEED;
	newY = cub->player->y + cub->math->dirY * MOVESPEED;
	if (get_node_value_at(cub, newY, newX) != '1')
	{
		cub->player->x = newX;
		cub->player->y = newY;
	}
}

void	move_backward(t_cub *cub)
{
	double newX;
	double newY;
	
	newX = cub->player->x - cub->math->dirX * MOVESPEED;
	newY = cub->player->y - cub->math->dirY * MOVESPEED;
	if (get_node_value_at(cub, newY, newX) != '1')
	{
		cub->player->x = newX;
		cub->player->y = newY;
	}
}

void	move_left(t_cub *cub)
{
	double newX;
	double newY;
	
	newX = cub->player->x - cub->math->planeX * MOVESPEED;
	newY = cub->player->y - cub->math->planeY * MOVESPEED;
	if (get_node_value_at(cub, newY, newX) != '1')
	{
		cub->player->x = newX;
		cub->player->y = newY;
	}
}

void	move_right(t_cub *cub)
{
	double newX;
	double newY;
	
	newX = cub->player->x + cub->math->planeX * MOVESPEED;
	newY = cub->player->y + cub->math->planeY * MOVESPEED;
	if (get_node_value_at(cub, newY, newX) != '1')
	{
		cub->player->x = newX;
		cub->player->y = newY;
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