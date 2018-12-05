/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:47:56 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/04 08:25:54 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 256
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(const int fd, char **line);

#endif
