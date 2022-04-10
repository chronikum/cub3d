/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:17:08 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/10 15:17:44 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Ternary helper for double values
 */
double	ternary_double(bool statement, double is_true, double is_false)
{
	if (statement)
		return (is_true);
	return (is_false);
}
