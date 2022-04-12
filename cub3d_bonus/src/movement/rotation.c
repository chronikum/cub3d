/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:49:19 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 10:22:48 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Rotates player to the right
 */
void	rotate_right(t_cub *cub)
{
	cub->math->olddirx = cub->math->dirx;
	cub->math->dirx = cub->math->dirx * cos(-cub->math->rotspeed)
		- cub->math->diry * sin(-cub->math->rotspeed);
	cub->math->diry = cub->math->olddirx * sin(-cub->math->rotspeed)
		+ cub->math->diry * cos(-cub->math->rotspeed);
	cub->math->oldplanex = cub->math->planex;
	cub->math->planex = cub->math->planex * cos(-cub->math->rotspeed)
		- cub->math->planey * sin(-cub->math->rotspeed);
	cub->math->planey = cub->math->oldplanex * sin(-cub->math->rotspeed)
		+ cub->math->planey * cos(-cub->math->rotspeed);
}

/**
 * Rotates player to the left
 */
void	rotate_left(t_cub *cub)
{
	cub->math->olddirx = cub->math->dirx;
	cub->math->dirx = cub->math->dirx * cos(cub->math->rotspeed)
		- cub->math->diry * sin(cub->math->rotspeed);
	cub->math->diry = cub->math->olddirx * sin(cub->math->rotspeed)
		+ cub->math->diry * cos(cub->math->rotspeed);
	cub->math->oldplanex = cub->math->planex;
	cub->math->planex = cub->math->planex * cos(cub->math->rotspeed)
		- cub->math->planey * sin(cub->math->rotspeed);
	cub->math->planey = cub->math->oldplanex * sin(cub->math->rotspeed)
		+ cub->math->planey * cos(cub->math->rotspeed);
}
