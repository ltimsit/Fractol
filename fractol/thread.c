/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:54:20 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/12 19:37:41 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int manage_thread(t_fmlx *ftol)
{
	int			i;
	t_data		data[1200];
	pthread_t	tab_thread[1200];

	i = 0;
	while (i < 1200)
	{
		data[i].y = i;
		data[i].fptr = ftol;
		pthread_create(tab_thread + i, NULL, fractol_calc_mandel, (void *)&data[i]);
		i++;
		ftol->ty++;
	}
	while (--i >= 0)
	{
		pthread_join(tab_thread[i], NULL);
	}
	ftol->ty = 0;
	return (0);
}
