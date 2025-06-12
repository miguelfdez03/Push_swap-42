/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:25:54 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/03 14:26:53 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: sort_two
 * -----------------
 * Ordena una pila que contiene exactamente 2 elementos.
 * Si el primer elemento es mayor que el segundo, realiza un swap.
 * 
 * a: Puntero a la pila que se va a ordenar
 */
void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

/*
 * Función: sort_three
 * -------------------
 * Ordena una pila que contiene exactamente 3 elementos.
 * Implementa una solución específica para 3 elementos que requiere
 * un máximo de 2 operaciones para cualquier configuración inicial.
 * 
 * Analiza los 6 posibles casos de ordenación y aplica las operaciones
 * necesarias para cada caso particular.
 * 
 * a: Puntero a la pila que se va a ordenar
 */
void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

/*
 * Función: move_min_to_top
 * ------------------------
 * Mueve el elemento con el valor mínimo a la parte superior de la pila.
 * 
 * 1. Determina la posición del valor mínimo en la pila
 * 2. Si está en la primera mitad, usa rotaciones hacia arriba (ra)
 * 3. Si está en la segunda mitad, usa rotaciones hacia abajo (rra)
 * 
 * a: Puntero a la pila
 * min_value: El valor mínimo que se va a mover a la parte superior
 */
static void	move_min_to_top(t_stack *a, int min_value)
{
	int	min_pos;

	min_pos = get_position(a, min_value);
	if (min_pos <= a->size / 2)
	{
		while (a->top->value != min_value)
			ra(a);
	}
	else
	{
		while (a->top->value != min_value)
			rra(a);
	}
}

/*
 * Función: sort_five
 * ------------------
 * Ordena una pila que contiene hasta 5 elementos.
 * 
 * 1. Extrae los elementos más pequeños (hasta 2) a la pila B
 * 2. Ordena los 3 elementos restantes en la pila A usando sort_three
 * 3. Devuelve los elementos de la pila B a la pila A
 * 
 * Este método garantiza una ordenación eficiente para pilas de 4 o 5 elementos.
 * 
 * a: Puntero a la pila principal que se va a ordenar
 * b: Puntero a la pila auxiliar
 */
void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3)
	{
		min = find_min(a);
		move_min_to_top(a, min->value);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

/*
 * Función: push_swap_algorithm
 * ----------------------------
 * Función principal que selecciona y ejecuta el algoritmo de ordenación adecuado
 * según el tamaño de la pila.
 * 
 * 1. Verifica si la pila ya está ordenada
 * 2. Para 2 elementos, usa sort_two
 * 3. Para 3 elementos, usa sort_three
 * 4. Para 4-5 elementos, usa sort_five
 * 5. Para más elementos, usa el algoritmo de costes (cost_algorithm)
 * 
 * a: Puntero a la pila principal que se va a ordenar
 * b: Puntero a la pila auxiliar
 */
void	push_swap_algorithm(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		cost_algorithm(a, b);
}
