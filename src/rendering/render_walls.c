/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:22:55 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/11 16:38:54 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Calculate lineHeight, drawStart and drawEnd
 */
void	calculate_line_height_drawstartend(t_cub *c)
{
	c->math->lineHeight = (int)(HEIGHT / c->math->perpWallDist);
	c->math->drawStart
		= -c->math->lineHeight / 2 + (int) HEIGHT / 2;
	if (c->math->drawStart < 0)
		c->math->drawStart = 0;
	c->math->drawEnd
		= c->math->lineHeight / 2 + (int)HEIGHT / 2;
	if (c->math->drawEnd >= (int) HEIGHT)
		c->math->drawEnd = (int) HEIGHT - 1;
}

/**
 * Inits and builds the raycaster helper struct
 */
void	init_raycast(t_cub *c, int x)
{
	c->math->cameraX = 2 * x / (double) WIDTH - 1;
	c->math->rayDirX = c->math->dirX + c->math->planeX * c->math->cameraX;
	c->math->rayDirY = c->math->dirY + c->math->planeY * c->math->cameraX;
	c->math->deltaDistX = ternary_double((c->math->rayDirX == 0),
			1e30, fabs(1 / c->math->rayDirX));
	c->math->deltaDistY = ternary_double((c->math->rayDirY == 0),
			1e30, fabs(1 / c->math->rayDirY));
	c->math->mapX = (int)c->player->x;
	c->math->mapY = (int)c->player->y;
	c->math->stepX = 0;
	c->math->stepY = 0;
	c->math->wall_found = false;
	c->math->perpWallDist = 0;
	c->math->sideDistX = 0;
	c->math->sideDistY = 0;
	c->math->side = -1;
}

/**
 * Calculates which direction the ray goes (plus/minus xy)
 */
void	calculate_stepxy(t_cub *c)
{
	if (c->math->rayDirX < 0)
	{
		c->math->stepX = -1;
		c->math->sideDistX = (c->player->x - c->math->mapX)
			* c->math->deltaDistX;
	}
	else
	{
		c->math->stepX = 1;
		c->math->sideDistX = ((c->math->mapX + 1.0) - c->player->x)
			* c->math->deltaDistX;
	}
	if (c->math->rayDirY < 0)
	{
		c->math->stepY = -1;
		c->math->sideDistY = (c->player->y - c->math->mapY)
			* c->math->deltaDistY;
	}
	else
	{
		c->math->stepY = 1;
		c->math->sideDistY = ((c->math->mapY + 1.0) - c->player->y)
			* c->math->deltaDistY;
	}
}

/**
 * Raying the trace on check grid intersections
 */
void	raycast_on_grid_lines(t_cub *c)
{
	while (c->math->wall_found == false)
	{
		if (c->math->sideDistX < c->math->sideDistY)
		{
			c->math->sideDistX += c->math->deltaDistX;
			c->math->mapX += c->math->stepX;
			c->math->side = 0;
		}
		else
		{
			c->math->sideDistY += c->math->deltaDistY;
			c->math->mapY += c->math->stepY;
			c->math->side = 1;
		}
		if (get_node_value_at(c, c->math->mapY, c->math->mapX) == '1')
			c->math->wall_found = true;
	}
	if (c->math->side == 0)
		c->math->perpWallDist = (c->math->sideDistX - c->math->deltaDistX);
	else
		c->math->perpWallDist = (c->math->sideDistY - c->math->deltaDistY);
	calculate_line_height_drawstartend(c);
}

/*
	Draws a raycast line and returns the distance to the wall
	Takes x as the current vertical pixel line
*/
double	render_walls(t_cub *c, int x)
{
	c->math->wall_found = false;
	init_raycast(c, x);
	calculate_stepxy(c);
	raycast_on_grid_lines(c);
	draw_textures(c, x);
	if (c->math->wall_found)
		return (c->math->perpWallDist);
	else
		return (-1);
}
