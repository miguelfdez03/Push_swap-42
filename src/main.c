/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:17:41 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/03 14:34:37 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;
	if (!parse_arguments(argc, argv, &stack_a))
	{
		free_stack(&stack_a);
		error_exit("Error: Invalid arguments");
	}
	if (has_duplicates(&stack_a))
	{
		free_stack(&stack_a);
		error_exit("Error: Duplicated values in stack A");
	}
	if (is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	push_swap_algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
