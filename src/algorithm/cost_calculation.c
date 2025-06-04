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

// Encuentra la posición correcta en stack A para un valor de B
int	find_target_position(t_stack *a, int b_value)
{
    t_node	*current;
    int		target_pos;
    int		closest_bigger;
    
    // Si stack A está vacío, retornar 0
    if (a->size == 0)
        return (0);
    
    // Encontrar el elemento más pequeño mayor que b_value
    closest_bigger = INT_MAX;
    target_pos = -1;
    current = a->top;
    
    for (int i = 0; i < a->size; i++)
    {
        if (current->value > b_value && current->value < closest_bigger)
        {
            closest_bigger = current->value;
            target_pos = i;
        }
        current = current->next;
    }
    
    // Si no encontramos ningún elemento mayor, buscar el elemento mínimo
    if (target_pos == -1)
    {
        t_node *min = find_min(a);
        target_pos = get_position(a, min->value);
    }
    
    return (target_pos);
}

// Calcula el coste de mover un elemento de B a A
void	calculate_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    t_node	*current;
    int		target_pos;
    int		i;
    
    current = b->top;
    i = 0;
    while (i < b->size)
    {
        // Coste para mover elemento en B
        if (i <= b->size / 2)
            cost_b[i] = i;
        else
            cost_b[i] = i - b->size;
        
        // Encontrar posición objetivo en A
        target_pos = find_target_position(a, current->value);
        
        // Coste para posicionar A correctamente
        if (target_pos <= a->size / 2)
            cost_a[i] = target_pos;
        else
            cost_a[i] = target_pos - a->size;
        
        current = current->next;
        i++;
    }
}

// Encuentra el índice del elemento con menor coste total
int	find_cheapest_move(int *cost_a, int *cost_b, int size)
{
    int	min_cost;
    int	min_index;
    int	total_cost;
    
    min_cost = INT_MAX;
    min_index = -1;
    
    for (int i = 0; i < size; i++)
    {
        // Calcular coste total (valor absoluto)
        total_cost = ft_abs(cost_a[i]) + ft_abs(cost_b[i]);
        
        // Optimización para movimientos combinados (rr, rrr)
        if (cost_a[i] > 0 && cost_b[i] > 0)
            total_cost = ft_max(cost_a[i], cost_b[i]);
        else if (cost_a[i] < 0 && cost_b[i] < 0)
            total_cost = ft_max(ft_abs(cost_a[i]), ft_abs(cost_b[i]));
        
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            min_index = i;
        }
    }
    
    return (min_index);
}