/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:17:11 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:52:29 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Intercambia los dos primeros elementos de la pila.
// Si la pila tiene menos de dos elementos, no hace nada.
static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

// Intercambia los dos primeros elementos de la pila A y muestra "sa".
void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

// Intercambia los dos primeros elementos de la pila B y muestra "sb".
void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

// Intercambia los dos primeros elementos de ambas pilas A y B y muestra "ss".
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
