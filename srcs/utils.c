/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgobeil- <pgobeil-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:53:49 by pgobeil-          #+#    #+#             */
/*   Updated: 2019/11/23 23:07:09 by pgobeil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*colors(void)
{
	int *colors;

	colors = (int *)malloc(sizeof(int) * 16);
	colors[0] = 0x421E0F;
	colors[1] = 0x19071A;
	colors[2] = 0x09012F;
	colors[3] = 0x040449;
	colors[4] = 0x000764;
	colors[5] = 0x0C2C8A;
	colors[6] = 0x1852B1;
	colors[7] = 0x397DD1;
	colors[8] = 0x86B5E5;
	colors[9] = 0xD3ECF8;
	colors[10] = 0xF1E9BF;
	colors[11] = 0xF8C95F;
	colors[12] = 0xFFAA00;
	colors[13] = 0xCC8000;
	colors[14] = 0x995700;
	colors[15] = 0x6A3403;
	return (colors);
}

void	pxto_win(int x, int y, int color, t_mlx *mlx)
{
	int index;

	color = mlx_get_color_value(mlx->mlx_ptr, color);
	index = (4 * WIDTH * y + x * 4);
	ft_memcpy(mlx->pixs + index, &color, sizeof(int));
}

void	offset(int key, t_mlx *mlx)
{
	if (key == 126)
		mlx->m->movey += (0.04 / mlx->m->zoom);
	if (key == 125)
		mlx->m->movey -= (0.04 / mlx->m->zoom);
	if (key == 124)
		mlx->m->movex += (0.04 / mlx->m->zoom);
	if (key == 123)
		mlx->m->movex -= (0.04 / mlx->m->zoom);
	if (key == 37)
		mlx->m->zoom *= 1.50;
	if (key == 40)
		mlx->m->zoom *= 0.75;
	draw_fractal(mlx, mlx->m);
}

int		pick_fract(char *str)
{
	int i;

	i = -1;
	if (ft_strcmp("Mandelbrot", str) == 0)
		i = 0;
	if (ft_strcmp("mandelbrot", str) == 0)
		i = 0;
	if (ft_strcmp("0", str) == 0)
		i = 0;
	if (ft_strcmp("julia", str) == 0)
		i = 1;
	if (ft_strcmp("Julia", str) == 0)
		i = 1;
	if (ft_strcmp("1", str) == 0)
		i = 1;
	if (ft_strcmp("tricorn", str) == 0)
		i = 2;
	if (ft_strcmp("Tricorn", str) == 0)
		i = 2;
	if (ft_strcmp("2", str) == 0)
		i = 2;
	return (i);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		exit(0);
	}
	if (key == 123 || key == 124 || key == 125 ||
		key == 126 || key == 37 || key == 40)
		offset(key, mlx);
	if (key == 34)
	{
		mlx->m->cp_iter += 5;
		draw_fractal(mlx, mlx->m);
	}
	if (key == 31)
	{
		mlx->m->cp_iter -= 5;
		draw_fractal(mlx, mlx->m);
	}
	return (0);
}
