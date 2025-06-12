/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:45:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 12:40:52 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: do_combined_rotations
 * ------------------------------
 * Realiza rotaciones combinadas en ambas pilas cuando los costes tienen el mismo signo.
 * 
 * 1. Si ambos costes son positivos, realiza rotaciones hacia arriba simultáneas (rr)
 * 2. Si ambos costes son negativos, realiza rotaciones hacia abajo simultáneas (rrr)
 * 3. Actualiza los valores de los costes después de cada operación
 * 
 * Esta función optimiza las operaciones aprovechando las instrucciones combinadas,
 * lo que reduce el número total de operaciones necesarias.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 * cost_a: Puntero al coste para la pila A (se actualiza durante la ejecución)
 * cost_b: Puntero al coste para la pila B (se actualiza durante la ejecución)
 */
static void	do_combined_rotations(t_stack *a, t_stack *b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

/*
 * Función: do_individual_rotations
 * --------------------------------
 * Realiza rotaciones individuales en cada pila para los costes restantes.
 * 
 * 1. Para la pila A:
 *    - Si cost_a > 0, realiza rotaciones hacia arriba (ra)
 *    - Si cost_a < 0, realiza rotaciones hacia abajo (rra)
 * 2. Para la pila B:
 *    - Si cost_b > 0, realiza rotaciones hacia arriba (rb)
 *    - Si cost_b < 0, realiza rotaciones hacia abajo (rrb)
 * 
 * Esta función completa las rotaciones necesarias después de las combinadas,
 * asegurando que cada pila esté en la posición correcta para el push.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 * cost_a: Coste restante para la pila A
 * cost_b: Coste restante para la pila B
 */
static void	do_individual_rotations(t_stack *a, t_stack *b, int cost_a,
		int cost_b)
{
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

/*
 * Función: execute_move
 * ---------------------
 * Ejecuta un movimiento completo para un elemento de la pila B.
 * 
 * 1. Realiza primero las rotaciones combinadas (cuando es posible)
 * 2. Luego realiza las rotaciones individuales restantes
 * 3. Finalmente, mueve el elemento de la pila B a la pila A (pa)
 * 
 * Esta función implementa la secuencia completa de operaciones para
 * mover un elemento de la pila B a su posición correcta en la pila A.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 * cost_a: Coste para la pila A
 * cost_b: Coste para la pila B
 */
void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	do_combined_rotations(a, b, &cost_a, &cost_b);
	do_individual_rotations(a, b, cost_a, cost_b);
	pa(a, b);
}

/*
 * Función: execute_cheapest_move
 * ------------------------------
 * Encuentra y ejecuta el movimiento más económico entre todos los posibles.
 * 
 * 1. Busca el índice del elemento con el menor coste total
 * 2. Ejecuta el movimiento para ese elemento
 * 
 * Esta función es el punto central del algoritmo basado en costes,
 * ya que selecciona y ejecuta el movimiento óptimo en cada iteración.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 * cost_a: Array con los costes para la pila A
 * cost_b: Array con los costes para la pila B
 */
void	execute_cheapest_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int	cheapest_idx;

	cheapest_idx = find_cheapest_move(cost_a, cost_b, b->size);
	execute_move(a, b, cost_a[cheapest_idx], cost_b[cheapest_idx]);
}
