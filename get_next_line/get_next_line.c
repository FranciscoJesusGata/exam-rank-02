/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:53:45 by fgata-va          #+#    #+#             */
/*   Updated: 2020/09/14 13:01:18 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == c)
			return(str[i]);
	}
	if (!str[i] && !c)
		return(str[i]);
	return(NULL);
}

char		*ft_strdup(const char *s)
{
	int	i;
	char	*dup;

	if (!(dup = malloc(ft_strlen(s) + 1)))
		return(NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if (!s)
		return(NULL);
	if (start >= ft_strlen(s))
		return(ft_strdup(""));
	i = start
	j = 0;
	while (j < len && s[i])
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return(substr);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1 || !s2)
		return(ft_strdup(""));
	if(!(joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return(NULL);
	i = 0;
	while(s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return(joined);
}

int		get_next_line(char **line)
{
	int	r;
	char	readed[BUFFER_SIZE + 1];
	static char	*saved;

	while ((r = read(0, readed, BUFFER_SIZE) > 0))
	{

	}

}
