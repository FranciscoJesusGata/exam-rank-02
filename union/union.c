/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:03:34 by fgata-va          #+#    #+#             */
/*   Updated: 2020/10/29 09:55:46 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int ok[128];
	int i;
	int j;
	int k;

	if (argc == 3)
	{
		i = 0;
		while (ok[i])
		{
			ok[i] = 0;
			i++;
		}
		i = 1;
		j = 0;
		k = 1;
		while (k < 3)
		{
			if (i >= 3)
			{
				i = 1;
				j = -1;
				k++;
			}
			else if (!argv[i][j])
			{
				i++;
				j = -1;
			}
			else if (k == 1 && argv[i][j])
				ok[(int)argv[i][j]] = 1;
			else if (k == 2 && argv[i][j] && ok[(int)argv[i][j]] == 1)
			{
				ok[(int)argv[i][j]] = 0;
				write(1, &argv[i][j], 1);
			}
			j++;
		}

	}
	write(1,"\n",1);
	return(0);
}
