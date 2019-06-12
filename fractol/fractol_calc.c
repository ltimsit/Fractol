/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:14:36 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/12 19:37:43 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>


/*
int		check_julia(double param.re, double paparam.ream.im, double cstr, double cstim)
{
	int i;
	double tmp;
	double abs;

	i = 0;
	while (i < 2)
	{
		tmp = param.re * param.re - param.im * param.im + cstr;
		param.im = 2 * param.re * param.im + cstim;
		param.re = tmp;
		abs = param.re * param.re + param.im * param.im;
		if (abs > 4)
			return (i);
		i++;
	}
	return (-1);
}
*/

int		check_if_div(t_data *data, t_fparam param, double cstr, double cstim)
{
	int i;
	double tmp;
	double abs;

	i = 0;
	while (i < param.iter)
	{
		tmp = data->re * data->re - data->im * data->im + cstr;
		data->im = 2 * data->re * data->im + cstim;
		data->re = tmp;
		abs = data->re * data->re + data->im * data->im;
		if (abs > 4)
			return (i);
		i++;
	}
	return (-1);
}

void		*fractol_calc_mandel(void *data)
{
	int x;
	int y;
	double cst;
	int ret;
	double ofx;
	double ofy;
//	pthread_t	tr;
	t_fmlx	*ftol2;

	ftol2 = (t_fmlx *)(((t_data *)data)->fptr);
	y = ((t_data *)data)->y;
/*
	if (ftol2->ty < ftol2->wdata.wy)
	{
		ftol2->ty++;
		pthread_create(&tr, NULL, fractol_calc_mandel, ftol2);
	}
	else
	{
		pthread_exit(NULL);
		return (NULL);
	}
	*/
	ofx = ftol2->param.ofx;
	ofy = ftol2->param.ofy;
	cst = 0.08;
		
	x = 0;
	while (x < ftol2->wdata.wx)
	{
		((t_data *)data)->re = (((double)x - ofx) / ftol2->wdata.zoom);
		((t_data *)data)->im = (((double)y - ofy) / ftol2->wdata.zoom);
		if ((ret = check_if_div((t_data *)data, ftol2->param, 0.4, 0.34)) == -1)
			*((int *)ftol2->data_ptr + (ftol2->wdata.wx * y + x)) = 0xFFFFFF;
		else
			*((int *)ftol2->data_ptr + (ftol2->wdata.wx * y + x)) = 0x000000 + ret * 200;
		x++;
	}
//	pthread_join(tr, NULL);
	pthread_exit(NULL);
	return (NULL);
}

/*
   int		fractol_calc_mandel(t_fmlx *ftol)
   {
   int x;
   int y;
   double cst;
	int ret;
	double ofx;
	double ofy;
	pthread_t	tr;

	pthread_create(&tr, NULL, fractol_calc_mendel, ftol);
	y = 0;
	ofx = ftol->param.ofx;
	ofy = ftol->param.ofy;
	cst = 0.08;
	while (y < ftol->wdata.wy)
	{
		x = 0;
		while (x < ftol->wdata.wx)
		{
			ftol->param.re = (((double)x - ofx) / ftol->wdata.zoom);
			ftol->param.im = (((double)y - ofy) / ftol->wdata.zoom);
			if ((ret = check_if_div(ftol->param, 0.4, 0.34)) == -1)
				*((int *)ftol->data_ptr + (ftol->wdata.wx * y + x)) = 0xFFFFFF;
			else
				*((int *)ftol->data_ptr + (ftol->wdata.wx * y + x)) = 0x000000 + ret * 200;
			x++;
		}
		y++;
	}
	return (0);
}
*/
