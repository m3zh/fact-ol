/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:13:37 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/25 21:24:53 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	if (ac == 2 && (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "mandelbrot")))
		fractals_magic(av[1]);
	else
	{
		printf("%s\nEnter \"julia\" or \"mandelbrot\" to start the program\n", strerror(EINVAL));
		printf("You can enter an additional integer params (optional)\nExample: ./fractol julia 56\n");
	}
	return (0);
}
