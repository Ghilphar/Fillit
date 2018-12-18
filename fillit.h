/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:50:52 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/14 19:12:12 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "valid.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_coord
{
	int x_ref;
	int y_ref;
	int x;
	int y;
}				t_coord;

void			ft_free_map(char ***map);
int				backtrack(int map_size, char **map, t_trimino *piece);
void			ft_print_map(char **map, int map_size);
int				is_placable(char **map, int map_size, char *pattern,
		t_coord pos);
void			place_piece(char ***map, char *pattern, t_coord pos);
void			remove_piece(char ***map, char *pattern, t_coord pos);
void			ft_free_tetri(t_trimino **lst);

#endif
