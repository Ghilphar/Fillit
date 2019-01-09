/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:13:45 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/09 16:03:05 by fgaribot         ###   ########.fr       */
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

void						add_tail(t_trimino *tetrimino, t_trimino **lst);
void						create_tetrimino(char **candidate, t_trimino **lst);
int							ft_test_tetriminoes(char *piece, int i);
t_trimino					*tritreminoes(char *av);
void						ft_puterror(void);
void						test_candidate(char **candidate, t_trimino **lst);
int							ft_test_size(char **line, int i);
char						*ft_joincandidate(char **candidate, char **line);
//void						add_tetrimino(char *str, t_trimino **alst);
int							valid_size(int fd, t_trimino **alst, int i);
int							ft_neighbour(char *str);
//int						valid_tetrimino(t_trimino **lst);

#endif
