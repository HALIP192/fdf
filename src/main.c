/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:50:50 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/13 17:26:07 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_cleaner(fdf *data)
{
	int i;
	int j;

	i = 0;
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data->mlx_ptr);
	free(data->win_ptr);
}

int	mouse_act(int mouse, fdf *data)
{
	int	x;
	int	y;

	ft_printf("mouse: %d\n", mouse);
	//mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x, &y);
	//ft_printf("mouse_pos: %d %d\n", x, y);
	return (0);
}

int	key_act(int key, fdf *data)
{
	ft_printf("key: %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
		//data_cleaner(data);
	}
	return (0);	
}

int		ft_close_window(fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	fdf	*data;
	int	shit;

	data = (fdf *)malloc(sizeof(fdf));
	read_file(data, argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->image = (int *)mlx_get_data_addr(data->img_ptr, &shit, &data->line_length, &shit);
	data->zoom = 20;	
	//bresenham(10, 10, 600, 300, data);
	draw(data);
	mlx_key_hook(data->win_ptr, key_act, data);
	//mlx_expose_hook(data->win_ptr, mouse_act, data);
	mlx_hook(data->win_ptr, 33, 0, ft_close_window, data);
	mlx_loop(data->mlx_ptr);
	//data_cleaner(data);
	return (0);	
}

