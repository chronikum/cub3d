/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:29:48 by ysonmez           #+#    #+#             */
/*   Updated: 2022/04/11 14:29:18 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __APPLE__
#  define MLX_HEADER "../minilibx_macos/mlx.h"
# else
#  define MLX_HEADER "../minilibx_linux/mlx.h"
# endif

# include "libft.h"
# include "get_next_line.h"
# include "keycodes.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include MLX_HEADER
# include <sys/time.h>

/*	Window Resolution */

# define WIDTH						1920
# define HEIGHT						1080
# define TILESIZE					10
# define PLAYER_MINIMAP_SIZE		10
# define MINIMAP_RAY_COLOR			55555
# define MINIMAP_HEIGHT				400
# define MINIMAP_WIDTH				680

/*----------------------------------------------------------------------*/
/*							MinilibX Data Struct						*/
/*----------------------------------------------------------------------*/

typedef struct s_vars {
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_data {
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

/*----------------------------------------------------------------------*/
/*							Main Rendering Data Struct					*/
/*----------------------------------------------------------------------*/

typedef struct s_map {
	double				x;
	double				y;
	char				o;
	struct s_map		*next;
}	t_map;

typedef struct s_map_data {
	char				*data;
	struct s_map_data	*next;
}	t_map_data;

typedef struct s_texture {
	int		width;
	int		height;
	char	*texture_ptr;
	int		*texture_data;
	int		*texture;
	int		bpp;
	int		line_size;
	int		endian;
}	t_texture;

typedef struct s_movetrigger {
	bool			is_moving_up;
	bool			is_moving_down;
	bool			is_moving_left;
	bool			is_moving_right;
	bool			is_rotating_left;
	bool			is_rotating_right;
}	t_move_trigger;

typedef struct s_math {
	char		playerdir;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldTime;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			maxX;
	int			mapY;
	int			maxY;
	double		stepX;
	double		stepY;
	bool		wall_found;
	double		side;
	double		lineHeight;
	double		drawStart;
	double		drawEnd;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	double		moveSpeed;
	double		rotSpeed;
	double		oldDirX;
	double		oldPlaneX;
	double		spritePosX;
	double		spritePosY;
	int			buff[HEIGHT][WIDTH];
	int			dBuffer[WIDTH];
	int			**texture;
	double		wallX;
	int			texX;
	double		step;
	double		texPos;
	int			texY;
	int			texColor;
}	t_math;

typedef struct s_vec2 {
	double	x;
	double	y;
}	t_vec2;

typedef struct s_cub {
	t_vars			vars;
	t_data			data;
	t_map			*map;
	int				i;
	int				floor;
	int				ceiling;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	void			*img_no;
	void			*img_so;
	void			*img_we;
	void			*img_ea;
	t_texture		*tex_no;
	t_texture		*tex_so;
	t_texture		*tex_we;
	t_texture		*tex_ea;
	t_vec2			*player;
	bool			id_done;
	bool			map_done;
	char			**c_map;
	t_math			*math;
	t_move_trigger	*movetrigger;
	t_map_data		*map_data;
}	t_cub;

typedef struct s_line {
	double	dx;
	double	dy;
	double	p;
	double	x;
	double	y;
	t_cub	*cub;
}	t_line;

// Preparation and starting cub3d
void			start_cub3d(t_cub *cub);
t_move_trigger	*initalize_key_trigger(void);
// gets value of this coordinate
char			get_node_value_at(t_cub *cub, int row, int column);
// Put pixel at position x and y
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
// Vector logic
t_vec2			*create_vector(double x, double y);
void			uvec(t_vec2 *vector, double x, double y);
// PARSING
t_cub			*get_data(int fd, char *read, t_cub *cub);
t_cub			*check_file_content(char *file);
int				check_file_format(char *file);

void			identifier_done(t_cub *cub);
int				identifier(t_cub *cub, char *read);
int				map(t_cub *cub, t_map *tmp, char *read, int i);
t_map			*ft_lstnew(void);
void			ft_lstadd_back(t_map **lst, t_map *new);
bool			is_map_valid(t_cub *cub, bool player_set, int n_col);
t_map_data		*ft_data_new_data(char *string);
void			ft_data_append_data(t_map_data **lst, t_map_data *new);
int				ft_lst_data_count(t_map_data *head);
void			build_2d_charmap(t_cub *cub);
// spawms player
void			calculate_player_pos(t_cub *cub);
// Key Handler
int				key_up(int keycode, t_cub *cub);
int				key_handler(int keycode, t_cub *cub);
// RENDERING
double			render_walls(t_cub *c, int x);
int				draw_line_color(t_cub *cub, t_vec2 *v1, t_vec2 *v0, int color);
bool			is_player_in_cache(t_cub *cub);
// TEXTURES
bool			load_textures(t_cub *cub);
t_texture		*new_texture(void *img_ptr);
void			fill_floor_ceiling(t_cub *cub, int x);
int				distance_color(int c, double d);
t_texture		*get_text_dir(t_cub *cub);
void			draw_textures(t_cub *cub, int x);
// MINIMAP
void			render_minimap(t_cub *cub);
// MLX Helpers
void			mlx_draw_imagegiven(t_cub *cub);
void			destroy_mlx_image(t_cub *cub);
void			create_mlx_data(t_cub *cub);
// MOVEMENT
void			move(t_cub *cub);
int				mouse_handler(t_cub *cub);
void			rotate_right(t_cub *cub);
void			rotate_left(t_cub *cub);
// SPAWNING
int				spawn_west(t_cub *cub);
int				spawn_north(t_cub *cub);
int				spawn_east(t_cub *cub);
int				spawn_south(t_cub *cub);
// CLEAR DATA
int				clear_data(t_cub *cub);
// UTILS
double			ternary_double(bool statement, double is_true, double is_false);
void			exit_on_error(void);
void			exit_on_texture_error(void);
bool			check_rgb_valid(int r, int g, int b);
#endif