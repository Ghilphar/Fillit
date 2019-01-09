/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:24:04 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/09 11:27:55 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_puterror(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

t_trimino	*tritreminoes(char *av)
{
	int			fd;
	t_trimino	*lst;

	if (!(lst = malloc(sizeof(t_trimino))))
		return (NULL);
	lst->next = NULL;
	lst->pattern = NULL;
	fd = open(av, O_RDONLY);
	if (!(valid_size(fd, &lst, -1)))
	{
		ft_free_tetri(&lst);
		ft_puterror();
	}
	return (lst);
}
