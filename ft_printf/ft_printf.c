/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:23:51 by fgata-va          #+#    #+#             */
/*   Updated: 2020/10/22 13:06:37 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}

void	ft_putnbr(long int n, char *base, int *printed)
{
	int	len = ft_strlen(base);
	int	c = 0;
	if (n >= len)
		ft_putnbr(n/len, base, printed);
	c = n % len;
	*printed += write(1, (base + c), 1);
}

int	ft_nbrlen(long int n, int base_len)
{
	int	i = 0;

	if (n < base_len)
		return (1);
	while(n > 0)
	{
		n /= base_len;
		i++;
	}
	return i;
}

int		ft_printf(const char *f, ...)
{
	va_list ap;
	int	i = 0;
	int	printed = 0;
	int	len = 0;
	int total_len = 0;
	char *hex = "0123456789abcdef";
	char *dec = "0123456789";
	char *base;
	int base_len = 0;
	long int	n = 0;
	unsigned int	h = 0;
	long int 	num = 0;
	char *str = NULL;
	int	w = 0;
	int p = 0;
	int p_l = 0;

	va_start(ap, f);
	while (f[i])
	{
		if (f[i] != '%')
			printed += write(1, (f + i), 1);
		else
		{
			p = 0;
			p_l = 0;
			w = 0;
			len = 0;
			total_len = 0;
			num = 0;
			while(f[i])
			{
				i++;
				if (f[i] == 's')
				{
					str = va_arg(ap, char *);
					if (!str)
						str = "(null)";
					len = ft_strlen(str);
					if (p == 1 && p_l < len)
					{
						len = p_l;
						total_len = p_l;
					}
				}
				else if (f[i] == 'd' || f[i] == 'x')
				{
					if (f[i] == 'd')
					{
						n = va_arg(ap, int);
						if (n > INT_MAX)
							n = INT_MIN;
						else if (n < INT_MIN)
							n = INT_MAX;
						if (n < 0)
						{
							printed += write(1, "-", 1);
							n *= -1;
						}
						base_len = 10;
						base = dec;
						num = n;
					}
					else if (f[i] == 'x')
					{
						h = va_arg(ap, int);
						base_len = 16;
						base = hex;
						num = h;
					}
					len = ft_nbrlen(n, base_len);
					total_len = len;
					if (p == 1)
					{
						if (p_l == 0 && h == 0 && n == 0)
						{
							len = 0;
							total_len = 0;
						}
						else if(p_l > len)
							total_len = p_l;
					}
				}
				else if (f[i] >= 48 && f[i] <= 57)
				{
					while(f[i] >= 48 && f[i] <= 57)
					{
						w *= 10;
						w += (f[i] - '0');
						i++;
					}
					i--;
					continue ;
				}
				else if (f[i] == '.')
				{
					i++;
					p = 1;
					while(f[i] >= 48 && f[i] <= 57)
					{
						p_l *= 10;
						p_l += (f[i] - '0');
						i++;
					}
					i--;
					continue ;
				}
				while (w > total_len)
				{
					printed += write(1, " ", 1);
					w--;
				}
				if (f[i] == 's')
				{
					if(len > 0)
						printed += write(1, str, len);
					break ;
				}
				else if (f[i] == 'd' || f[i] == 'x')
				{
					while (p_l > len)
					{
						printed += write(1, "0", 1);
						p_l--;
					}
					if (f[i] == 'd' && len > 0)
						ft_putnbr(n, base, &printed);
					else if (f[i] == 'x' && len > 0)
						ft_putnbr(h, base, &printed);
					break ;
				}
			}
		}
		i++;
	}
	return (printed);
}
