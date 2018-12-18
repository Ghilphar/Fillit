/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:13:45 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/14 19:31:06 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

typedef struct s_trimino	t_trimino;

struct						s_trimino
{
	char					*pattern;
	t_trimino				*next;
};

t_trimino					*tritreminoes(char *av);
void						ft_puterror(void);
void						add_tetrimino(char *str, t_trimino **alst);
int							ft_test_tetriminoes(char *piece, int i);
int							valid_size(int fd, t_trimino **alst, int i);
int							ft_neighbour(char *str);
int							valid_tetrimino(t_trimino **lst);

#endif
