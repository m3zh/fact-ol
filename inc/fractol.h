/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:54:06 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/11 07:32:42 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "structs.h"
# include "../mlx/mlx.h"

# ifndef BNS
#  define BNS 0
# endif

# define PI 3.14159265359
# define PLAYER 3
# define OFFSET 0
# define STEP 5
# define SPEED 0.05
# define ROT 0.05
# define FOV 1
# define SCREENW 1000
# define SCREENH 800
# define TILE 5
# define RAY 20
# define FILESIZE 1000

# define BLACK -16777216
# define GRAY 0xC0C0C0
# define PURPLE 0x7d0330
# define RED 0xFF0000
# define GREEN 0x037d50
# define YELLOW 0xFFFF00

# define UP_KEY 65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define Q_KEY 12
# define ESC_KEY 65307

/*
* FRACTAL EXPLORER
*/

int		init_fractal(t_fractal *fr, char *set);
int		get_colors(int i);
void    fractals_magic(char *set);
void	draw_pixel(t_fractal *fr, int y, int x, int color);
// void	rotate_view(t_fractal *fr, double dx, double px);
void	move_backforwards(t_fractal *fr);
void	move_leftright(t_fractal *fr);
void	draw_fractal(t_fractal *fr);
void	get_orientation(t_fractal *fr);

/*
* UTILS
*/

int		x_exit(t_fractal *fr);
int		key_press(int keycode, t_fractal *fr);
int		key_release(int keycode, t_fractal *fr);
int		free_window(t_fractal *fr);
void	free_fractal(t_fractal *fr);
int		free_dataimg(t_fractal *fr);

#endif
