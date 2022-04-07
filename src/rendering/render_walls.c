/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:22:55 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/07 18:18:39 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Inits and builds the raycaster helper struct
 */
void	init_raycast(t_cub *c, int x)
{
    c->math->cameraX = 2 * x / WIDTH - 1; //x-coordinate in camera space // x is ithe iteration value, w describes the WIDTH
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
		c->math->sideDistX = ((c->math->mapX + 1) - c->player->x)
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
		c->math->sideDistY = ((c->math->mapY + 1) - c->player->y)
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
		// if (c->math->perpWallDist < 50)
		// 	my_mlx_pixel_put(&c->data, c->math->mapX, c->math->mapY,
		// 		13734333);
		if (get_node_value_at(c, c->math->mapY, c->math->mapX) == '1')
			c->math->wall_found = true;
	}
	if(c->math->side == 0)
		c->math->perpWallDist = (c->math->sideDistX - c->math->deltaDistX);
	else
		c->math->perpWallDist = (c->math->sideDistY - c->math->deltaDistY);
}

// /**
//  * Calculates the line which should be drawn.
//  * Sets an array of color codes to be set. The array ends with -1.
//  */
// void	draw_texture(t_cub *cub)
// {
// 	// define lineheight, drawStart and drawEnd
// 	cub->lineHeight = (int)(HEIGHT / cub->r->perpWallDist);
// 	cub->drawStart = -cub->lineHeight / 2 + HEIGHT / 2;
// 	if(cub->drawStart < 0) cub->drawStart = 0;
// 	cub->drawEnd = cub->lineHeight / 2 + HEIGHT / 2;
// 	if(cub->drawEnd >= cub->lineHeight) cub->drawEnd = HEIGHT - 1;

// 	double wallX; //where exactly the wall was hit
// 	if (cub->r->side == 0)
// 		wallX = cub->player_y + cub->r->perpWallDist * cub->r->rayDirY; // y can also be player pos
// 	else
// 		wallX = cub->player_x + cub->r->perpWallDist * cub->r->rayDirX; // x can also be player pos
// 	wallX -= floor((wallX));

// 	//x coordinate on the texture
// 	int texX = (int) wallX * (double)TEXTURE_SIZE;
// 	if(cub->r->side == 0 && cub->r->rayDirX > 0) texX = TEXTURE_SIZE - texX - 1;
// 	if(cub->r->side == 1 && cub->r->rayDirY < 0) texX = TEXTURE_SIZE - texX - 1;
// 	double step = .5 * (double) TEXTURE_SIZE / cub->lineHeight;
// 	// Starting texture coordinate
// 	double texPos = (cub->drawStart - HEIGHT / 2 + cub->lineHeight / 2) * step;

// 	int color2 = 0;
// 	int	incrementer = 0;
// 	int y1 = cub->drawStart;
// 	while (y1 < cub->drawEnd)
// 	{
// 		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
// 		int texY = (int)texPos & (TEXTURE_SIZE - 1);
// 		texPos += step;
// 		color2 = cub->tex_ea->texture_data[TEXTURE_SIZE * texY + (cub->raycount % TEXTURE_SIZE)]; //todo: this is a very rough implementation to get the correct X coordinate. We use the camera angle
// 		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// 		if(cub->r->side == 1) color2 = (color2 >> 1) & 8355711;
// 		cub->line_to_draw[incrementer] = color2;
// 		incrementer++;
// 		y1++;
// 	}
// 	cub->line_to_draw_height = incrementer;
// 	cub->line_to_draw[incrementer] = -1;
// }

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
	if (c->math->wall_found)
		return (c->math->perpWallDist);
	else
		return (-1);
}
