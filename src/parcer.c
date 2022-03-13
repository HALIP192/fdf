/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:01:45 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/13 17:16:08 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



static int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
	{
		write(1, "Read file error.\n", 17);
		close(fd);
		exit(0);
	}
	width = ft_linecounter(line, ' ');
	close(fd);
	free(line);
	return (width);
}

void	write_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}
void	read_file(fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		write_matrix(data->z_matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
