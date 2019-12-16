/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:54:03 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/16 17:52:27 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_mov(int x, int y, void *param)
{
	if (!(((t_fmlx *)param)->param.stop)
			&& (((t_fmlx *)param)->f_nb == 0))
		change_cst_julia(x, y, (t_fmlx *)param);
	return (0);
}

int		mouse_press(int keycode, int x, int y, void *param)
{
	if ((keycode == 4 || keycode == 5) && (((t_fmlx *)param)->param.stop
				|| ((t_fmlx *)param)->f_nb != 0))
		zoom((t_fmlx *)param, keycode, x, y);
	if (keycode == 1)
		change_fractal_clic(x, y, (t_fmlx *)param);
	return (0);
}

int		close_x(void *param)
{
	finish((t_fmlx *)param);
	return (0);
}

int		key_press(int keycode, void *param)
{
	if (keycode == 53)
		finish((t_fmlx *)param);
	if (keycode == 49)
		((t_fmlx *)param)->param.stop = ((t_fmlx *)param)->param.stop == 1
			? 0 : 1;
	if (keycode == 38 || keycode == 46 || keycode == 11)
		change_fractal(keycode, (t_fmlx *)param);
	if (keycode == 86 || keycode == 83 || keycode == 87 || keycode == 84
			|| keycode == 88 || keycode == 85 || keycode == 71)
		change_color(keycode, (t_fmlx *)param);
	if (keycode >= 123 && keycode <= 126)
		translation(keycode, (t_fmlx *)param);
	return (0);
}
