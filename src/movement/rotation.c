/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:49:19 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:10:31 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Rotates player to the right
 */
void	rotate_right(t_cub *cub)
{
	cub->math->oldDirX = cub->math->dirX;
	cub->math->dirX = cub->math->dirX * cos(-cub->math->rotSpeed)
		- cub->math->dirY * sin(-cub->math->rotSpeed);
	cub->math->dirY = cub->math->oldDirX * sin(-cub->math->rotSpeed)
		+ cub->math->dirY * cos(-cub->math->rotSpeed);
	cub->math->oldPlaneX = cub->math->planeX;
	cub->math->planeX = cub->math->planeX * cos(-cub->math->rotSpeed)
		- cub->math->planeY * sin(-cub->math->rotSpeed);
	cub->math->planeY = cub->math->oldPlaneX * sin(-cub->math->rotSpeed)
		+ cub->math->planeY * cos(-cub->math->rotSpeed);
}

/**
 * Rotates player to the left
 */
void	rotate_left(t_cub *cub)
{
	cub->math->oldDirX = cub->math->dirX;
	cub->math->dirX = cub->math->dirX * cos(cub->math->rotSpeed)
		- cub->math->dirY * sin(cub->math->rotSpeed);
	cub->math->dirY = cub->math->oldDirX * sin(cub->math->rotSpeed)
		+ cub->math->dirY * cos(cub->math->rotSpeed);
	cub->math->oldPlaneX = cub->math->planeX;
	cub->math->planeX = cub->math->planeX * cos(cub->math->rotSpeed)
		- cub->math->planeY * sin(cub->math->rotSpeed);
	cub->math->planeY = cub->math->oldPlaneX * sin(cub->math->rotSpeed)
		+ cub->math->planeY * cos(cub->math->rotSpeed);
}
