/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:07:02 by ehafidi           #+#    #+#             */
/*   Updated: 2021/07/21 19:47:20 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_check_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_readline(char *line, int fd)
{
	char	*buf;
	int		ret;

	ret = 1;
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ft_check_nl(line) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
		{
			free(buf);
			return (NULL);
		}
		if (ft_check_nl(line) >= 0)
			break ;
	}
	if (ret < 0)
		return (NULL);
	free(buf);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char rest[OPEN_MAX][BUFFER_SIZE + 1];
	int			nl;

	if (fd < 0 || line == 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	*line = ft_strdup(rest[fd]);
	if (!*line)
		return (-1);
	*line = ft_readline(*line, fd);
	if (!*line)
		return (-1);
	if ((nl = ft_check_nl(*line)) >= 0 || (ft_check_nl(rest[fd])) >= 0)
	{
		ft_strcpy(rest[fd], *line + nl + 1);
		*line = ft_substr(*line, 0, nl);
		if (!*line)
			return (-1);
		return (1);
	}
	rest[fd][0] = '\0';
	return (0);
}
