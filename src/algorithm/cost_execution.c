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

// Ejecuta rotaciones combinadas (rr o rrr)
static void	do_combined_rotations(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    // Rotaciones normales combinadas (rr)
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
    
    // Rotaciones inversas combinadas (rrr)
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

// Ejecuta rotaciones individuales
static void	do_individual_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
    // Rotaciones para A
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
    
    // Rotaciones para B
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

// Ejecuta el movimiento más barato
void	execute_cheapest_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b, int cheapest_idx)
{
    int	move_cost_a;
    int	move_cost_b;
    
    move_cost_a = cost_a[cheapest_idx];
    move_cost_b = cost_b[cheapest_idx];
    
    // Ejecutar rotaciones combinadas cuando sea posible
    do_combined_rotations(a, b, &move_cost_a, &move_cost_b);
    
    // Ejecutar rotaciones individuales restantes
    do_individual_rotations(a, b, move_cost_a, move_cost_b);
    
    // Mover el elemento de B a A
    pa(a, b);
}
