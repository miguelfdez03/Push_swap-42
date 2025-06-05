/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:45:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:51:07 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Realiza rotaciones en ambas pilas al mismo tiempo si es posible.
// Esto ahorra movimientos cuando ambos costes son positivos o negativos.
static void	do_combined_rotations(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
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

// Realiza las rotaciones que faltan en cada pila por separado.
// Así se termina de colocar cada pila en la posición correcta antes de hacer el push.
static void	do_individual_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b)
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

// Ejecuta todos los movimientos necesarios para llevar un elemento de B a su sitio en A.
// Primero hace las rotaciones combinadas, luego las individuales, y finalmente el push.
void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	do_combined_rotations(a, b, &cost_a, &cost_b);
	do_individual_rotations(a, b, cost_a, cost_b);
	pa(a, b);
}

// Busca cuál es el movimiento más barato y lo ejecuta.
// Así siempre se avanza de la forma más eficiente posible.
void	execute_cheapest_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int	cheapest_idx;

	cheapest_idx = find_cheapest_move(cost_a, cost_b, b->size);
	execute_move(a, b, cost_a[cheapest_idx], cost_b[cheapest_idx]);
}
