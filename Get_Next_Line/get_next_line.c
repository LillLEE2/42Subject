/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junholee <junholee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:10:50 by junholee          #+#    #+#             */
/*   Updated: 2021/06/01 00:19:34 by junholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if ((!s1 && !s2 ) || !(ret = (char*)malloc(sizeof(char) * (len1 
		+ len2 + 1))))
		return (NULL);
	while (i < len1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (j < len2)
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}

char		*add_after_newline(char *save)
{
	char	*tmp; 
	char	*line;
	size_t	size;

	if (!save)
		return (NULL);
	line = NULL;
	tmp = NULL;
	if ((tmp = ft_strchr(save, '\n')))
	{
		size = ft_strlen(tmp);
		if (!(line = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_strlcpy(line, (tmp + 1), (size + 1));
	}
	free(save);
	return (!line) ? NULL : line;
}

char		*add_before_newline(char *save)
{
	char	*line;
	char	*tmp;
	size_t	s_size;
	size_t	t_size;

	if (!save)
		return (NULL);
	tmp = ft_strchr(save, '\n');
	s_size = ft_strlen(save);
	t_size = ft_strlen(tmp);
	if (!(line = (char *)malloc(sizeof(char) * (s_size - t_size) + 1)))
		return (NULL);
	ft_strlcpy(line, save, (s_size - t_size) + 1);
	return (line);
}

int					get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*save;
	int				rd;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((!ft_strchr(save, '\n')) &&
		(rd = read(fd, buf, BUFFER_SIZE)))
	{
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		save = ft_strjoin(save, buf);
	}
	if (!rd && !save)
		*line = ft_strdup("");
	else
		*line = add_before_newline(save);
	save = add_after_newline(save);
	return (rd || save) ? 1 : 0;
}
