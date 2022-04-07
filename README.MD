Cub3D


TODO;


TODO;

We could draw an image, but we do not display it yet

cub->data.img = mlx_new_image(cub->vars.mlx, WIDTH, HEIGHT);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
			&cub->data.line_length, &cub->data.endian);

is missing in the render loop.
Also we do not have floors or ceiling implemented, neither textures