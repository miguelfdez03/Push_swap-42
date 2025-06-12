/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:00:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/10 13:40:28 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: prepare_stacks
 * -----------------------
 * Prepara las pilas para el algoritmo de ordenación.
 * 
 * 1. Si la pila A tiene 3 o menos elementos, termina sin hacer nada
 * 2. Mueve todos los elementos excepto 3 de la pila A a la pila B
 * 3. Ordena los 3 elementos restantes en la pila A
 * 
 * Esta función deja la pila A con 3 elementos ordenados y el resto en la pila B.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 */
static void	prepare_stacks(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		return ;
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
}

/*
 * Función: final_rotation
 * -----------------------
 * Realiza una rotación final de la pila A para que el elemento mínimo quede en la parte superior.
 * 
 * 1. Encuentra el nodo con el valor mínimo en la pila A
 * 2. Determina su posición
 * 3. Realiza rotaciones (ra o rra) para mover el mínimo a la parte superior
 * 
 * Esta función garantiza que la pila quede ordenada de menor a mayor (con el mínimo arriba).
 * 
 * a: Puntero a la pila A que se va a rotar
 */
static void	final_rotation(t_stack *a)
{
	t_node	*min_node;
	int		min_pos;

	min_node = find_min(a);
	min_pos = get_position(a, min_node->value);
	if (min_pos <= a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < a->size)
		{
			rra(a);
			min_pos++;
		}
	}
}

/*
 * Función: cost_algorithm
 * -----------------------
 * Implementa el algoritmo principal de ordenación basado en costes.
 * 
 * 1. Prepara las pilas (3 elementos ordenados en A, resto en B)
 * 2. Para cada elemento en la pila B, calcula el coste de moverlo a su posición correcta en A
 * 3. Ejecuta el movimiento con menor coste
 * 4. Repite hasta que todos los elementos estén en la pila A
 * 5. Realiza una rotación final para que el mínimo quede arriba
 * 
 * Este algoritmo optimiza el número de operaciones necesarias para ordenar la pila.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 */
void	cost_algorithm(t_stack *a, t_stack *b)
{
	int	*costs;
	int	cheapest_idx;
	int	*cost_a;
	int	*cost_b;

	prepare_stacks(a, b);
	costs = (int *)malloc(sizeof(int) * b->size * 2);
	if (!costs)
		error_exit(NULL);
	while (b->size > 0)
	{
		cost_a = costs;
		cost_b = costs + b->size;
		calculate_cost(a, b, cost_a, cost_b);
		cheapest_idx = find_cheapest_move(cost_a, cost_b, b->size);
		execute_cheapest_move(a, b, cost_a, cost_b);
	}
	free(costs);
	final_rotation(a);
}
