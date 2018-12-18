/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:57:53 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/18 19:52:41 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

void		ft_add_tetrimino(char **str, )

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
