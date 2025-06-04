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
	int		min;
	int		max;
	int		range;
	bool	*hash_table;
	
	if (!stack->top || stack->size <= 1)
		return (false);
	
	min = find_min(stack)->value;
	max = find_max(stack)->value;
	range = max - min + 1;
	
	if (stack->size < 100 || range > 10000)
	{
		current = stack->top;
		for (int i = 0; i < stack->size; i++)
		{
			t_node *checker = current->next;
			for (int j = i + 1; j < stack->size; j++)
			{
				if (current->value == checker->value)
					return (true);
				checker = checker->next;
			}
			current = current->next;
		}
		return (false);
	}
	
	hash_table = (bool *)ft_calloc(range, sizeof(bool));
	if (!hash_table)
		return (false);
	
	current = stack->top;
	while (current)
	{
		int hash_index = current->value - min;
		if (hash_table[hash_index])
		{
			free(hash_table);
			return (true);
		}
		hash_table[hash_index] = true;
		current = current->next;
	}
	
	free(hash_table);
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
