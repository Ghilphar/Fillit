/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:35:06 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/04 08:20:35 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_int_strcpycharstop(char **line, char *src, char c)
{
	int				i;
	char			*tmp;
	char			*tmp2;

	i = 0;
	tmp = NULL;
	i = ft_countchar(src, c);
	if (!(tmp = malloc(sizeof(tmp) * (i + 1))))
		return (0);
	tmp = ft_strcpycharstop(tmp, src, c);
	*line = tmp;
	if (src[i] == '\n')
		tmp2 = ft_strdup(src + (i + 1));
	else
		tmp2 = ft_strdup(src + (i));
	free(src);
	return (tmp2);
}

static t_list	*found_save(t_list **save, int fd)
{
	t_list			*tmp;

	tmp = *save;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(save, tmp);
	return (tmp);
}

static int		ft_read(int fd, void **str)
{
	char			buf[BUFF_SIZE + 1];
	int				read_size;
	void			*tmp;

	tmp = NULL;
	if (read(fd, buf, 0) < 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFF_SIZE)))
	{
		if (read_size == -1)
			return (-1);
		buf[read_size] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			return (-1);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_size < BUFF_SIZE && !ft_strlen(*str))
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*save = NULL;
	t_list			*current;
	int				ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	current = found_save(&save, fd);
	*line = NULL;
	ret = ft_read(fd, &(current->content));
	current->content = ft_int_strcpycharstop(&(*line), current->content, '\n');
	if (ret == -1 || ret == 0)
		return (ret);
	return (1);
}
