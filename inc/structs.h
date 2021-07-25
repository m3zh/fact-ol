/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:26:17 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/06 18:40:00 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	void		*img;
	int			*addr;
	void		*img2;
	int			*addr2;	
	int			counter;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_moves
{
	int			forw;
	int			back;
	int			left;
	int			right;
	int			rotleft;
	int			rotright;
}				t_moves;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	int			winW;
	int			winH;
	int			set;
	t_data		img;
	t_moves		move;
}				t_fractal;

#	endif
