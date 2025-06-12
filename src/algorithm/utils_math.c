/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:00:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 11:40:32 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: ft_abs
 * ---------------
 * Calcula el valor absoluto de un número entero.
 * El valor absoluto es el valor numérico sin signo.
 * 
 * n: Número entero del que se calculará el valor absoluto
 * 
 * Retorna: El valor absoluto de n
 */
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/*
 * Función: ft_max
 * ---------------
 * Encuentra el mayor de dos números enteros.
 * 
 * a: Primer número entero
 * b: Segundo número entero
 * 
 * Retorna: El mayor valor entre a y b
 */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
 * Función: ft_min
 * ---------------
 * Encuentra el menor de dos números enteros.
 * 
 * a: Primer número entero
 * b: Segundo número entero
 * 
 * Retorna: El menor valor entre a y b
 */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
