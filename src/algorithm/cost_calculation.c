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

/*
 * Función: find_closest_bigger
 * ----------------------------
 * Encuentra el elemento más cercano en valor que sea mayor que un valor dado.
 * 
 * 1. Recorre la pila A
 * 2. Busca el valor más pequeño que sea mayor que b_value
 * 3. Guarda la posición de este valor en pos
 * 
 * Esta función se utiliza para encontrar la posición correcta donde insertar
 * un elemento de la pila B en la pila A.
 * 
 * a: Puntero a la pila A
 * b_value: Valor de referencia
 * pos: Puntero donde se guardará la posición encontrada (-1 si no hay ningún valor mayor)
 */
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

/*
 * Función: find_min_value
 * -----------------------
 * Encuentra la posición del elemento con el valor mínimo en una pila.
 * 
 * 1. Recorre la pila A
 * 2. Mantiene un seguimiento del valor mínimo encontrado
 * 3. Guarda la posición de este valor en pos
 * 
 * a: Puntero a la pila A
 * pos: Puntero donde se guardará la posición del valor mínimo
 */
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

/*
 * Función: find_target_position
 * -----------------------------
 * Determina la posición objetivo en la pila A para un valor de la pila B.
 * 
 * 1. Si la pila A está vacía, retorna 0
 * 2. Busca el elemento más cercano mayor que b_value
 * 3. Si no hay ningún elemento mayor, busca el elemento mínimo
 * 
 * Esta función es clave para determinar dónde debe insertarse cada elemento
 * de la pila B para mantener el orden en la pila A.
 * 
 * a: Puntero a la pila A
 * b_value: Valor del elemento de la pila B que se va a insertar
 * 
 * Retorna: La posición objetivo en la pila A
 */
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

/*
 * Función: calculate_cost
 * -----------------------
 * Calcula el coste de mover cada elemento de la pila B a su posición correcta en la pila A.
 * 
 * 1. Para cada elemento en la pila B:
 *    - Calcula el coste de moverlo a la parte superior de B (cost_b)
 *    - Encuentra su posición objetivo en A
 *    - Calcula el coste de preparar esa posición en A (cost_a)
 * 
 * Los costes positivos indican rotaciones hacia arriba (ra/rb)
 * Los costes negativos indican rotaciones hacia abajo (rra/rrb)
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 * cost_a: Array donde se guardarán los costes para la pila A
 * cost_b: Array donde se guardarán los costes para la pila B
 */
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

/*
 * Función: find_cheapest_move
 * ---------------------------
 * Encuentra el movimiento con menor coste total entre todos los elementos de la pila B.
 * 
 * 1. Para cada elemento en la pila B, calcula el coste total:
 *    - Si ambos costes (cost_a y cost_b) tienen el mismo signo, se pueden combinar (rr/rrr)
 *    - Si tienen signos diferentes, deben realizarse por separado
 * 2. Encuentra el índice del elemento con el menor coste total
 * 
 * cost_a: Array con los costes para la pila A
 * cost_b: Array con los costes para la pila B
 * size: Tamaño de la pila B
 * 
 * Retorna: El índice del elemento con el menor coste total
 */
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
