Cub3D


TODO;


TODO;

We could draw an image, but we do not display it yet

cub->data.img = mlx_new_image(cub->vars.mlx, WIDTH, HEIGHT);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
			&cub->data.line_length, &cub->data.endian);

is missing in the render loop.
Also we do not have floors or ceiling implemented, neither textures

```c->math->lineHeight = (int)(HEIGHT / c->math->perpWallDist);
c->math->drawStart = -c->math->lineHeight / 2 + HEIGHT / 2;
if(c->math->drawStart < 0) c->math->drawStart = 0;
c->math->drawEnd = c->math->lineHeight / 2 + HEIGHT / 2;
if(c->math->drawEnd >= c->math->lineHeight) c->math->drawEnd = HEIGHT - 1;```

could be used to calculate drawEnd and drawHeight


and the render loop could look something like this



```cub->data.img = mlx_new_image(cub->vars.mlx, WIDTH, HEIGHT);
	cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel,
			&cub->data.line_length, &cub->data.endian);
	while (x < (int)WIDTH)
	{
		render_walls(cub, x);
		draw_line_color(cub, create_vector(x, cub->math->drawStart), create_vector(x, cub->math->drawEnd), 8355711);
		x++;
	}
	mlx_put_image_to_window(cub->vars.mlx, cub->vars.win, cub->data.img, 0, 0);```