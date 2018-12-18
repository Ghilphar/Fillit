/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:33:50 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/14 19:22:53 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int a;

	a = 0;
	while ((a <= nb / 2) && (a < 46341))
	{
		if (a * a >= nb)
			return (a);
		a++;
	}
	return (0);
}

int		ft_link_count(t_trimino *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char	**ft_map_maker(int map_size)
{
	char		**map;
	int			i;
	int			x;
	int			y;

	x = -1;
	i = -1;
	if (!(map = (char **)malloc(sizeof(*map) * (map_size + 1))))
		return (NULL);
	while (++i < map_size)
	{
		if (!(map[i] = (char*)malloc(sizeof(**map) * (map_size + 1))))
			return (NULL);
	}
	while (++x < map_size)
	{
		y = -1;
		while (++y < map_size)
			map[x][y] = '.';
		map[x][y] = '\0';
	}
	map[x] = 0;
	return (map);
}

void	ft_print_map(char **map, int map_size)
{
	int i;
	int j;

	j = 0;
	while (j < map_size)
	{
		i = 0;
		while (i < map_size)
		{
			ft_putchar(map[i][j]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return ;
}

int		main(int ac, char **av)
{
	int			map_size;
	t_trimino	*piece;
	char		**map;
	int			count;

	if (ac == 2)
	{
		piece = tritreminoes(av[1]);
		if ((count = ft_link_count(piece)) > 26)
			ft_puterror();
		map_size = ft_sqrt(count * 4);
		map = ft_map_maker(map_size);
		while (backtrack(map_size, map, piece) == 0)
		{
			ft_free_map(&map);
			map_size++;
			map = ft_map_maker(map_size);
		}
		ft_free_map(&map);
		ft_free_tetri(&piece);
	}
	else
		ft_putendl("usage: ./fillit target_file");
	return (0);
}
