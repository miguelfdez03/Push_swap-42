/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:44:46 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:51:08 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprueba si la pila está ordenada de menor a mayor.
// Devuelve true si ya está ordenada y false si no lo está.
bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->top || stack->size <= 1)
		return (true);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

// Busca el nodo con el valor más pequeño de la pila y lo devuelve.
// Sirve para encontrar rápidamente el mínimo.
t_node	*find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack->top)
		return (NULL);
	current = stack->top;
	min_node = current;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

// Busca el nodo con el valor más grande de la pila y lo devuelve.
// Sirve para encontrar rápidamente el máximo.
t_node	*find_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	if (!stack->top)
		return (NULL);
	current = stack->top;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

// Busca la posición (empezando en 0) de un valor concreto en la pila.
// Si no lo encuentra, devuelve -1.
int	get_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;

	if (!stack->top)
		return (-1);
	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

// Devuelve cuántos elementos hay en la pila.
int	stack_len(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}
