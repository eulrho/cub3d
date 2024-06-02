/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:18:31 by sewopark          #+#    #+#             */
/*   Updated: 2024/06/02 21:36:55 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define IMAGE_SIZE 64

// mask code
# define KEY_PRESS_MASK 1

// mac key codes
# define LEFT_CLICK 1
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define ESC 53
# define KEY_PRESS 2
# define EXIT_BUTTON 17

# define TRUE 1
# define FALSE 0

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

typedef enum e_error_type
{
	VALID,
	ERROR_OTHER_CHARACTERS,
	ERROR_FILE_NAME,
	ERROR_STANDARD_INPUT,
	ERROR_INVALID_FILE,
	ERROR_INVALID_MAP,
	ERROR_INVALID_INFO,
	ERROR_MAP_SIZE
}	t_error_type;

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_image {
	char	*path;
	void	*image;
	int		width;
	int		height;
}	t_image;

typedef struct s_map
{
	char	**field;
	int		start_y;
	int		start_x;
	int		direction;
	int		ceiling[3];
	int		floor[3];
	size_t	y_size;
	size_t	x_size;
}	t_map;

typedef struct s_play {
	void	*mlx;
	void	*win;
	char	**origin;
	t_image	images[4];
	int		check_parsing;
	size_t	height;
	t_map	map;
}	t_play;

typedef struct s_node {
	size_t			y;
	size_t			x;
	struct s_node	*next;
}	t_node;

typedef struct s_queue {
	t_node	*front;
	t_node	*back;
}	t_queue;

/* parse */
// length
size_t	ft_exp_len(char **str);

// check_file
void	is_valid_file(char *file, int fd);

// check_info
void	is_valid_info(t_play *p);

// check_map
void	is_valid_map(t_map *m);

// bfs
void	bfs(t_map *m, size_t start_y, size_t start_x, int **visited);

// set_play
void	initial_play(t_play *play);

// extract_data
void	extract_path(t_play *p, size_t idx, size_t *width, int image_type);
void	extract_color(t_play *p, int *arr, size_t idx, size_t *width);

// print_error
void	print_error(int error_no);

// queue
void	q_pop(t_queue *q);
void	q_push(t_queue *q, t_node *node);
t_list	*make_node(size_t y, size_t x);
t_queue	*make_queue(void);

// free
void	free_exp(int **exp);

#endif