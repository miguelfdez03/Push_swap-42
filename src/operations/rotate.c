/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:16:31 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:20 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: rotate
 * ---------------
 * Rota todos los elementos de la pila hacia arriba.
 * El primer elemento (top) se convierte en el último, mientras
 * que el segundo elemento pasa a ser el primero.
 * 
 * stack: Puntero a la pila que se va a rotar
 * 
 * Si la pila tiene menos de 2 elementos, la función no hace nada.
 */
static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*temp;

	if (stack->size < 2)
		return ;
	first = stack->top;
	temp = stack->top;
	while (temp->next)
		temp = temp->next;
	stack->top = first->next;
	first->next = NULL;
	temp->next = first;
}

/*
 * Función: ra
 * -----------
 * Rota todos los elementos de la pila A hacia arriba.
 * Usa la función rotate e imprime "ra" para indicar que
 * se ha realizado la operación.
 * 
 * a: Puntero a la pila A
 */
void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

/*
 * Función: rb
 * -----------
 * Rota todos los elementos de la pila B hacia arriba.
 * Usa la función rotate e imprime "rb" para indicar que
 * se ha realizado la operación.
 * 
 * b: Puntero a la pila B
 */
void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

/*
 * Función: rr
 * -----------
 * Rota todos los elementos tanto de la pila A como de la pila B hacia arriba.
 * Usa la función rotate para ambas pilas e imprime "rr" para indicar que
 * se ha realizado la operación doble.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 */
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
