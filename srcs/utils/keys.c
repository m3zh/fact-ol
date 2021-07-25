/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:57:35 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 07:38:49 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	key_press(int keycode, t_fractal *fr)
{
	if (keycode == RIGHT_KEY)
		fr->move.rotright = 1;
	if (keycode == LEFT_KEY)
		fr->move.rotleft = 1;
	if (keycode == A_KEY)
		fr->move.left = 1;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		fr->move.back = 1;
	if (keycode == D_KEY)
		fr->move.right = 1;
	if (keycode == W_KEY || keycode == UP_KEY)
		fr->move.forw = 1;
	if (keycode == Q_KEY || keycode == ESC_KEY)
		free_fractal(fr);
	return (1);
}

int	key_release(int keycode, t_fractal *fr)
{
	if (keycode == A_KEY)
		fr->move.left = 0;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		fr->move.back = 0;
	if (keycode == D_KEY)
		fr->move.right = 0;
	if (keycode == W_KEY || keycode == UP_KEY)
		fr->move.forw = 0;
	if (keycode == RIGHT_KEY)
		fr->move.rotright = 0;
	if (keycode == LEFT_KEY)
		fr->move.rotleft = 0;
	return (1);
}

int	x_exit(t_fractal *fr)
{
	free_fractal(fr);
	return (0);
}
