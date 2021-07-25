/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   crated: 2021/07/25 12:27:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/07/25 12:54:39 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	draw_fractal(t_fractal *fr)
{
    double cr, im;           //real and imaginary part of the constant c, determinate shape of the Julia Set
    double new_cr, new_im, old_cr, old_im;   //real and imaginary parts of new and old
    double zoom = 1, x = -1, y = -1; //you can change these to zoom and change position
    int max = 300;
    int color; //after how much iterations the function should stop
    int i;

    //pick some values for the constant c, this determines the shape of the Julia Set
    cr = -0.7;
    im = 0.27015;

    //loop through every pixel
    while (++y < fr->winH)
    {
        while (++x < fr->winW)
        {
            //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
            new_cr = 1.5 * (x - fr->winW / 2) / (0.5 * zoom * fr->winW) + x;
            new_im = (y - fr->winH / 2) / (0.5 * zoom * fr->winH) + y;
            //i will represent the number of iterations
            i = -1;
            //start the iteration process
            while (++i < max)
            {
            //remember value of previous iteration
                old_cr = new_cr;
                old_im = new_im;
                //the actual iteration, the real and imaginary part are calculated
                new_cr = old_cr * old_cr - old_im * old_im + cr;
                new_im = 2 * old_cr * old_im + im;
                //if the point is outside the circle with radius 2: stop
                if ((new_cr * new_cr + new_im * new_im) > 4) break;
                color = get_colors(i);
                printf("%i\n", i);
                //draw the pixel
                draw_pixel(fr, y, x, color);
            }
            //use color model conversion to get rainbow palette, make brightness black if max reached
            draw_pixel(fr, y, x, color);
        }
    }
    mlx_put_image_to_window(fr->mlx, fr->win, fr->img.img, 0, 0);
}