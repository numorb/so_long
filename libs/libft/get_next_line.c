/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:34:31 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 19:55:01 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_one_line(char *line)
{
	char	*line_chop;
	size_t	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	line_chop = (char *)malloc((len + 1) * sizeof(char));
	if (!line_chop)
		return (NULL);
	ft_memcpy(line_chop, line, len);
	line_chop[len] = '\0';
	return (line_chop);
}

int	append_line(char **line, char *buffer)
{
	char	*temp;

	temp = NULL;
	if (*line)
	{
		temp = ft_strjoin(*line, buffer);
		if (!temp)
		{
			free(*line);
			return (1);
		}
		free(*line);
		*line = temp;
	}
	else
	{
		*line = ft_strdup(buffer);
		if (!*line)
			return (1);
	}
	return (0);
}

int	read_line(char *buffer, int fd, char **old_line)
{
	char	*line;
	ssize_t	bytes_read;
	int		found_newline;

	line = NULL;
	found_newline = 0;
	while (!found_newline)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			return (1);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (append_line(&line, buffer))
			return (1);
		if (ft_strchr(buffer, '\n'))
			found_newline = 1;
	}
	*old_line = line;
	return (0);
}

char	*handle_lines(char *line, char *old_line, char *remainder)
{
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (!line)
		return (old_line);
	if (old_line)
	{
		temp2 = get_one_line(line);
		temp = ft_strjoin(old_line, temp2);
		free(temp2);
		free(old_line);
	}
	else
		temp = get_one_line(line);
	free(line);
	rest_of_line(remainder);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*line;
	char		*old_line;

	line = NULL;
	old_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder[0] != '\0')
	{
		old_line = get_one_line(remainder);
		rest_of_line(remainder);
	}
	if (old_line && ft_strchr(old_line, '\n'))
		return (old_line);
	if (read_line(remainder, fd, &line))
	{
		free(old_line);
		return (NULL);
	}
	return (handle_lines(line, old_line, remainder));
}
