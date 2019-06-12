/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:27:48 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/11 13:51:57 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_tab_fractal(char **tab_fractal)
{
	tab_fractal[0] = "Julia";
	tab_fractal[1] = "Mandelbrot";
}

int		print_usage(char **tab_fractal)
{
	int i;

	i = 0;
	ft_printf("usage :\n");
	while (i < end_fractal)
		ft_printf("--> %s\n", tab_fractal[i++]);
	return (0);
}

int		check_arg_fractol(char *arg, char **tab_fractal)
{
	int		i;

	i = 0;
	while (i < end_fractal)
	{
		if (!(ft_strcmp(arg, tab_fractal[i])))
			return (i);
		i++;
	}
	return (-1);
}

int		main(int a, char **v)
{
	int		fractal;
	char	*tab_fractal[3];
	t_fmlx	ftol;

	init_tab_fractal(tab_fractal);
	if (a != 2 || (fractal = check_arg_fractol(v[1], tab_fractal)) == -1)
		return (print_usage(tab_fractal));
	init_wd(&ftol);
	return (0);
}
