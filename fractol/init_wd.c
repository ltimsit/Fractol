/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:15:19 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/12 19:37:39 by ltimsit-         ###   ########.fr       */
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

int		zoom(t_fmlx *ftol, int keycode, int x, int y)
{
	//pthread_t tr;
	if (keycode == 4)
	{
		ftol->wdata.zoom *= 1.05;
		ftol->param.ofx += (900.0 - (double)x) / (ftol->wdata.zoom / 100.0);
		ftol->param.ofy += (600.0 - (double)y) / (ftol->wdata.zoom / 100.0);
	}
	if (keycode == 5)
	{
		ftol->wdata.zoom *= 0.95;
		ftol->param.ofx -= (900 - (double)x) * 0.05;
		ftol->param.ofy -= (600.0 - (double)y) * 0.05;
	}
	mlx_clear_window(ftol->mlx_ptr, ftol->win_ptr);
/*
	pthread_create(&tr, NULL, fractol_calc_mandel, ftol);
	pthread_join(tr, NULL);
	ftol->ty = 0;
	*/
	manage_thread(ftol);
	mlx_put_image_to_window(ftol->mlx_ptr, ftol->win_ptr, ftol->img_ptr, 0, 0);
	return (0);
}

int		mouse_press(int keycode, int x, int y, void *param)
{
	(void)x;
	(void)y;
	if (keycode == 4 || keycode == 5)
		zoom((t_fmlx *)param, keycode, x, y);
	return (0);
}

int		key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
	{
		mlx_destroy_image(((t_fmlx *)param)->mlx_ptr, ((t_fmlx *)param)->img_ptr);
		exit(0);
	}
	return (0);
}

void	init_wdata(t_fmlx *ftol)
{
	ftol->wdata.wx = 1800;
	ftol->wdata.wy = 1200;
	ftol->wdata.zoom = 300.0;
	ftol->param.ofx = (ftol->wdata.wx / 2.0);
	ftol->param.ofy = (ftol->wdata.wy / 2.0);
	ftol->param.iter = 50;
	ftol->ty = 0;
}

int		init_wd(t_fmlx *ftol)
{
	//pthread_t	tr;

	ftol->mlx_ptr = mlx_init();
	init_wdata(ftol);
	ftol->win_ptr = mlx_new_window(ftol->mlx_ptr, 1800, 1200, "Fractol");
	ftol->img_ptr = mlx_new_image(ftol->mlx_ptr, 1800, 1200);
	ftol->data_ptr = get_data_ptr(ftol->img_ptr);
	manage_thread(ftol);
/*
	pthread_create(&tr, NULL, fractol_calc_mandel, ftol);
	pthread_join(tr, NULL);
	*/
	mlx_put_image_to_window(ftol->mlx_ptr, ftol->win_ptr, ftol->img_ptr, 0, 0);
	mlx_hook(ftol->win_ptr, 2, 0, key_press, ftol);
	mlx_hook(ftol->win_ptr, 4, 0, mouse_press, ftol);
	mlx_loop(ftol->mlx_ptr);
	return (0);
}
