/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:06:16 by lgirerd           #+#    #+#             */
/*   Updated: 2024/11/19 14:53:55 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytesread;

	if (fd == -1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	bytesread = read(fd, buffer, BUFFER_SIZE);
	buffer[bytesread - 1] = '\0';
	return(buffer);
}

void	ft_lstinit(t_list **lst, int fd)
{

}
