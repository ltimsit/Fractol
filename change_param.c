/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:56:57 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/16 17:50:45 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom(t_fmlx *ftol, int keycode, int x, int y)
{
	if (keycode == 4)
	{
		ftol->param.ofx = (x / ftol->param.zoom + ftol->param.ofx)
			- (x / (ftol->param.zoom * ZOOM_SPEED));
		ftol->param.ofy = (y / ftol->param.zoom + ftol->param.ofy)
			- (y / (ftol->param.zoom * ZOOM_SPEED));
		ftol->param.zoom *= ZOOM_SPEED;
		ftol->param.iter++;
	}
	if (keycode == 5)
	{
		ftol->param.ofx = (x / ftol->param.zoom + ftol->param.ofx)
			- (x / (ftol->param.zoom / ZOOM_SPEED));
		ftol->param.ofy = (y / ftol->param.zoom + ftol->param.ofy)
			- (y / (ftol->param.zoom / ZOOM_SPEED));
		ftol->param.zoom /= 1.3;
		ftol->param.iter--;
	}
	manage_thread(ftol);
	return (0);
}

int		change_color(int keycode, t_fmlx *ftol)
{
	if (keycode == 86)
		ftol->param.color_b += 5;
	if (keycode == 83)
		ftol->param.color_b -= 5;
	if (keycode == 87)
		ftol->param.color_g += 5;
	if (keycode == 84)
		ftol->param.color_g -= 5;
	if (keycode == 88)
		ftol->param.color_r += 5;
	if (keycode == 85)
		ftol->param.color_r -= 5;
	if (keycode == 71)
	{
		ftol->param.color_b = 5;
		ftol->param.color_g = 5;
		ftol->param.color_r = 5;
	}
	manage_thread(ftol);
	return (0);
}

int		change_cst_julia(int x, int y, t_fmlx *ftol)
{
	ftol->param.cstr = (double)((x) / (ftol->param.zoom)) + ftol->param.ofx;
	ftol->param.cstim = (double)((y) / ftol->param.zoom) + ftol->param.ofy;
	manage_thread(ftol);
	return (0);
}

int		translation(int keycode, t_fmlx *ftol)
{
	if (ftol->param.stop == 0 && ftol->f_nb == 0)
		return (0);
	if (keycode == 123 || keycode == 124)
		ftol->param.ofx += keycode == 124 ? 20 / ftol->param.zoom
			: -20 / ftol->param.zoom;
	if (keycode == 125 || keycode == 126)
		ftol->param.ofy += keycode == 125 ? 20 / ftol->param.zoom
			: -20 / ftol->param.zoom;
	manage_thread(ftol);
	return (0);
}
