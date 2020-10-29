/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:48:58 by fgata-va          #+#    #+#             */
/*   Updated: 2020/10/29 09:49:38 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}

char	*ft_add_char(char *s, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(ft_strlen(s) + 2);
	while(s[i] != '\0')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = c;
	i++;
	tmp[i] = '\0';
	free(s);
	return (tmp);
}

int		get_next_line(char **line)
{
	int r;
	char *buff = malloc(2);

	if (!line || !(*line = malloc(sizeof(char))))
		return (-1);
	buff[1] = '\0';
	while ((r = read(0, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			break ;
		*line = ft_add_char(*line, *buff);
	}
	free(buff);
	return (r);
}
