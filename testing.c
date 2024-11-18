/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:29:48 by lgirerd           #+#    #+#             */
/*   Updated: 2024/11/18 17:55:49 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	int fd = open(av[1], O_NONBLOCK | O_RDONLY);
	char *returned = get_next_line(fd);
	printf("%s", returned);
	free(returned);
	return (0);
}
