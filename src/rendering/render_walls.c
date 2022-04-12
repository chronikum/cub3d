/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:22:55 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 10:22:48 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Calculate lineheight, drawstart and drawend
 */
void	calculate_line_height_drawstartend(t_cub *c)
{
	c->math->lineheight = (int)(HEIGHT / c->math->perpwalldist);
	c->math->drawstart
		= -c->math->lineheight / 2 + (int) HEIGHT / 2;
	if (c->math->drawstart < 0)
		c->math->drawstart = 0;
	c->math->drawend
		= c->math->lineheight / 2 + (int)HEIGHT / 2;
	if (c->math->drawend >= (int) HEIGHT)
		c->math->drawend = (int) HEIGHT - 1;
}

/**
 * Inits and builds the raycaster helper struct
 */
void	init_raycast(t_cub *c, int x)
{
	c->math->camerax = 2 * x / (double) WIDTH - 1;
	c->math->raydirx = c->math->dirx + c->math->planex * c->math->camerax;
	c->math->raydiry = c->math->diry + c->math->planey * c->math->camerax;
	c->math->deltadistx = ternary_double((c->math->raydirx == 0),
			1e30, fabs(1 / c->math->raydirx));
	c->math->deltadisty = ternary_double((c->math->raydiry == 0),
			1e30, fabs(1 / c->math->raydiry));
	c->math->mapx = (int)c->player->x;
	c->math->mapy = (int)c->player->y;
	c->math->stepx = 0;
	c->math->stepy = 0;
	c->math->wall_found = false;
	c->math->perpwalldist = 0;
	c->math->sidedistx = 0;
	c->math->sidedisty = 0;
	c->math->side = -1;
}

/**
 * Calculates which direction the ray goes (plus/minus xy)
 */
void	calculate_stepxy(t_cub *c)
{
	if (c->math->raydirx < 0)
	{
		c->math->stepx = -1;
		c->math->sidedistx = (c->player->x - c->math->mapx)
			* c->math->deltadistx;
	}
	else
	{
		c->math->stepx = 1;
		c->math->sidedistx = ((c->math->mapx + 1.0) - c->player->x)
			* c->math->deltadistx;
	}
	if (c->math->raydiry < 0)
	{
		c->math->stepy = -1;
		c->math->sidedisty = (c->player->y - c->math->mapy)
			* c->math->deltadisty;
	}
	else
	{
		c->math->stepy = 1;
		c->math->sidedisty = ((c->math->mapy + 1.0) - c->player->y)
			* c->math->deltadisty;
	}
}

/**
 * Raying the trace on check grid intersections
 */
void	raycast_on_grid_lines(t_cub *c)
{
	while (c->math->wall_found == false)
	{
		if (c->math->sidedistx < c->math->sidedisty)
		{
			c->math->sidedistx += c->math->deltadistx;
			c->math->mapx += c->math->stepx;
			c->math->side = 0;
		}
		else
		{
			c->math->sidedisty += c->math->deltadisty;
			c->math->mapy += c->math->stepy;
			c->math->side = 1;
		}
		if (get_node_value_at(c, c->math->mapy, c->math->mapx) == '1')
			c->math->wall_found = true;
	}
	if (c->math->side == 0)
		c->math->perpwalldist = (c->math->sidedistx - c->math->deltadistx);
	else
		c->math->perpwalldist = (c->math->sidedisty - c->math->deltadisty);
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
		return (c->math->perpwalldist);
	else
		return (-1);
}
