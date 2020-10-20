/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:50:36 by fgata-va          #+#    #+#             */
/*   Updated: 2020/10/20 12:07:06 by fgata-va         ###   ########.fr       */
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
	char buff[2];

	if (!line || !(*line = malloc(sizeof(char))))
		return (-1);
	buff[1] = '\0';
	while ((r = read(0, buff, 1)) == 1)
	{
		if (buff[0] == '\n' || buff[0] == '\0')
			break ;
		*line = ft_add_char(*line, buff[0]);
	}
	return (r);
}
