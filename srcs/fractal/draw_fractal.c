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

static void mandelbrot_set(t_fractal *fr)
{
    double pr, pi;      
    double new_cr, new_im, old_cr, old_im;   
    double zoom = 1, posx = 0, posy = 0; 
    int max = 30;
    int color; 
    int i;
    int y = 0;
    int x = 0;
   

    
    while (++y < fr->winH)
    {
        x = 0;
        while (++x < fr->winW)
        {
            pr = 1.5 * (x - fr->winW / 2) / (0.5 * zoom * fr->winW) + posx;
            pi = (y - fr->winH / 2) / (0.5 * zoom * fr->winH) + posy;
            new_cr = new_im = old_cr = old_im = 0;             
            
            i = -1;

            while (++i < max)
            {
            
                old_cr = new_cr;
                old_im = new_im;
                
                new_cr = (double)(old_cr * old_cr - old_im * old_im + pr);
                new_im = (double)(2 * old_cr * old_im + pi);
                
                
                if ((new_cr * new_cr + new_im * new_im) > 4) break;
            }
            if (i < max)
            {
                color = get_colors(i);
                draw_pixel(fr, y, x, color);
            }
        }
    }
}

static void julia_set(t_fractal *fr)
{
double cr, im;           
    double new_cr, new_im, old_cr, old_im;   
    double zoom = 1, posx = 0, posy = 0; 
    int max = 230;
    int color; 
    int i;
    int y = 0;
    int x = 0;
   
    cr = -0.7;
    im = 0.27015;
    
    while (++y < fr->winH)
    {
        x = 0;
        while (++x < fr->winW)
        {
            
            new_cr = (double)(1.5 * (x - fr->winW / 2) / (0.5 * zoom * fr->winW) + posx);
            new_im = (double)((y - fr->winH / 2) / (0.5 * zoom * fr->winH) + posy);
            
            i = -1;

            while (++i < max)
            {
                old_cr = new_cr;
                old_im = new_im;
                
                new_cr = (double)(old_cr * old_cr - old_im * old_im + cr);
                new_im = (double)(2 * old_cr * old_im + im);
                if ((new_cr * new_cr + new_im * new_im) > 4) break;
            }
            if (i < max)
            {
                color = get_colors(i);
                draw_pixel(fr, y, x, color);
            }         
        }
    }
}

void	draw_fractal(t_fractal *fr)
{
    if (!fr->set)
        julia_set(fr);
    else
        mandelbrot_set(fr);
    mlx_put_image_to_window(fr->mlx, fr->win, fr->img.img, 0, 0);
}