/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgobeil- <pgobeil-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:56:36 by pgobeil-          #+#    #+#             */
/*   Updated: 2019/11/25 00:08:09 by pgobeil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_mlx *mlx, t_mov *m)
{
	mlx->sline = 0;
	mlx->bpp = 4;
	mlx->endian = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "FRACTOL");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->pixs = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,\
	&mlx->sline, &mlx->endian);
	m->zoom = 1;
	m->movex = -0.5;
	m->movey = 0;
	m->cp_iter = 30;
	mlx->m = m;
}

int		move_point(int x, int y, t_mlx *mlx)
{
	mlx->m->movex += (double)(x - WIDTH / 2) * 0.00005;
	mlx->m->movey += (double)(y - HEIGHT / 2) * 0.00005;
	return (0);
}

int		do_mouse(int key, int x, int y, t_mlx *mlx)
{
	if (mlx->fra == 1)
	{
		move_point(x, y, mlx);
		draw_fractal(mlx, mlx->m);
	}
	if (key == 4)
	{
		mlx->m->zoom *= 1.1;
		draw_fractal(mlx, mlx->m);
	}
	if (key == 5)
	{
		mlx->m->zoom *= 0.9;
		draw_fractal(mlx, mlx->m);
	}
	return (0);
}

int		do_jul_mov(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= 1000 && y <= 1000 && y >= 0)
	{
		move_point(x, y, mlx);
		draw_fractal(mlx, mlx->m);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_mov	m;

	if (argc != 2 || (mlx.fra = pick_fract(argv[1])) < 0)
		return (err_ret("./fractal [mandelbrot || julia || tricorn]"));
	init(&mlx, &m);
	mlx.colors = colors();
	draw_fractal(&mlx, &m);
	mlx_key_hook(mlx.win_ptr, deal_key, (void *)&mlx);
	(mlx.fra != 1) ? mlx_mouse_hook(mlx.win_ptr, do_mouse, (void *)&mlx) :\
	mlx_hook(mlx.win_ptr, 6, 0, do_jul_mov, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
