/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:58:39 by mbabayan          #+#    #+#             */
/*   Updated: 2023/12/18 14:13:37 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *rl(char *str, int fd) {
	int		index_chars;
	char 	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	index_chars = 1;
	while (!ft_strchr(str, '\n') && index_chars != 0)
	{
		index_chars = read(fd, buff, BUFFER_SIZE);
		if (index_chars == -1)
		{
			free(buff);
			return (0);
		}
		buff[index_chars] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char *get_next_line(int fd)
{
	static char *str;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = rl(str, fd);
	if (!str)
		return (0);



}