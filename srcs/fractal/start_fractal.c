/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:41:56 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/09 07:41:00 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	swap_frame(t_fractal *fr)
{
	void	*frame;
	void	*adr;

	if (fr->img.counter % 2 == 0)
	{
		frame = fr->img.img;
		fr->img.img = fr->img.img2;
		fr->img.img2 = frame;
		adr = fr->img.addr;
		fr->img.addr = fr->img.addr2;
		fr->img.addr2 = adr;
	}
	else
	{
		frame = fr->img.img2;
		fr->img.img2 = fr->img.img;
		fr->img.img = frame;
		adr = fr->img.addr2;
		fr->img.addr2 = fr->img.addr;
		fr->img.addr = adr;
	}
	fr->img.counter++;
}

static int	fractal_loop(t_fractal *fr)
{	
	if (fr->win)
	{
		draw_fractal(fr);
		move_backforwards(fr);
		move_leftright(fr);
		// rotate_view(game, fr->player.initx, fr->player.planex);
		swap_frame(fr);
		return (0);
	}
	return (-1);
}

static int	set_window(t_fractal *fr)
{
	if (!fr->set)
		fr->win = mlx_new_window(fr->mlx, fr->winW,
				fr->winH, "julia set fractal");
	else
		fr->win = mlx_new_window(fr->mlx, fr->winW,
				fr->winH, "mandelbrot set fractal");
	if (!fr->win)
		return (free_window(fr));
	fr->img.img = mlx_new_image(fr->mlx, fr->winW,
			fr->winH);
	fr->img.addr = (int *)mlx_get_data_addr(fr->img.img,
			&fr->img.bits_per_pixel,
			&fr->img.line_length, &fr->img.endian);
	fr->img.img2 = mlx_new_image(fr->mlx, fr->winW,
			fr->winH);
	fr->img.addr2 = (int *)mlx_get_data_addr(fr->img.img2,
			&fr->img.bits_per_pixel,
			&fr->img.line_length, &fr->img.endian);
	fr->img.counter = 0;
	if (!fr->img.img || !fr->img.img2
		|| !fr->img.addr || !fr->img.addr2)
		return (free_dataimg(fr));
	return (1);
}

void	fractals_magic(char *set)
{
	t_fractal	fr;

	init_fractal(&fr, set);
	fr.mlx = mlx_init();
	if (!fr.mlx)
		return (perror("Error\nMlx failed to initialise\n"));
	if (!set_window(&fr))
		return ;
	mlx_hook(fr.win, 33, 1L << 17, x_exit, &fr);
	mlx_hook(fr.win, 2, 1L << 0, key_press, &fr);
	mlx_loop_hook(fr.mlx, fractal_loop, &fr);
	mlx_hook(fr.win, 3, 1L << 1, key_release, &fr);
	mlx_loop(fr.mlx);
	mlx_destroy_display(fr.mlx);
	free(fr.mlx);
	return ;
}
