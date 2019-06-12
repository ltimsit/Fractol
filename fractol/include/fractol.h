/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:33:30 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/12 19:37:40 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include "mlx.h"
#include <stdio.h>
# include <pthread.h>

enum	e_fractal_nb
{
	julia,
	mandelbrot,
	end_fractal
};

typedef struct		s_win_data
{
	int				wx;
	int				wy;
	double			zoom;
}					t_win_data;

typedef struct		s_fparam
{
	double			ofx;
	double			ofy;
	int				iter;
}					t_fparam;

typedef struct		s_fmlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	int				ty;
//	int				(*fractal_calc_tab[2])()
	t_win_data		wdata;
	t_fparam		param;
}					t_fmlx;

typedef struct		s_data
{
	t_fmlx			*fptr;
	int				y;
	double			re;
	double			im;
}					t_data;

int		init_wd(t_fmlx *ftol);
int		key_press(int keycode, void *param);
int		mouse_press(int keycode, int x, int y, void *param);
void	*fractol_calc_mandel(void *ftol);
void	init_wdata(t_fmlx *ftol);
int		manage_thread(t_fmlx *ftol);

#endif
