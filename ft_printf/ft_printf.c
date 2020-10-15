/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:23:51 by fgata-va          #+#    #+#             */
/*   Updated: 2020/10/15 13:35:08 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int i = 0;
	while(s[++i]);
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
	int	i = 1;

	while(n > base_len)
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
	char *hex = "0123456789abcdef";
	char *dec = "0123456789";
	long int	n = 0;
	unsigned int	h = 0;
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
			while(f[i])
			{
				i++;
				if (f[i] == 's')
				{
					str = va_arg(ap, char *);
					if (!str)
						len = 6;
					else
						len = ft_strlen(str);
					if (p == 1 && p_l < len)
						len -= p_l;
				}
				else if (f[i] == 'd')
				{
					n = va_arg(ap, long int);
					len = ft_nbrlen(n, 10);
				}
				else if (f[i] == 'x')
				{
					h = va_arg(ap, unsigned int);
					len = ft_nbrlen(n, 16);
				}
				while (w > len)
				{
					printed += write(1, " ", 1);
					w--;
				}
				if (f[i] == 's')
				{
					if(!str)
						printed += write(1, "(null)", len);
					else
						printed += write(1, str, len);
				}
				else
				{
					while (p == 1 && p_l > len)
					{
						write(1, "0", 1);
						p_l--;
					}
					if (f[i] == 'd' && (n > 0 && p == 1 && p_l > 0))
						ft_putnbr(n, dec, &printed);
					else if (f[i] == 'x')
						ft_putnbr(h, hex, &printed);
				}
			}
		}
		i++;
	}
	return (printed);
}
