/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:57:53 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/19 17:26:19 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
void		add_tetrimino(char *candidate, t_trimino **alst)
{
	t_trimino	*new;
	t_trimino	*first;

	first = *alst;
	if (!(new = malloc(sizeof(t_trimino))))
	{
		
	}
}
*/

int			ft_neigbour(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] == '.' || str[i] == '#')
	{
		if (str[i] == '#')
		{
			j = (i > = 4 && str[i - 4] == '#') ? j + 1 : j;
			j = (i > 0 && str[i - 1] == '#') ? j + 1 : j;
			j = (i != 3 && i != 7 && i != 11 && i != 15 &&
					str[i + 1] == '#') j + 1 : j;
			j = (i < 12 && str[i + 4] == '#') ? j + 1 : j;
		}
		i++;
	}
	return (i != 16 || (j != 6 && j != 8) ? 0 : 1);
}

void		test_candidate(char **candidate, t_trimino **lst)
{
	if (!(ft_neigbour(*candidate)))
	{
		free(candidate);
		ft_free_tetri(&lst);
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}

void		ft_puterror(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int			ft_test_size(char **line, int i)
{
	int			j;

	j = ft_countchar(*line, '\n');
	return (((i < 4 && j != 4) || (i == 4 && j != 0)) ? 0 : 1);
}

char		*ft_joincandidate(char **candidate, char **line)
{
	char		*newcandidate;

	if (!(newcandidate = ft_strjoin(*candidate, *line)))
	{
		free(line);
		free(candidate);
		return (NULL);
	}
	free(candidate);
	free(line);
	return (newcandidate);
}


int			valid_size(int fd, t_trimino **alst, int i)
{
	char		*candidate;
	char		*line;

	while (get_next_line(fd, &line) == 1 && ++i < 5)
	{
		if (!(candidate = (i == 0 ? ft_strdup(line) : candidate)))
		{
			free(line);
			return (0);
		}
		if (!(ft_test_size(&line, i)))
		{
			free(candidate);
			free(line);
			return (0);
		}
		if (i != 0 && i < 4)
			if (!(candidate = ft_joincandidate(&candidate, &line)))
				return(0);
		if (i == 3)
		{
			add_tetrimino(candidate, alst);
			free(candidate);
		}
		if (i == 4)
			i = -1;
	}
	return (i == 3 ? 1 : 0);
}

int			main(int ac, char **av)
{
	(void)ac;
	int			fd;
	t_trimino	*lst;

	if (!(lst = malloc(sizeof(t_trimino))))
		return (0);
	lst->next = NULL;
	lst->pattern = NULL;
	fd = open(av[1], O_RDONLY);
	if (!(valid_size(fd, &lst, -1)))
	{
		ft_free_tetri(&lst);
		ft_puterror();
	}
	ft_putendl("valid work");
	return (0);
}
