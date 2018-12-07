/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:13:45 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/06 15:37:48 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

typedef struct		s_list t_tetriminoes;

struct				s_list
{
	char			*tetriminoes;
	int				height;
	int				width;
	t_tetriminoes	*next;
};

#endif
