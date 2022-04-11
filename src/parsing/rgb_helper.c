/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:26:25 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/11 14:31:11 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Checks if rgb is valid, means no value is bigger than 255 or smaller than 0
 */
bool	check_rgb_valid(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (false);
	else if (g < 0 || g > 255)
		return (false);
	else if (b < 0 || b > 255)
		return (false);
	return (true);
}
