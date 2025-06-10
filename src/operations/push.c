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

void	pa(t_stack *a, t_stack *b)
{
	push_operation(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push_operation(b, a);
	ft_printf("pb\n");
}
