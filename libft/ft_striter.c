/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:32:03 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/12 12:37:22 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_striter(char *s, void (*f)(char *))
{
	while (*s)
		f(s++);
}
