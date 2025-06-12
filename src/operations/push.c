/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:15:25 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:16 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: push_operation
 * -----------------------
 * Realiza la operación básica de empujar (push) el elemento superior de una pila
 * hacia otra pila. Toma el nodo superior de la pila origen (src) y lo coloca en
 * la parte superior de la pila destino (dst).
 * 
 * dst: Puntero a la pila destino donde se colocará el elemento
 * src: Puntero a la pila origen de donde se tomará el elemento
 * 
 * Si la pila origen está vacía, la función no hace nada.
 */
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

/*
 * Función: pa
 * -----------
 * Mueve el elemento superior de la pila B a la pila A.
 * Esta operación utiliza la función push_operation e imprime "pa"
 * para indicar que se ha realizado la operación.
 * 
 * a: Puntero a la pila A (destino)
 * b: Puntero a la pila B (origen)
 */
void	pa(t_stack *a, t_stack *b)
{
	push_operation(a, b);
	ft_printf("pa\n");
}

/*
 * Función: pb
 * -----------
 * Mueve el elemento superior de la pila A a la pila B.
 * Esta operación utiliza la función push_operation e imprime "pb"
 * para indicar que se ha realizado la operación.
 * 
 * a: Puntero a la pila A (origen)
 * b: Puntero a la pila B (destino)
 */
void	pb(t_stack *a, t_stack *b)
{
	push_operation(b, a);
	ft_printf("pb\n");
}
