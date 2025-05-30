/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:17:41 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 12:29:16 by miguel-f         ###   ########.fr       */
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
	// TODO: Aquí irá el algoritmo de ordenamiento
	// Por ahora solo mostramos que funciona
	ft_printf("Stack creado con %d elementos\n", stack_a.size);
	// Limpiar memoria
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
