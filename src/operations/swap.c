/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:17:11 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:24 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: swap
 * -------------
 * Intercambia los dos elementos superiores de una pila.
 * Toma los dos primeros nodos de la pila y cambia su orden,
 * manteniendo el resto de la pila intacta.
 * 
 * stack: Puntero a la pila cuyos elementos superiores se intercambiarán
 * 
 * Si la pila tiene menos de 2 elementos, la función no hace nada.
 */
static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

/*
 * Función: sa
 * -----------
 * Intercambia los dos elementos superiores de la pila A.
 * Usa la función swap e imprime "sa" para indicar que se
 * ha realizado la operación.
 * 
 * a: Puntero a la pila A
 */
void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

/*
 * Función: sb
 * -----------
 * Intercambia los dos elementos superiores de la pila B.
 * Usa la función swap e imprime "sb" para indicar que se
 * ha realizado la operación.
 * 
 * b: Puntero a la pila B
 */
void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

/*
 * Función: ss
 * -----------
 * Intercambia los dos elementos superiores tanto de la pila A como de la pila B.
 * Usa la función swap para ambas pilas e imprime "ss" para indicar que
 * se ha realizado la operación doble.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 */
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
