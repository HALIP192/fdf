/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:31:56 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/12 19:57:01 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

#include "../minilibx-linux/mlx.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdlib.h"
#include "../ft_printf/src/ft_printf.h"
#include "../get_next_line/get_next_line_bonus.h"

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	void	*img_ptr;
	int		*image;
	int		line_length;
	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

int		ft_atoi(const char *str);
int		ft_linecounter(char *str, char space);
char	**ft_split(char *s, char c);
void	read_file(fdf *data, char *file_name);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

#endif
