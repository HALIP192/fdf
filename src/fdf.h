/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:31:56 by ntitan            #+#    #+#             */
/*   Updated: 2022/03/14 00:08:02 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "../ftprintf/src/ft_printf.h"
# include "get_next_line.h"

typedef struct s_shit
{
	float	x;
	float	y;
}			t_shit;

typedef struct s_fdf
{
	float	x;
	float	y;
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		x_shift;
	int		y_shiift;
	int		color;
	void	*img_ptr;
	int		*image;
	int		line_length;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

int		ft_isspace(int c);
int		ft_mod(int a);
int		ft_max(int a, int b);
int		ft_atoi(const char *str);
int		ft_linecounter(char *str, char space);
char	**ft_split(char *s, char c);
void	read_file(t_fdf *data, char *file_name);
void	bresenham(t_shit *str, float x1, float y1, t_fdf *data);
void	draw(t_shit *str, t_fdf *data);
void	isometric(float *x, float *y, float z);
void	get_step(float *x_step, float *y_step, float buff);

#endif
