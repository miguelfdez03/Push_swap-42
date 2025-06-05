/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:11:02 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 12:25:26 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_number(char *str)
{
	int		i;
	long	num;

	if (!str || !str[0])
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

bool	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;
	int		i;
	int		j;

	if (!stack->top || stack->size <= 1)
		return (false);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		checker = current->next;
		j = i + 1;
		while (j < stack->size)
		{
			if (current->value == checker->value)
				return (true);
			checker = checker->next;
			j++;
		}
		current = current->next;
		i++;
	}
	return (false);
}

bool	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		node = create_node(ft_atoi(argv[i]));
		if (!node)
			return (false);
		add_to_bottom(stack_a, node);
		i++;
	}
	return (true);
}
