/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgobeil- <pgobeil-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:28:02 by pgobeil-          #+#    #+#             */
/*   Updated: 2019/11/24 00:43:15 by pgobeil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1050
# define HEIGHT 600
# define MAX_ITER 100
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_pos{
	int				xscale;
	int				yscale;
	int				xoff;
	int				yoff;
}					t_pos;

typedef	struct		s_map{
	double			cxmin;
	double			cxmax;
	double			cymin;
	double			cymax;
}					t_map;

typedef struct		s_cmplx{
	double			r;
	double			i;
}					t_cmplx;

typedef struct		s_mov{
	double			zoom;
	double			movex;
	double			movey;
	int				cp_iter;
}					t_mov;

typedef struct		s_mlx{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				sline;
	int				endian;
	int				bpp;
	int				fra;
	int				*colors;
	char			*pixs;
	t_pos			*p;
	t_map			*c;
	t_mov			*m;
}					t_mlx;

int					map_color(int n);
int					new_mandelboy(int x, int y, int cp_iter, t_mov *m);
int					julia(int x, int y, int cp_iter, t_mov *m);
int					burning_ship(int x, int y, int cp_iter, t_mov *m);
int					deal_key(int key, t_mlx *mlx);
int					pick_fract(char *str);
int					*colors();

void				draw_fractal(t_mlx *mlx, t_mov *m);
void				pxto_win(int x, int y, int color, t_mlx *mlx);
void				resize(t_map *c, t_pos *p);
void				offset(int key, t_mlx *mlx);
void				draw_stuff(t_mlx *mlx, t_pos *pnt, t_map *pos);

#endif
