/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:14:11 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 07:47:08 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	move_leftright(t_fractal *fr)
{
	if (fr->move.left)
	{
		// if (fr->config.maze[(int)(fr->player.posx - fr->player.inity
		// 		* (SPEED + 0.1))][(int)fr->player.posy] == '0')
		// 	fr->player.posx -= fr->player.inity * SPEED;
		// if (fr->config.maze[(int)fr->player.posx][(int)(fr->player.posy
		// 	+ fr->player.initx * (SPEED + 0.1))] == '0')
		// 	fr->player.posy += fr->player.initx * SPEED;
	}
	if (fr->move.right)
	{
		// if (fr->config.maze[(int)(fr->player.posx + fr->player.inity
		// 		* (SPEED + 0.1))][(int)fr->player.posy] == '0')
		// 	fr->player.posx += fr->player.inity * SPEED;
		// if (fr->config.maze[(int)fr->player.posx][(int)(fr->player.posy
		// 	- fr->player.initx * (SPEED + 0.1))] == '0')
		// 	fr->player.posy -= fr->player.initx * SPEED;
	}
}

void	move_backforwards(t_fractal *fr)
{
	if (fr->move.forw)
	{
		// if (fr->config.maze[(int)(fr->player.posx + fr->player.initx
		// 		* (SPEED + 0.1))][(int)fr->player.posy] == '0')
		// 	fr->player.posx += fr->player.initx * SPEED;
		// if (fr->config.maze[(int)(fr->player.posx)][(int)(fr->player.posy
		// 		+ fr->player.inity * (SPEED + 0.1))] == '0')
		// 	fr->player.posy += fr->player.inity * SPEED;
	}
	if (fr->move.back)
	{
		// if (fr->config.maze[(int)(fr->player.posx - fr->player.initx
		// 		* (SPEED + 0.1))][(int)(fr->player.posy)] == '0')
		// 	fr->player.posx -= fr->player.initx * SPEED;
		// if (fr->config.maze[(int)(fr->player.posx)][(int)(fr->player.posy
		// 	- fr->player.inity * (SPEED + 0.1))] == '0')
		// 	fr->player.posy -= fr->player.inity * SPEED;
	}
}

void	rotate_view(t_fractal *fr) //, double dx, double px)
{
	if (fr->move.rotright)
	{
		// fr->player.initx = fr->player.initx * cos(-ROT)
		// 	- fr->player.inity * sin(-ROT);
		// fr->player.inity = dx * sin(-ROT)
		// 	+ fr->player.inity * cos(-ROT);
		// fr->player.planex = fr->player.planex * cos(-ROT)
		// 	- fr->player.planey * sin(-ROT);
		// fr->player.planey = px * sin(-ROT) + fr->player.planey
		// 	* cos(-ROT);
	}
	if (fr->move.rotleft)
	{
		// fr->player.initx = fr->player.initx * cos(ROT)
		// 	- fr->player.inity * sin(ROT);
		// fr->player.inity = dx * sin(ROT) + fr->player.inity
		// 	* cos(ROT);
		// fr->player.planex = fr->player.planex * cos(ROT)
		// 	- fr->player.planey * sin(ROT);
		// fr->player.planey = px * sin(ROT) + fr->player.planey
		// 	* cos(ROT);
	}
}
