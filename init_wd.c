/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:15:19 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/23 13:23:28 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*get_data_ptr(void *img_ptr)
{
	char	*data_ptr;
	int		bit_pp;
	int		size_line;
	int		endian;

	data_ptr = mlx_get_data_addr(img_ptr, &bit_pp, &size_line, &endian);
	return (data_ptr);
}

void	init_fdata(t_fmlx *ftol)
{
	ftol->param.zoom = ZOOM_INIT;
	ftol->param.ofx = -((double)ftol->wdata.wx / 2) / ZOOM_INIT;
	ftol->param.ofy = -((double)ftol->wdata.wy / 2) / ZOOM_INIT;
	ftol->param.iter = ITER_INIT;
	ftol->param.stop = 0;
	ftol->param.cstr = 0.0;
	ftol->param.cstim = 0.0;
	ftol->param.color_b = 5;
	ftol->param.color_g = 5;
	ftol->param.color_r = 5;
	ftol->param.color_main = 0xFFFFB0;
}

void	init_wdata(t_fmlx *ftol)
{
	ftol->wdata.wx = LENGTH;
	ftol->wdata.wy = HEIGHT;
	ftol->f_ft_tab[0] = julia_calc;
	ftol->f_ft_tab[1] = mandel_calc;
	ftol->f_ft_tab[2] = bs_calc;
	init_fdata(ftol);
	ftol->ty = 0;
}

int		init_wd(t_fmlx *ftol)
{
	ftol->mlx_ptr = mlx_init();
	init_wdata(ftol);
	ftol->win_ptr = mlx_new_window(ftol->mlx_ptr, WIN_LENGTH, WIN_HEIGHT
			, "Fractol");
	ftol->img_ptr = mlx_new_image(ftol->mlx_ptr, LENGTH, HEIGHT);
	ftol->data_ptr = get_data_ptr(ftol->img_ptr);
	color_panel(ftol);
	manage_thread(ftol);
	mlx_hook(ftol->win_ptr, 2, 0, key_press, ftol);
	mlx_hook(ftol->win_ptr, 4, 0, mouse_press, ftol);
	mlx_hook(ftol->win_ptr, 17, 0, close_x, ftol);
	if (!(ftol->param.stop))
		mlx_hook(ftol->win_ptr, 6, 0, mouse_mov, ftol);
	mlx_loop(ftol->mlx_ptr);
	return (0);
}
