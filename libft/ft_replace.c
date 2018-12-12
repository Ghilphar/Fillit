/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:49:30 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/12 14:34:01 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *str, char find, char replace)
{
	if (!str)
		return (NULL);
	char	*current_pos;

	current_pos = ft_strchr(str, find);
	while (current_pos)
	{
		*current_pos = replace;
		current_pos = ft_strchr(current_pos + 1, find);
	}
	return (str);
}
