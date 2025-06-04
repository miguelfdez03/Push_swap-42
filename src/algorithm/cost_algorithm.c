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

// Deja 3 elementos en stack A y mueve el resto a B
static void	prepare_stacks(t_stack *a, t_stack *b)
{
    if (a->size <= 3)
        return ;
    while (a->size > 3)
        pb(a, b);
    sort_three(a);
}

// Ajusta la posición final en A después de ordenar
static void	final_rotation(t_stack *a)
{
    t_node	*min_node;
    int		min_pos;
    
    min_node = find_min(a);
    min_pos = get_position(a, min_node->value);
    
    // Rotar el stack A para que el mínimo esté en la parte superior
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

// Algoritmo principal de costes
void	cost_algorithm(t_stack *a, t_stack *b)
{
    int	*cost_a;
    int	*cost_b;
    int	cheapest_idx;
    
    // Preparar stacks iniciales
    prepare_stacks(a, b);
    
    // Mientras haya elementos en B
    while (b->size > 0)
    {
        // Asignar memoria para arrays de costes
        cost_a = (int *)malloc(sizeof(int) * b->size);
        cost_b = (int *)malloc(sizeof(int) * b->size);
        if (!cost_a || !cost_b)
        {
            if (cost_a)
                free(cost_a);
            error_exit("Error: Memory allocation failed");
        }
        
        // Calcular costes
        calculate_cost(a, b, cost_a, cost_b);
        
        // Encontrar movimiento más barato
        cheapest_idx = find_cheapest_move(cost_a, cost_b, b->size);
        
        // Ejecutar movimiento más barato
        execute_cheapest_move(a, b, cost_a, cost_b, cheapest_idx);
        
        // Liberar memoria
        free(cost_a);
        free(cost_b);
    }
    
    // Ajustar posición final en A
    final_rotation(a);
}
