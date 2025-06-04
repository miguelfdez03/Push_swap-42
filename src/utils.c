/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:02:41 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 13:24:44 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	else
		ft_putendl_fd("Error", 2);
	exit(1);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_to_bottom(t_stack *stack, t_node *node)
{
	t_node	*current;

	if (!node)
		return ;
	if (!stack->top)
	{
		stack->top = node;
	}
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
