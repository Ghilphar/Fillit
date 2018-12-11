/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:32:54 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/11 16:33:26 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "valid.h"
#include <fcntl.h>

char	*ft_test_tetriminoes(char *piece, int nb)
{
	char	*test[19];
	int		i;

	i = 1;
	*test[1] = "###...#";
	*test[2] = "###..#";
	*test[3] = "###.#";
	*test[4] = "##.##";
	*test[5] = "####";
	*test[6] = "##..##";
	*test[7] = "##...##";
	*test[8] = "#...#..##";
	*test[9] = "#..##...#";
	*test[10] = "##...#...#";
	*test[11] = "#...##...#";
	*test[12] = "#...#...#...#";
	*test[13] = "#..##..#";
	*test[14] = "#...###";
	*test[15] = "#..###";
	*test[16] = "#.###";
	*test[17] = "##..#...#";
	*test[18] = "#...##..#";
	*test[19] = "#...#...##";
	while (ft_strcmp(piece, test[i]) != 0)
		i++;
	return (i > 19 ? "NONE" : *test[i])
}


int		valid_size(int fd, t_tetriminoes **alst)
{
	int		i;
	int		j;
	char		*line;
	char		*candidate_tetrimino;
	char		*tmp;

	i = -1;
	while (get_next_line(fd, &line) == 1 && ++i < 5)
	{
		j = ft_countchar(line, '\n');
		if ((i < 4 && j != 4) || (i == 4 && j != 0))
			exit(EXIT_FAILURE);
		if (i < 4)
		{
			tmp = ft_strjoin(candidate_tetrimino, line);
			free(candidate_tetrimino);
			candidate_tetrimino = tmp;
		}
		if (i == 5)
			i = add_tetrimino(candidate_tetrimino, &alst);
	}
	free(line);
	return (1);
}

int		add_tetrimino(char	*str, t_tetriminoes **alst)
{
	t_tetriminoes		*new;
	char			*tmp;
	t_tetriminoes		*first;

	first = *alst;
	new->next = NULL;
	tmp = ft_strdup(str);
	new->tetrimino = tmp;
	while ((*alst)->next != NULL)
		(*alst) = (*alst)->next;
	(*alst)->next = new;
	ft_strdel(str);
	*alst = first;
	return (-1);
}

int		valid_tetrimino(t_tetriminoes **alst)
{
	int				i;
	int				j;

	while (tmp != NULL)
	{
		i = 0;
		while ((*alst->tetrimino)[i] == '.' || *alst->tetrimino[i] == '#')
		{
			if ((*alst->tetrimino)[i] == '#')
			{
				j = (i >= 4 && (alst->tetrimino)[i - 4] == '#') ? j + 1 : j;
				j = (i > 0 && (alst->tetrimino)[i - 1] == '#') ? j + 1 : j;
				j = ((alst->tetrimino)[i + 1] == '#') ? j + 1 : j;
				j = (i < 12 && (*alst->tetrimino)[i + 1] == '#') ? j + 1 : j;
			}
			i++;
		}
		if (i != 16 || (j != 6 && j != 8))
			return (-1);
		alst->tetrimino = ft_strtrimc(alst->tetrimino, '.');
		*alst = alst->next;
	}
	return (1);
}
