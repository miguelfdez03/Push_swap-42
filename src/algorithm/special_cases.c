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

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

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
		ft_printf("TODO: Algoritmo de costes para %d elementos\n", a->size);
}
