/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:06:16 by lgirerd           #+#    #+#             */
/*   Updated: 2024/11/19 15:13:23 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_list	*stack;
	char			*line;
	int				bytesread;

	stack = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0) // avance pas la tete de lecture mais check la lecture du fd
		return (NULL);
	bytesread = 1;
	line = NULL;
	// on lit
	read_to_stack(fd, &stack, &bytesread); 
	// on met line dans la stack
	// on clear et on free la stack
	return (line);
}

void	read_to_stack(int fd, t_list **stack, int *bytesread_ptr)
{
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return ;
	while (!newline(*stack) && *bytesread_ptr != 0)
	{
	*bytesread_ptr = (int)read(fd, buf, BUFFER_SIZE);
	buf[*bytesread_ptr] = '\0';
	}
}

int	newline()
