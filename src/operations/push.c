/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:15:25 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:52:22 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Realiza la operación de "push": mueve el primer elemento de la pila src a la pila dst.
// Si la pila de origen está vacía, no hace nada.
static void	push_operation(t_stack *dst, t_stack *src)
{
	t_node	*temp;

	if (src->size == 0)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dst->top;
	dst->top = temp;
	src->size--;
	dst->size++;
}

// Toma el primer elemento de la pila B y lo coloca en la pila A.
// Imprime "pa" para indicar la operación.
void	pa(t_stack *a, t_stack *b)
{
	push_operation(a, b);
	ft_printf("pa\n");
}

// Toma el primer elemento de la pila A y lo coloca en la pila B.
// Imprime "pb" para indicar la operación.
void	pb(t_stack *a, t_stack *b)
{
	push_operation(b, a);
	ft_printf("pb\n");
}
