/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:17:41 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 13:51:09 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Inicializa las pilas A y B y valida los argumentos de entrada.
// Si hay algún error, muestra un mensaje y termina el programa.
static int	init_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	if (!parse_arguments(argc, argv, a))
		return (error_exit("Error: Invalid arguments"), 0);
	if (has_duplicates(a))
	{
		free_stack(a);
		error_exit("Error: Duplicated values in stack A");
	}
	return (1);
}

// Función principal del programa.
// Se encarga de preparar las pilas, comprobar si ya están ordenadas
// y ejecutar el algoritmo de ordenación si es necesario.
int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	if (!init_stacks(argc, argv, &stack_a, &stack_b))
		return (0);
	if (is_sorted(&stack_a))
		return (free_stack(&stack_a), 0);
	push_swap_algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
