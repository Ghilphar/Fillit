/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:32:54 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/06 16:11:24 by fgaribot         ###   ########.fr       */
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
	*test[7] = "##...###";
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


int		valid_file(int fd)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (get_next_line(fd, &line) == 1 && ++i < 5)
	{
		j = ft_countchar(line, '\n');
		if (j != 4 || j != 0 || (j == 0 && i != 5) || (i < 5 && j != 4) || i = 5 && j != 0)
			return (-1);

	}
}


int		valid_file(int fd)
{
	int		i;
	int		j;
	char	*line;
	char	candidate_tetrimino[17];

	i = 0;
	while (get_next_line(fd, &line) == 1 && i++ < 5)
	{
		j = 0;
		while (i != 5 && line[j] && j < 5)
			j++;
		if ((i == 5 && line[0] != '\0') || j != 4)
			return (-1);
		if (i < 5 && j == 4)
			ft_strjoin(candidate_tetrimino, line);
		if (i == 5 && )
//		ft_add(candidate_tetrimino);
		i = ((i == 5 && line[0] == '\0') ? 0 : i);
		ft_strdel(line);
		if (i == 5)
			return (-1);
	}
	return (1);
}

int		valid_file;
{
	char	*line;
	int		i;
	int		j;
	int 	fd;
	char	candidate_tetrimino[26][16];
	
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		while (j++ < 5)
		{
			
		}
}
