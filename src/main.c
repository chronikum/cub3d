/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:24:17 by jfritz            #+#    #+#             */
/*   Updated: 2022/04/07 16:40:01 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = NULL;
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	if (check_file_format(argv[1]))
	{
		ft_putendl_fd("Wrong map format", 2);
		exit(EXIT_FAILURE);
	}
	cub = check_file_content(argv[1]);
	if (cub == NULL)
		exit(EXIT_FAILURE);
	return (0);
}