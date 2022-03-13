/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:50:50 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/14 00:16:48 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_cleaner(t_fdf *data)
{
	int	i;

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

int	key_act(int key, t_fdf *data)
{
	ft_printf("key: %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int	ft_close_window(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

int	malloc_error(t_shit *mdata, t_fdf *data)
{
	data_cleaner(data);
	free(mdata);
	return (write(1, "Malloc error\n", 13));
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		shit;
	t_shit	*mdata;

	if (argc < 2 || argc > 2)
		return (write(1, "File name error\n", 16));
	data = (t_fdf *)malloc(sizeof(t_fdf));
	mdata = (t_shit *)malloc(sizeof(t_shit));
	if (!data | !mdata)
		return (malloc_error(mdata, data));
	read_file(data, argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->img_ptr = mlx_new_image(data->mlx_ptr,
			2 * ft_max(data->height, data->width) * data->zoom + 150,
			2 * ft_max(data->height, data->width) * data->zoom + 150);
	data->image = (int *)mlx_get_data_addr(data->img_ptr, &shit,
			&data->line_length, &shit);
	draw(mdata, data);
	free(mdata);
	mlx_key_hook(data->win_ptr, key_act, data);
	mlx_hook(data->win_ptr, 33, 0, ft_close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
