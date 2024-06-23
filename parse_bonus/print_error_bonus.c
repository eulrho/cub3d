/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sewopark <sewopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:26:50 by erho              #+#    #+#             */
/*   Updated: 2024/06/23 14:59:51 by sewopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	print_error(int error_no)
{
	ft_putstr_fd("Error\n", 2);
	if (error_no == ERROR_FILE_NAME)
		ft_putstr_fd("invalid file name\n", 2);
	else if (error_no == ERROR_STANDARD_INPUT)
		ft_putstr_fd("invalid input\n", 2);
	else if (error_no == ERROR_INVALID_FILE)
		ft_putstr_fd("file is empty or not found\n", 2);
	else if (error_no == ERROR_INVALID_MAP)
		ft_putstr_fd("invalid configuration on map\n", 2);
	else if (error_no == ERROR_INVALID_INFO)
		ft_putstr_fd("invalid information\n", 2);
	else if (error_no == ERROR_MAP_SIZE)
		ft_putstr_fd("map is not rectangle\n", 2);
	exit(1);
}
