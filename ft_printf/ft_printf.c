/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:00:56 by fgata-va          #+#    #+#             */
/*   Updated: 2020/09/24 20:12:03 by fgata-va         ###   ########.fr       */
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
			return((char *)s + i);
		i++;
	}
	if(s[i] == c)
		return((char *)s + i);
	return(NULL);
}

int		ft_atoi(const char *str)
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
	return((int)nbr * n);
}

int			ft_putstr(const char *str, int precision[])
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (precision[0] == 1 && i > precision[1])
			break ;
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void		ft_printstr(va_list ap, int precision[], int *printed)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		*printed += ft_putstr("(null)", precision);
	else
		*printed += ft_putstr(str, precision);
}

int		ft_nbrlen(int nbr)
{
	int	i;

	i = 1;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nbr, int *printed)
{
	char	c;

	if (nbr > 9)
		ft_putnbr(nbr/10, printed);
	c = (nbr % 10) + '0';
	*printed += write(1, &c, 1);
}

int		ft_printzero(int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	return(len);
}

void	ft_printnbr(va_list ap, int precision[], int *printed)
{
	int	nbr;
	int	len;

	nbr = va_arg(ap, int);
	len = ft_nbrlen(nbr);
	if (nbr < 0 && nbr > -2147483648)
	{
		*printed += write(1, "-", 1);
		nbr *= -1;
	}
	else if (nbr == -2147483648)
	{
		*printed += write(1, "-", 1);
		if (precision[0] == 1 && precision[1] > len)
			*printed += ft_printzero(precision[1] - len);
		*printed += write(1, "2147483648", 10);
	}
	else
	{
		if (precision[0] == 1 && precision[1] > len)
			*printed += ft_printzero(precision[1] - len);
		if (nbr < -2147483648)
			*printed += write(1, "2147483647", 10);
		else if (nbr >= 2147483647)
			*printed += write(1, "2147483647", 10);
		else
			ft_putnbr(nbr, printed);
	}
}

void				ft_puthex(unsigned int nbr, int *printed)
{
	char			c;
	unsigned int	h;

	c = 0;
	h = 0;
	if (nbr >= 0)
	{
		if (nbr > 16)
			ft_puthex(nbr / 16, printed);
		h = nbr % 16;
		if(h > 9)
			c = (h - 10) + 'a';
		else if (h <= 9)
			c = h + '0';
		*printed += write(1, &c, 1);
	}	
}

int		ft_hexlen(int n)
{
	int				i;

	i = 1;
	while(n > 0)
	{
		n /= 16;
		i++;
	}
	return(i);
}

void	ft_printhex(va_list ap, int precision[], int *printed)
{
	int len;
	int nbr;

	nbr = va_arg(ap, int);
	if (nbr < 0)
		nbr *= -1;
	len = ft_hexlen(nbr);
	if (precision[0] == 1 && precision[1] > len)
			*printed += ft_printzero(precision[1] - len);
	ft_puthex(nbr, printed);
}

void	ft_types(char type, int width, int precision [], va_list ap, int *printed)
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
		ft_printnbr(ap, precision, printed);
	else if (type == 'x')
		ft_printhex(ap, precision, printed);
}

void	ft_width(const char *format, int *width, int *i)
{
	*width = ft_atoi((char *)&format[*i]);
	while (ft_strchr("0123456789", format[*i]))
		*i += 1;
}

void	ft_precision(const char *format, int *precision, int *p_len, int *i)
{
	*precision = 1;
	*p_len = ft_atoi((char *)&format[*i]);
	while (ft_strchr("0123456789", format[*i]))
		*i += 1;
}


void	ft_format(const char *format, va_list ap, int *printed)
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
			while (1)
			{
				i++;
				if (ft_strchr("sdx", format[i]))
				{
					ft_types(format[i], width, precision, ap, printed);
					width = 0;
					precision[0] = 0;
					precision[1] = 0;
					break;
				}
				else if (ft_strchr("0123456789", format[i]))
				{
					ft_width(format, &width, &i);
					i--;
				}
				else if (format[i] == '.')
					ft_precision(format, &precision[0], &precision[1], &i);
			}
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
