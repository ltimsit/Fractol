/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:54:20 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/21 16:36:36 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		finish(t_fmlx *ftol)
{
	mlx_destroy_image(ftol->mlx_ptr, ftol->img_ptr);
	mlx_destroy_image(ftol->mlx_ptr, ftol->panel_img);
	exit(0);
}

void		thread_call(t_data *data, t_fmlx *ftol, pthread_t *t_tab, int i)
{
	int			zone;

	zone = ftol->wdata.wy / 8;
	data->y = zone * i;
	data->x = 0;
	data->y_max = zone * i + zone;
	data->fptr = ftol;
	data->data_t = (int *)ftol->data_ptr;
	if (pthread_create(t_tab, NULL, fractol_calc_mandel, (void *)data))
		finish(ftol);
}

int			manage_thread(t_fmlx *ftol)
{
	int			i;
	t_data		data[8];
	pthread_t	t_tab[8];

	mlx_clear_window(ftol->mlx_ptr, ftol->win_ptr);
	i = -1;
	while (++i < 8)
		thread_call(&data[i], ftol, &t_tab[i], i);
	while (i--)
		if (pthread_join(t_tab[i], NULL))
			finish(ftol);
	ftol->ty = 0;
	mlx_put_image_to_window(ftol->mlx_ptr, ftol->win_ptr, ftol->img_ptr, 0, 0);
	create_side_image(ftol);
	color_block(ftol);
	return (0);
}
