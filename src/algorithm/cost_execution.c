/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:45:00 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/04 14:45:00 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	execute_cheapest_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b, int cheapest_idx)
{
    int	move_cost_a;
    int	move_cost_b;
    
    move_cost_a = cost_a[cheapest_idx];
    move_cost_b = cost_b[cheapest_idx];
    
    do_combined_rotations(a, b, &move_cost_a, &move_cost_b);
    
    do_individual_rotations(a, b, move_cost_a, move_cost_b);
    
    pa(a, b);
}
