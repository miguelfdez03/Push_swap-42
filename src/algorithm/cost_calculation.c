/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:30:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/04 14:30:00 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_target_position(t_stack *a, int b_value)
{
	t_node	*current;
	int		closest_bigger_pos;
	int		closest_bigger_val;
	int		min_pos;
	int		min_val;
	
	if (a->size == 0)
		return (0);
	
	closest_bigger_pos = -1;
	closest_bigger_val = INT_MAX;
	min_pos = 0;
	min_val = INT_MAX;
	current = a->top;
	
	for (int i = 0; i < a->size; i++)
	{
		if (current->value > b_value && current->value < closest_bigger_val)
		{
			closest_bigger_val = current->value;
			closest_bigger_pos = i;
		}
		
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = i;
		}
		
		current = current->next;
	}
	
	return (closest_bigger_pos == -1) ? min_pos : closest_bigger_pos;
}

void	calculate_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	t_node	*current;
	int		target_pos;
	int		i;
	
	current = b->top;
	i = 0;
	while (i < b->size)
	{
		if (i <= b->size / 2)
			cost_b[i] = i;
		else
			cost_b[i] = i - b->size;
		
		target_pos = find_target_position(a, current->value);
		
		if (target_pos <= a->size / 2)
			cost_a[i] = target_pos;
		else
			cost_a[i] = target_pos - a->size;
		
		current = current->next;
		i++;
	}
}

int	find_cheapest_move(int *cost_a, int *cost_b, int size)
{
	int	min_cost;
	int	min_index;
	int	total_cost;
	
	min_cost = INT_MAX;
	min_index = -1;
	
	for (int i = 0; i < size; i++)
	{
		if ((cost_a[i] > 0 && cost_b[i] > 0) || (cost_a[i] < 0 && cost_b[i] < 0))
			total_cost = ft_max(ft_abs(cost_a[i]), ft_abs(cost_b[i]));
		else
			total_cost = ft_abs(cost_a[i]) + ft_abs(cost_b[i]);
		
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			min_index = i;
		}
	}
	
	return (min_index);
}