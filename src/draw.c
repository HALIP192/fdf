/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:50:25 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/14 00:08:53 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "stdio.h"

#define RED		 0x00ff0000
#define GREEN	0x0000ff00
#define BLUE    0x000000ff
#define YELLOW	0x00ffff00
#define PURPLE	0x00ff00ff
#define CYAN	0x0000ffff
#define WHITE	0x00ffffff
#define BLACK	0x00000000

void	set_color(float z, float z1, t_fdf *data)
{
	if ((int)z > 0 || (int)z1 > 0)
		data->color = YELLOW;
	else if ((int)z < 0 || (int)z1 < 0)
		data->color = RED;
	else
		data->color = WHITE;
}

static void	zoom(t_shit *str, float *x1, float *y1, int zoom)
{
	str->x *= zoom;
	str->y *= zoom;
	*x1 *= zoom;
	*y1 *= zoom;
}

void	put_pixel(const t_fdf *restrict data, int x, int y)
{
	data->image[y * (data->line_length / 4) + x] = data->color;
}

void	bresenham(t_shit *str, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	buff;
	float	z;
	float	z1;

	z = (float)data->z_matrix[(int)(str->y)][(int)(str->x)];
	z1 = (float)data->z_matrix[(int)y1][(int)x1];
	zoom(str, &x1, &y1, data->zoom);
	set_color(z, z1, data);
	isometric(&(str->x), &(str->y), z);
	isometric(&x1, &y1, z1);
	x_step = x1 - str->x;
	y_step = y1 - str->y;
	buff = ft_max(ft_mod(x_step), ft_mod(y_step));
	get_step(&x_step, &y_step, buff);
	while ((int)((str->x) - x1) || (int)((str->y) - y1))
	{
		put_pixel(data, str->x, str->y);
		str->x += x_step;
		str->y += y_step;
	}
}

void	draw(t_shit *str, t_fdf *data)
{
	float	x;
	float	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			str->x = x;
			str->y = y;
			if (x < data->width - 1)
				bresenham(str, str->x + 1, str->y, data);
			str->x = x;
			str->y = y;
			if (y < data->height - 1)
				bresenham(str, str->x, str->y + 1, data);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
