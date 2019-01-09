/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:53:05 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/09 16:02:42 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		add_tail(t_trimino *new, t_trimino **lst)
{
	t_trimino		*current;

	current = *lst;
	if (current->pattern == NULL)
	{
		*lst = new;
		free(current);
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->next = NULL;
}

void		create_tetrimino(char **candidate, t_trimino **lst)
{
	t_trimino		*new;

	if (!(new = malloc(sizeof(t_trimino))))
	{
		free(candidate);
		ft_free_tetri(lst);
		ft_puterror();
	}
	if (!(new->pattern = ft_strdup(*candidate)))
	{
		free(new);
		free(candidate);
		ft_free_tetri(lst);
		ft_puterror();
	}
	new->next = NULL;
	add_tail(new, lst);
}

int			ft_test_tetriminoes(char *piece, int i)
{
	char			*test[19];

	test[0] = "###...#";
	test[1] = "###..#";
	test[2] = "###.#";
	test[3] = "##.##";
	test[4] = "####";
	test[5] = "##..##";
	test[6] = "##...##";
	test[7] = "#...#..##";
	test[8] = "#..##...#";
	test[9] = "##...#...#";
	test[10] = "#...##...#";
	test[11] = "#...#...#...#";
	test[12] = "#..##..#";
	test[13] = "#...###";
	test[14] = "#..###";
	test[15] = "#.###";
	test[16] = "##..#...#";
	test[17] = "#...##..#";
	test[18] = "#...#...##";
	while (i < 19 && ft_strcmp(piece, test[i]) != 0)
		i++;
	return (i >= 19 ? 0 : 1);
}
