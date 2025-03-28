/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:54 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/28 17:41:31 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx_int.h"
# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "struct.h"
# include "prototypes.h"
# include <sys/time.h>
# include <math.h>

# define WIN_WIDTH 1800
# define WIN_HEIGHT 900
# define ERROR_MAP "File not valid or doesn't exist\n"
# define ERROR_ARG "Usage: %s <fichier_map.fdf>\n", argv[0]

#endif
