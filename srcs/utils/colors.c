/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:55:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/07/25 13:57:41 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	draw_pixel(t_fractal *fr, int y, int x, int color)
{
	if (x < 0 || x > fr->winW || y < 0 || y > fr->winH)
		return ;
	fr->img.addr[fr->winW * y + x] = color;
}

int	get_colors(int i)
{
	return (i % 256 << 16 | 255 << 8 | 255 * i);
}
