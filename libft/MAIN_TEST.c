/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:02:49 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/06 09:08:13 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>


int main(int ac, char **av)
{
	int fd;
	(void)av;
	char *line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(15, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	free(line);
	return (0);
}
