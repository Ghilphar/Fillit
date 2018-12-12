/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:13:45 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/12 16:37:53 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

typedef struct		s_trimino t_trimino;

struct				s_trimino
{
	char			*pattern;
	t_trimino		*next;
};

#endif
