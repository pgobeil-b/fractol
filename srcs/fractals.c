/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgobeil- <pgobeil-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:40:49 by pgobeil-          #+#    #+#             */
/*   Updated: 2019/11/24 00:39:27 by pgobeil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		tricorn(int x, int y, int cp_iter, t_mov *m)
{
	int		i;
	t_cmplx c;
	t_cmplx new;
	t_cmplx old;

	c.r = 3.5 * (x - WIDTH / 2) / (1 * m->zoom * WIDTH) + m->movex;
	c.i = 2 * (y - HEIGHT / 2) / (1 * m->zoom * HEIGHT) + m->movey;
	new.r = 0;
	new.i = 0;
	old.r = 0;
	old.i = 0;
	i = 0;
	while (i < cp_iter)
	{
		old.r = (new.r);
		old.i = (new.i);
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = -2 * (old.r * old.i) + c.i;
		if (new.r * new.r + new.i * new.i > 4)
			break ;
		i++;
	}
	return (i);
}

int		julia(int x, int y, int cp_iter, t_mov *m)
{
	int		i;
	t_cmplx p;
	t_cmplx new;
	t_cmplx old;

	p.r = m->movex;
	p.i = m->movey;
	new.r = 1.5 * (x - WIDTH / 2) / (0.5 * m->zoom * WIDTH);
	new.i = (y - HEIGHT / 2) / (0.5 * m->zoom * HEIGHT);
	i = 0;
	while (i < cp_iter)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + p.r;
		new.i = 2 * old.r * old.i + p.i;
		if (new.r * new.r + new.i * new.i > 4)
			break ;
		i++;
	}
	return (i);
}

int		new_mandelboy(int x, int y, int cp_iter, t_mov *m)
{
	int		i;
	t_cmplx p;
	t_cmplx new;
	t_cmplx old;

	p.r = 1.5 * (x - WIDTH / 2) / (0.5 * m->zoom * WIDTH) + m->movex;
	p.i = (y - HEIGHT / 2) / (0.5 * m->zoom * HEIGHT) + m->movey;
	new.r = 0;
	new.i = 0;
	old.r = 0;
	old.i = 0;
	i = 0;
	while (i < cp_iter)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + p.r;
		new.i = 2 * old.r * old.i + p.i;
		if (new.r * new.r + new.i * new.i > 4)
			break ;
		i++;
	}
	return (i);
}

void	draw_fractal(t_mlx *mlx, t_mov *m)
{
	int y;
	int x;
	int i;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (mlx->fra == 2)
				i = tricorn(x, y, m->cp_iter, m);
			else
				i = (mlx->fra == 0) ? new_mandelboy(x, y, m->cp_iter, m)
			: julia(x, y, m->cp_iter, m);
			color = (i == m->cp_iter) ? 0x000000 : mlx->colors[i % 16];
			pxto_win(x, y, color, mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
