/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:00:56 by fgata-va          #+#    #+#             */
/*   Updated: 2020/09/22 20:03:26 by fgata-va         ###   ########.fr       */
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
		if (precision == 1 && i == precision_l)
			break ;
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 0 && nbr > -2147483648)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	else if (nbr > 9)
		putnbr(nbr/10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int	ft_printnbr(int ap, int *printed)
{
	int	nbr;

	nbr = va_arg(ap, int);
	if (nbr == -2147483648)
		*printed += write(1, "-2147483648", 11);
	else if (nbr < -2147483648)
		*printed += write(1, "2147483647", 10);
	else if (nbr >= 2147483647)
		*printed += write(1, "2147483647", 10);
	else
		ft_putnbr(nbr);
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
		ft_printstr(ap, precision, printed);
	else if (type == 'd')
		ft_printnbr(ap, printed);
	else if (type == 'x')
		ft_printhex(ap, precision, printed);
}

void	ft_format(const char *format, int ap, int *printed)
{
	int	i;
	int	width;
	int	precision[2];

	i = 0;
	width = 0;
	precision[0] = 0;
	precision[1] = 0;
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
				precision[0] = 0;
				precision[1] = 0;
			}
			else if (ft_strchr("123456789", format[i]))
				ft_width(format, &width, &i);
			else if (format[i] == '.')
				ft_precision(format, &precision[0], &precision[1], &i);
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	printed;

	va_start(ap, format);
	printed = 0;
	ft_format(format, ap, &printed);	
	return(printed);
}
