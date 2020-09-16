/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:53:45 by fgata-va          #+#    #+#             */
/*   Updated: 2020/09/16 10:22:26 by fgata-va         ###   ########.fr       */
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

char		*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == c)
			return(&s[i]);
	}
	if (!s[i] && !c)
		return(&s[i]);
	return(NULL);
}

char		*ft_strdup(const char *s)
{
	int	i;
	char	*dup;

	if (!(dup = malloc(ft_strlen((char *)s) + 1)))
		return(NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if (!s)
		return(NULL);
	if (start >= ft_strlen(s))
		return(ft_strdup(""));
	if(!(substr = malloc(len + 1)))
		return(NULL);
	i = start;
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

char		*ft_strjoin(char *s1,char *s2)
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
	j = 0;
	while(s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return(joined);
}

char		*get_line(char *saved, char **line, int r)
{
	char	*tmp;
	int	i;
	int	len;

	if (r == 0 && !saved)
	{
		*line = ft_strdup("");
		return (NULL);
	}
	else if (r == 0)
	{
		*line = saved;
		return(NULL);
	}
	len = ft_strlen(saved);
	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	*line = ft_substr(saved, 0, i);
	tmp = ft_substr(saved, i, len);
	free(saved);
	saved = tmp;
	tmp = NULL;
	return(saved);
}

int		get_next_line(char **line)
{
	int	r;
	char	readed[BUFFER_SIZE + 1];
	static char	*saved;

	r = 0;
	while ((r = read(0, readed, BUFFER_SIZE)) > 0)
	{
		readed[r] = '\0';
		if (!saved)
			saved = ft_strdup(readed);
		else
			saved = ft_strjoin(saved, readed);
		if (ft_strchr(readed, '\n') || r < BUFFER_SIZE)
			break ;
	}
	if (r < 0)
		return (-1);
	saved = get_line(saved, line, r);
	if (r == 0 && !saved)
		return (0);
	return (1);	
}
