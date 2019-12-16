/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:52:24 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/16 16:38:14 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		change_fractal(int keycode, t_fmlx *ftol)
{
	if (keycode == 38)
		ftol->f_nb = 0;
	else if (keycode == 46)
		ftol->f_nb = 1;
	else if (keycode == 11)
		ftol->f_nb = 2;
	init_fdata(ftol);
	manage_thread(ftol);
	return (0);
}

int		change_fractal_clic(int x, int y, t_fmlx *ftol)
{
	if (x > LENGTH && x < WIN_LENGTH)
	{
		if (y >= 45 && y <= 80)
			ftol->f_nb = 0;
		else if (y >= 95 && y <= 130)
			ftol->f_nb = 1;
		else if (y >= 145 && y <= 180)
			ftol->f_nb = 2;
		else
			return (0);
	}
	else
		return (0);
	init_fdata(ftol);
	manage_thread(ftol);
	return (0);
}
