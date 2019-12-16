/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:14:36 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/23 13:23:47 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		bs_calc(void *dataptr, t_fparam param)
{
	int		i;
	double	tmp;
	double	abs;
	t_data	*data;

	data = (t_data *)dataptr;
	data->re = ((data->x / param.zoom) + param.ofx);
	data->im = ((data->y / param.zoom) + param.ofy);
	param.cstr = data->re;
	param.cstim = data->im;
	i = 0;
	while (i < param.iter)
	{
		tmp = fabs(data->re) * fabs(data->re) - fabs(data->im) * fabs(data->im)
			+ param.cstr;
		data->im = 2 * fabs(data->re) * fabs(data->im) + param.cstim;
		data->re = tmp;
		abs = data->re * data->re + data->im * data->im;
		if (abs > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		mandel_calc(void *dataptr, t_fparam param)
{
	int		i;
	double	tmp;
	double	abs;
	t_data	*data;

	data = (t_data *)dataptr;
	data->re = ((data->x / param.zoom) + param.ofx);
	data->im = ((data->y / param.zoom) + param.ofy);
	param.cstr = data->re;
	param.cstim = data->im;
	i = 0;
	while (i < param.iter)
	{
		tmp = data->re * data->re - data->im * data->im + param.cstr;
		data->im = 2 * data->re * data->im + param.cstim;
		data->re = tmp;
		abs = data->re * data->re + data->im * data->im;
		if (abs > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		julia_calc(void *dataptr, t_fparam param)
{
	int		i;
	double	tmp;
	double	abs;
	t_data	*data;

	data = (t_data *)dataptr;
	data->re = ((data->x / param.zoom) + param.ofx);
	data->im = ((data->y / param.zoom) + param.ofy);
	i = 0;
	while (i < param.iter)
	{
		tmp = data->re * data->re - data->im * data->im + param.cstr;
		data->im = 2 * data->re * data->im + param.cstim;
		data->re = tmp;
		abs = data->re * data->re + data->im * data->im;
		if (abs > 4)
			return (i);
		i++;
	}
	return (-1);
}

int		get_color_px(void *mlxptr, int ret, t_fparam param)
{
	uint8_t tab[4];

	tab[0] = ret * param.color_b;
	tab[1] = ret * param.color_g;
	tab[2] = ret * param.color_r;
	tab[3] = 0;
	return (mlx_get_color_value(mlxptr, *((int *)tab)));
}

void	*fractol_calc_mandel(void *dataptr)
{
	t_data	*data;
	int		ret;
	t_fmlx	*ftol;

	data = (t_data *)dataptr;
	ftol = data->fptr;
	while (data->y < data->y_max)
	{
		data->x = 0;
		while (data->x < ftol->wdata.wx)
		{
			if ((ret = ftol->f_ft_tab[ftol->f_nb](dataptr, ftol->param)) == -1)
				(data->data_t + (int)data->y * ftol->wdata.wx)[(int)data->x] =
					ftol->param.color_main;
			else
				(data->data_t + (int)data->y * ftol->wdata.wx)[(int)data->x] =
					get_color_px(ftol->mlx_ptr, ret, ftol->param);
			data->x++;
		}
		data->y++;
	}
	pthread_exit(NULL);
	return (NULL);
}
