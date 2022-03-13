/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:50:25 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/12 19:34:49 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define RED		 0x00ff0000
#define GREEN	0x0000ff00
#define BLUE    0x000000ff
#define YELLOW	0x00ffff00
#define PURPLE	0x00ff00ff
#define CYAN	0x0000ffff
#define WHITE	0x00ffffff
#define BLACK	0x00000000
#define	MAX(a, b) (a <= b ? b : a)
#define	MOD(a) (a < 0 ? -a : a)

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8) + 150;
	*y = (*x + *y) * sin(0.8) - z + 150;
}

void	set_color(float z, float z1, fdf *data)
{
	if ((int)z > 0 || (int)z1 > 0)
		data->color = YELLOW;
	else if ((int)z < 0 || (int)z1 < 0)
		data->color = RED;
	else
		data->color = WHITE;
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	float	buff;
	float	z;
	float	z1;

	z = (float)data->z_matrix[(int)y][(int)x];
	z1 = (float)data->z_matrix[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	set_color(z, z1, data);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x_step = x1 - x;
	y_step = y1 - y;
	//isometric(&x, &y, z);
	//isometric(&x1, &y1, z1);
	buff = MAX(MOD(x_step), MOD(y_step));
	x_step /= (float)buff;
	y_step /= (float)buff;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
