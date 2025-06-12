/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:44:46 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/03 14:32:58 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Función: is_sorted
 * ------------------
 * Verifica si una pila está ordenada de menor a mayor.
 * 
 * 1. Si la pila está vacía o tiene un solo elemento, se considera ordenada
 * 2. Recorre la pila comparando cada elemento con el siguiente
 * 3. Si encuentra un par de elementos donde el primero es mayor que el siguiente,
 *    la pila no está ordenada
 * 
 * stack: Puntero a la pila que se va a verificar
 * 
 * Retorna: true si la pila está ordenada, false en caso contrario
 */
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

/*
 * Función: find_min
 * -----------------
 * Encuentra el nodo con el valor mínimo en una pila.
 * 
 * 1. Recorre toda la pila
 * 2. Mantiene un seguimiento del nodo con el valor mínimo encontrado hasta el momento
 * 
 * stack: Puntero a la pila donde se buscará el mínimo
 * 
 * Retorna: Puntero al nodo con el valor mínimo, o NULL si la pila está vacía
 */
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

/*
 * Función: find_max
 * -----------------
 * Encuentra el nodo con el valor máximo en una pila.
 * 
 * 1. Recorre toda la pila
 * 2. Mantiene un seguimiento del nodo con el valor máximo encontrado hasta el momento
 * 
 * stack: Puntero a la pila donde se buscará el máximo
 * 
 * Retorna: Puntero al nodo con el valor máximo, o NULL si la pila está vacía
 */
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

/*
 * Función: get_position
 * ---------------------
 * Encuentra la posición (índice) de un nodo con un valor específico en la pila.
 * La posición comienza desde 0 para el elemento superior (top).
 * 
 * stack: Puntero a la pila donde se buscará el valor
 * value: El valor a buscar en la pila
 * 
 * Retorna: La posición del valor en la pila, o -1 si no se encuentra
 */
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

/*
 * Función: stack_len
 * ------------------
 * Devuelve el número de elementos en una pila.
 * 
 * stack: Puntero a la pila cuya longitud se quiere conocer
 * 
 * Retorna: El número de elementos en la pila, o 0 si la pila es NULL
 */
int	stack_len(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}
