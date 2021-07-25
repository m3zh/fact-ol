/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 09:35:28 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/06 18:53:52 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static int	get_set(char *set)
{
	if (!ft_strcmp(set, "julia"))
		return (0);
	return (1);
}

int	init_fractal(t_fractal *fr, char *set)
{
	fr->winW = SCREENW;
	fr->winH = SCREENH;
	fr->set = get_set(set);
	fr->move.forw = 0;
	fr->move.back = 0;
	fr->move.right = 0;
	fr->move.left = 0;
	fr->move.rotright = 0;
	fr->move.rotleft = 0;
	return (1);
}
