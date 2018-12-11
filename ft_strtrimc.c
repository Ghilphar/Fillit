/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:24:45 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/11 16:31:31 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrimc(char const *s, char c)
{
	char	*str;
	int		i;
	int		j;
	int		a;

	if (!s)
		return (NULL);
	a = 0;
	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[j])
		j++;
	j = j - 1;
	while (s[j] == c && j > i)
		j--;
	if (!(str = (char *)malloc(sizeof(*str) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		str[a++] = s[i++];
	str[a] = '\0';
	return (str);
}
