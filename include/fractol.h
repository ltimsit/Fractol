/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:33:30 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/23 13:23:36 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include "mlx.h"
# include <pthread.h>
# include <math.h>
# define WIN_HEIGHT 600
# define WIN_LENGTH 1200
# define HEIGHT 600
# define LENGTH 900
# define HEIGHT_PANEL 100
# define HEIGHT_PANEL2 200
# define HEIGHT_PANEL3 200
# define LENGTH_PANEL 300
# define LENGTH_PANEL2 300
# define LENGTH_PANEL3 300
# define ZOOM_INIT 300.0
# define ITER_INIT 50
# define ZOOM_SPEED 1.3

enum	e_fractal_nb
{
	julia,
	mandelbrot,
	burningship,
	end_fractal
};

typedef struct		s_win_data
{
	int				wx;
	int				wy;
}					t_win_data;

typedef struct		s_fparam
{
	double			ofx;
	double			ofy;
	unsigned int	color_b;
	unsigned int	color_g;
	unsigned int	color_r;
	int				color_main;
	double			zoom;
	int				iter;
	int				stop;
	double			cstr;
	double			cstim;
}					t_fparam;

typedef struct		s_fmlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	void			*panel_img;
	void			*panel_data;
	int				f_nb;
	int				(*f_ft_tab[3])(void *, struct s_fparam);
	int				ty;
	t_win_data		wdata;
	t_fparam		param;
}					t_fmlx;

typedef struct		s_data
{
	t_fmlx			*fptr;
	double			y;
	double			x;
	int				y_max;
	double			re;
	double			im;
	int				color_var;
	int				*data_t;
}					t_data;

int					init_wd(t_fmlx *ftol);
void				init_fdata(t_fmlx *ftol);
char				*get_data_ptr(void *img_ptr);
void				finish(t_fmlx *ftol);
void				create_side_image(t_fmlx *ftol);
void				color_panel(t_fmlx *ftol);
void				color_block(t_fmlx *ftol);
int					key_press(int keycode, void *param);
int					mouse_press(int keycode, int x, int y, void *param);
int					key_press(int keycode, void *param);
int					mouse_mov(int x, int y, void *param);
int					close_x(void *param);
int					get_color_px(void *mlxptr, int ret, t_fparam param);
void				*fractol_calc_mandel(void *ftol);
void				init_wdata(t_fmlx *ftol);
int					manage_thread(t_fmlx *ftol);
int					mandel_calc(void *dataptr, t_fparam param);
int					julia_calc(void *dataptr, t_fparam param);
int					bs_calc(void *dataptr, t_fparam param);
int					bs_test_calc(void *dataptr, t_fparam param);
int					test_calc(void *dataptr, t_fparam param);

int					zoom(t_fmlx *ftol, int keycode, int x, int y);
int					change_color(int keycode, t_fmlx *ftol);
int					change_cst_julia(int x, int y, t_fmlx *ftol);
int					change_fractal(int keycode, t_fmlx *ftol);
int					change_fractal_clic(int x, int y, t_fmlx *ftol);
int					translation(int keycode, t_fmlx *ftol);
#endif
