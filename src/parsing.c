/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:11:02 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 12:22:06 by miguel-f         ###   ########.fr       */
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
	int		count_current;
	int		count_checker;

	if (!stack->top || stack->size <= 1)
		return (false);
	current = stack->top;
	count_current = 0;
	while (count_current < stack->size)
	{
		checker = current->next;
		count_checker = count_current + 1;
		while (count_checker < stack->size)
		{
			if (current->value == checker->value)
				return (true);
			checker = checker->next;
			count_checker++;
		}
		current = current->next;
		count_current++;
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
