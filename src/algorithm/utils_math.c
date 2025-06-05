/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:00:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:51:08 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Devuelve el valor absoluto de un número (si es negativo lo convierte en positivo).
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

// Devuelve el mayor de dos números dados.
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// Devuelve el menor de dos números dados.
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
