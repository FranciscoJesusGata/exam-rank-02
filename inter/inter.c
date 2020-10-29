/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 10:23:34 by fgata-va          #+#    #+#             */
/*   Updated: 2020/10/29 09:55:29 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int ok[255];
	int i;
	int j;

	if (argc == 3 && argv[1] && argv[2])
	{
		i = 0;
		while(ok[i])
		{
			ok[i] = 0;
			i++;
		}
		i = 2;
		j = 0;
		while(i > 0)
		{
			if (!argv[i][j])
			{
				i--;
				j = -1;
			}
			else if (i == 2 && argv[i][j])
				ok[(int)argv[i][j]] = 1;
			if (i == 1 && argv[i][j] && ok[(int)argv[i][j]] == 1)
			{
				write(1, &argv[i][j], 1);
				ok[(int)argv[i][j]] = 0;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
