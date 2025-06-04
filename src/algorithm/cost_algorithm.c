/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:00:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/04 12:00:00 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	prepare_stacks(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		return ;
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
}

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

void	cost_algorithm(t_stack *a, t_stack *b)
{
	int	*costs;
	int	cheapest_idx;
	int	*cost_a;
	int	*cost_b;
	
	prepare_stacks(a, b);
	
	costs = (int *)malloc(sizeof(int) * b->size * 2);
	if (!costs)
		error_exit("Error: Memory allocation failed");
	
	while (b->size > 0)
	{
		cost_a = costs;
		cost_b = costs + b->size;
		
		calculate_cost(a, b, cost_a, cost_b);
		
		cheapest_idx = find_cheapest_move(cost_a, cost_b, b->size);
		
		execute_cheapest_move(a, b, cost_a, cost_b, cheapest_idx);
	}
	
	free(costs);
	final_rotation(a);
}
