/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:25:03 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 07:39:36 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	free_fractal(t_fractal *fr)
{
	if (fr->img.img)
		mlx_destroy_image(fr->mlx, fr->img.img);
	if (fr->img.img2)
		mlx_destroy_image(fr->mlx, fr->img.img2);
	if (fr->win)
		mlx_destroy_window(fr->mlx, fr->win);
	fr->win = 0;
}

int	free_window(t_fractal *fr)
{
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	return (0);
}

int	free_dataimg(t_fractal *fr)
{
	printf("Error\nImage data failed to initialise\n");
	if (fr->img.img)
		mlx_destroy_image(fr->mlx, fr->img.img);
	if (fr->img.img2)
		mlx_destroy_image(fr->mlx, fr->img.img2);
	if (fr->win)
		mlx_destroy_window(fr->mlx, fr->win);
	fr->win = 0;
	mlx_destroy_display(fr->mlx);
	free(fr->mlx);
	return (0);
}
