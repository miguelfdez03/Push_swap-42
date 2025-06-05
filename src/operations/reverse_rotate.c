/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:16:04 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:52:23 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Realiza una rotación inversa en la pila: el último elemento pasa a ser el primero.
// Si la pila tiene menos de dos elementos, no hace nada.
static void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

// Aplica la rotación inversa a la pila A y muestra "rra".
void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

// Aplica la rotación inversa a la pila B y muestra "rrb".
void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

// Aplica la rotación inversa a ambas pilas A y B a la vez y muestra "rrr".
void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
