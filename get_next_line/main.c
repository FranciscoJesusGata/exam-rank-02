/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:49:32 by fgata-va          #+#    #+#             */
/*   Updated: 2020/09/10 18:54:43 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	char 	*line;
	int	gnl;

	line = NULL;
	while((gnl = get_next_line(&line)) == 1)
	{
		printf("%s", line);
	}
	printf("%s", line);
	free(line);
	return (0);
}
