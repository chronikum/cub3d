/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:05 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/12 15:53:11 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h" 

/**
 * Returns true if the wall is a direction or empty space
 */
bool	is_direction(char c)
{
	return (c == '0' || c == 'S' || c == 'N'
		|| c == 'E' || c == 'W');
}

/**
 * Draws the player on the minimap
 */
void	draw_player(t_cub *cub, int x, int y, int size)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (tmp_y < y + size)
	{
		while (tmp_x < x + size)
		{
			if (tmp_x >= 0 && tmp_x < WIDTH && tmp_y >= 0
				&& tmp_y < HEIGHT)
				my_mlx_pixel_put(&cub->data, tmp_x, tmp_y, 386486);
			tmp_x++;
		}
		tmp_y++;
		tmp_x = x;
	}
}

/**
 * Draws squares in the minimap
 */
void	draw_square(t_cub *cub, int x, int y, int size)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (tmp_y < y + size)
	{
		while (tmp_x < x + size)
		{
			if (tmp_x >= 0 && tmp_x < WIDTH && tmp_y >= 0
				&& tmp_y < HEIGHT)
				my_mlx_pixel_put(&cub->data, tmp_x, tmp_y, 10101099);
			tmp_x++;
		}
		tmp_y++;
		tmp_x = x;
	}
}

/**
 * Draws the floor of the minimap
 */
void	draw_floor(t_cub *cub, int x, int y, int size)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (tmp_y < y + size)
	{
		while (tmp_x < x + size)
		{
			if (tmp_x >= 0 && tmp_x < WIDTH && tmp_y >= 0
				&& tmp_y < HEIGHT)
				my_mlx_pixel_put(&cub->data, tmp_x, tmp_y, 15535);
			tmp_x++;
		}
		tmp_y++;
		tmp_x = x;
	}
}

/**
 * Renders the minimap
 */
void	render_minimap(t_cub *cub)
{
	t_map	*node;
	int		pos[2];
	int		old_y;

	node = cub->map;
	pos[0] = 0;
	pos[1] = 0;
	old_y = 0;
	while (node)
	{
		if (old_y != node->y)
		{
			pos[0] = 0;
			pos[1] += TILESIZE;
		}
		draw_floor(cub, pos[0], pos[1], TILESIZE - 1);
		if (node->o == '1')
			draw_square(cub, pos[0], pos[1], TILESIZE - 1);
		if (node->x == floor(cub->player->x)
			&& node->y == floor(cub->player->y))
			draw_player(cub, pos[0], pos[1], TILESIZE - 1);
		pos[0] += TILESIZE;
		old_y = node->y;
		node = node->next;
	}
}
