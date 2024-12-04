/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:58:28 by lgirerd           #+#    #+#             */
/*   Updated: 2024/12/04 15:08:06 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero_mod(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
}

static void	clean(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	j = 0;
	while (s[i + j])
	{
		s[j] = s[i + j];
		j++;
	}
	s[j] = '\0';
}
