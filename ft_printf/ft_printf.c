/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:00:56 by fgata-va          #+#    #+#             */
/*   Updated: 2020/09/17 17:21:43 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			return((char *)s + i)
		i++;
	}
	if(s[i] == c)
		return((char *)s + i);
	return(NULL);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	n;

	i = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while(str[i] >= 48 && str[i] <= 57)
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return((int)resp * n);
}

int	ft_printstr(int ap, int precision)
{
	int	i;
	char	*str;

	i = 0;
	str = va_arg(ap, char *);
	while (str[i])
	{
		if (precision < 0 && i == precision)
			break ;
		i++;
	}
	return (i);
}


void	ft_types(char type, int width, int precision, int ap, int *printed)
{
	int	i;

	i = 0;
	if (width > 0)
	{
		while (i < width)
		{
			*printed += write(1, " ", 1);
			i++;
		}
	}
	if (type == 's')
		printed += ft_printstr(ap, precision);
	else if (type == 'd')
		printed += ft_printdgt(ap, precision);
	else if (type == 'x')
		printed += ft_printhex(ap, precision);
}

void	ft_format(const char *format, int width, int precision, int ap, int *printed)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			*printed += write(1, &format[i], 1);
		else if (format[i] == '%')
		{
			if (ft_strchr("sdx", format[i]))
			{
				ft_types(format[i], width, precision, ap, printed);
				width = 0;
				precision = 0;
			}
			else if (ft_strchr("123456789", format[i]))
				ft_width(format, &width, &i);
			else if (format[i] == '.')
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	width;
	int	precision;
	int	printed;

	va_start(ap, format);
	width = 0;
	printed = 0;
	precision = 0;
	ft_format(format, width, precision, ap, &printed);	
	return(printed);
}
