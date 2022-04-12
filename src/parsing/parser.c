/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:23:08 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/12 19:23:50 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2022/02/26 18:35:27 by ysonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*	Initialize the data and the pointers
*	NO/SO/WE/EA Identifiers
*	F[0-1-2] Floor RGB Colours
*	C[0-1-2] Ceiling RGB Colours
*
*/

void	init_data(t_cub *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->floor = -1;
	cub->ceiling = -1;
	cub->i = 0;
	cub->map = NULL;
	cub->id_done = false;
	cub->map_done = false;
	cub->map_data = NULL;
}

/*	Create the data struct
*	Read the file
*	Verify the content
*	Store the data
*	Builds the char map used later
*/

t_cub	*get_data(int fd, char *read, t_cub *cub)
{
	int checker;

	cub = (t_cub *)xmalloc(sizeof(t_cub));
	init_data(cub);
	checker = get_next_line(fd, &read);
	while (read != NULL)
	{
		if (ft_strcmp(read, "\0") == 0)
		{
			if (checker == 0 && (!cub->id_done))
				return (NULL);
			else if (checker == 1 && cub->map != NULL)
				return (NULL);
			else if (checker == 0 && cub->map != NULL && ft_memfree((void *)read))
				break;
		}
		else if (cub->id_done == false && identifier(cub, read))
			exit_on_error();
		else if (cub->id_done == true && map(cub, NULL, read, 0))
			exit_on_error();
		identifier_done(cub);
		free(read);
		checker = get_next_line(fd, &read);
	}
	cub->map_done = is_map_valid(cub, false, 0);
	build_2d_charmap(cub);
	if ((cub->id_done == false || cub->map_done == false))
		exit_on_error();
	return (cub);
}

/*	This function is the main parsing function, it will
*		Check if the content of the file respect the rules
*		Store the data
*/

t_cub	*check_file_content(char *file)
{
	int		fd;
	t_cub	*cub;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_on_error();
	cub = get_data(fd, NULL, NULL);
	if (cub == NULL)
		exit_on_error();
	if (close(fd) == -1)
		exit_on_error();
	return (cub);
}

/**
**	Check if the filename has
**	a valid extension (.cub)
**	If not, it returns 0.
*/
int	check_file_format(char *file_name)
{
	int			len;
	const char	*start;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (1);
	start = (const char *) &file_name[(len - 4)];
	if (ft_strncmp(start, ".cub", 4) == 0)
		return (0);
	return (1);
}
