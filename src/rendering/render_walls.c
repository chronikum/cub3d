/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:22:55 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/08 17:27:43 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Inits and builds the raycaster helper struct
 */
void	init_raycast(t_cub *c, int x)
{
    c->math->cameraX = 2 * x / (double) WIDTH - 1; //x-coordinate in camera space // x is ithe iteration value, w describes the WIDTH
	c->math->rayDirX = c->math->dirX + c->math->planeX * c->math->cameraX;
	c->math->rayDirY = c->math->dirY + c->math->planeY * c->math->cameraX;
	c->math->deltaDistX = (c->math->rayDirX == 0) ? 1e30 : fabs(1 / c->math->rayDirX);
	c->math->deltaDistY = (c->math->rayDirY == 0) ? 1e30 : fabs(1 / c->math->rayDirY);
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
		c->math->sideDistX = (c->player->x - c->math->mapX) * c->math->deltaDistX;
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
		c->math->sideDistY = (c->player->y - c->math->mapY) * c->math->deltaDistY;
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
		if (c->math->perpWallDist < 50)
			my_mlx_pixel_put(&c->data, c->math->mapX, c->math->mapY,
				13734333);
		if (get_node_value_at(c, c->math->mapY, c->math->mapX) == '1')
			c->math->wall_found = true;
	}
	if(c->math->side == 0)
		c->math->perpWallDist = (c->math->sideDistX - c->math->deltaDistX);
	else
		c->math->perpWallDist = (c->math->sideDistY - c->math->deltaDistY);
	
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

void	write_in_mlx_buffer(t_cub *cub, int x, int y)
{
	while (y < cub->math->drawEnd)
	{
		cub->math->texY = (int)cub->math->texPos & (64 - 1);
		cub->math->texPos += cub->math->step;
		cub->math->texColor
				= cub->tex_ea->texture_data[64 * cub->math->texY + cub->math->texX]; // Choose texture for pixel here later
		if (cub->math->side == 1)
			cub->math->texColor = (cub->math->texColor >> 1) & 8355711; // Darken sides
		cub->math->buff[y][x] = cub->math->texColor;
		y++;
	}
}

void	draw_textures(t_cub *cub, int x)
{
	int	y_helper;
	
	if (cub->math->side == 0)
	{
		cub->math->wallX
			= cub->player->y + cub->math->perpWallDist * cub->math->rayDirY;
	}
	else
	{
		cub->math->wallX
			= cub->math->posX + cub->math->perpWallDist * cub->math->rayDirX;
	}
	cub->math->wallX -= floor(cub->math->wallX);
	cub->math->texX = (int)(cub->math->wallX * ((double) 64));
	if (cub->math->side == 0 && cub->math->rayDirX > 0)
		cub->math->texX = 64 - cub->math->texX - 1;
	if (cub->math->side == 1 && cub->math->rayDirY < 0)
		cub->math->texX = 64 - cub->math->texX - 1;
	cub->math->step = 1.0 * 64 / cub->math->lineHeight;
	cub->math->texPos = (cub->math->drawStart - HEIGHT
			/ 2 + cub->math->lineHeight / 2) * cub->math->step;
			
	y_helper = cub->math->drawStart;
	write_in_mlx_buffer(cub, x, y_helper);
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
