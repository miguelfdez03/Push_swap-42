/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:30:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 12:49:34 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_closest_bigger(t_stack *a, int b_value, int *pos)
{
	t_node	*current;
	int		closest_val;
	int		i;

	current = a->top;
	closest_val = INT_MAX;
	*pos = -1;
	i = 0;
	while (i < a->size)
	{
		if (current->value > b_value && current->value < closest_val)
		{
			closest_val = current->value;
			*pos = i;
		}
		current = current->next;
		i++;
	}
}

static void	find_min_value(t_stack *a, int *pos)
{
	t_node	*current;
	int		min_val;
	int		i;

	current = a->top;
	min_val = INT_MAX;
	*pos = -1;
	i = 0;
	while (i < a->size)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			*pos = i;
		}
		current = current->next;
		i++;
	}
}

int	find_target_position(t_stack *a, int b_value)
{
	int	closest_bigger_pos;
	int	min_pos;

	if (a->size == 0)
		return (0);
	find_closest_bigger(a, b_value, &closest_bigger_pos);
	find_min_value(a, &min_pos);
	if (closest_bigger_pos == -1)
		return (min_pos);
	return (closest_bigger_pos);
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
	int	i;

	min_cost = INT_MAX;
	min_index = -1;
	i = 0;
	while (i < size)
	{
		if ((cost_a[i] > 0 && cost_b[i] > 0) || (cost_a[i] < 0
				&& cost_b[i] < 0))
			total_cost = ft_max(ft_abs(cost_a[i]), ft_abs(cost_b[i]));
		else
			total_cost = ft_abs(cost_a[i]) + ft_abs(cost_b[i]);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
