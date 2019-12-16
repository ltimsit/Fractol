/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:38:03 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/22 19:39:54 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_block(t_fmlx *ftol)
{
	int				x;
	int				y;
	unsigned int	*tab;

	tab = (unsigned int*)ftol->panel_data;
	y = 0;
	while (y < HEIGHT_PANEL)
	{
		x = 0;
		while (x < 100)
			tab[y * LENGTH_PANEL + x++] = (uint8_t)ftol->param.color_b;
		while (x < 200)
			(tab[y * LENGTH_PANEL + x++]) = (int)((uint8_t)ftol->param.color_g)
				<< 8;
		while (x < 300)
			(tab[y * LENGTH_PANEL + x++]) = (int)((uint8_t)ftol->param.color_r)
				<< 16;
		y++;
	}
	mlx_put_image_to_window(ftol->mlx_ptr, ftol->win_ptr, ftol->panel_img,
			900, 500);
}

void	color_panel(t_fmlx *ftol)
{
	ftol->panel_img = mlx_new_image(ftol->mlx_ptr, LENGTH_PANEL, HEIGHT_PANEL);
	ftol->panel_data = get_data_ptr(ftol->panel_img);
	color_block(ftol);
}

void	create_side_image(t_fmlx *ftol)
{
	mlx_string_put(ftol->mlx_ptr, ftol->win_ptr, 920, 50, 0xFFFFFF,
			"Julia");
	mlx_string_put(ftol->mlx_ptr, ftol->win_ptr, 920, 100, 0xFFFFFF,
			"Mandelbrot");
	mlx_string_put(ftol->mlx_ptr, ftol->win_ptr, 920, 150, 0xFFFFFF,
			"Burningship");
}
