/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:06:16 by lgirerd           #+#    #+#             */
/*   Updated: 2024/11/26 13:25:11 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>

void	read_to_stack(int fd, t_list **stack, int *bytesread_ptr)
{
	char	*buf;

	while (!newline(*stack) && *bytesread_ptr != 0)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buf == NULL)
			return ;
		*bytesread_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stack == NULL && *bytesread_ptr == 0) || *bytesread_ptr == -1)
		{
			free(buf);
			return ;
		}
		buf[*bytesread_ptr] = '\0';
		lstadd_stack(stack, buf, *bytesread_ptr);
		free(buf);
	}
}

void	lstadd_stack(t_list **stack, char *buf_content, int bytesread)
{
	int		i;
	t_list	*last;
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return ;
	newnode->next = NULL;
	newnode->content = malloc(bytesread * sizeof(char));
	if (newnode->content == NULL)
		return ;
	i = 0;
	while (i < bytesread)
	{
		newnode->content[i] = buf_content[i];
		i++;
	}
	newnode->content[i] = '\0';
	if (*stack == NULL)
	{
		*stack = newnode;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = newnode;
}

void	extract_line(t_list *stack, char **line)
{
	int	i;
	int	j;

	if (stack == NULL)
		return ;
	generate_line_mem(line, stack);
	if (*line == NULL)
		return ;
	j = 0;
	while (stack)
	{
		i = 0;
		while (stack->content[i])
		{
			if (stack->content[i] == '\n')
			{
				(*line)[j++] = stack->content[i];
				break ;
			}
			(*line)[j++] = stack->content[i++];
		}
		stack = stack->next;
	}
	(*line)[j] = '\0';
}

void	clean_stack(t_list **stack)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	last = ft_lstlast(*stack);
	if (last == NULL || last->content == NULL)
		return ;
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	if (last->content[i] == '\0')
	{
		free_stack(*stack);
		*stack = NULL;
		return ;
	}
	clean_node = malloc(sizeof(t_list));
	if (clean_node == NULL)
		return ;
	clean_node->next = NULL;
	clean_node->content = malloc(
			(ft_strlen(last->content + i) + 1) * sizeof(char));
	if (clean_node->content == NULL)
	{
		free(clean_node);
		return ;
	}
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stack(*stack);
	*stack = clean_node;
}

char	*get_next_line(int fd)
{
	static t_list	*stack;
	char			*line;
	int				bytesread;

	// stack = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	bytesread = 1;
	line = NULL;
	read_to_stack(fd, &stack, &bytesread);
	if (stack == NULL)
		return (NULL);
	extract_line(stack, &line);
	clean_stack(&stack);
	return (line);
}
