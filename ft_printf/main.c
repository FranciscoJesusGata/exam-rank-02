/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:01:04 by fgata-va          #+#    #+#             */
/*   Updated: 2020/09/24 10:16:46 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int pf1;
	int pf2;

	pf1 = ft_printf("La %s a todo es %d\n", "respuesta", 42);
	pf2 = printf("La %s a todo es %d\n", "respuesta", 42);
	printf("Escrito por printf: %d\nEscrito por ft_printf: %d\n", pf2, pf1);
}
