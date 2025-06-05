/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:16:31 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:52:24 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Realiza una rotación en la pila: el primer elemento pasa al final.
// Si la pila tiene menos de dos elementos, no hace nada.
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

// Aplica la rotación a la pila A y muestra "ra".
void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

// Aplica la rotación a la pila B y muestra "rb".
void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

// Aplica la rotación a ambas pilas A y B a la vez y muestra "rr".
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
