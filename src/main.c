/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:17:41 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/10 13:33:06 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Función: init_stacks
 * --------------------
 * Inicializa las pilas A y B, y procesa los argumentos de entrada.
 * 
 * 1. Inicializa las pilas A y B como vacías
 * 2. Analiza los argumentos de entrada y llena la pila A con los números
 * 3. Verifica que no haya números duplicados en la pila A
 * 
 * argc: Número de argumentos
 * argv: Array de strings con los argumentos
 * a: Puntero a la pila A que se va a inicializar
 * b: Puntero a la pila B que se va a inicializar
 * 
 * Retorna: 1 si la inicialización fue exitosa, 0 en caso de error
 */
static int	init_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	if (!parse_arguments(argc, argv, a))
	{
		free_stack(a);
		return (error_exit(NULL), 0);
	}
	if (has_duplicates(a))
	{
		free_stack(a);
		error_exit(NULL);
	}
	return (1);
}

/*
 * Función: main
 * -------------
 * Punto de entrada principal del programa push_swap.
 * 
 * 1. Verifica que haya al menos un argumento
 * 2. Inicializa las pilas A y B con los números de entrada
 * 3. Si la pila A ya está ordenada, termina sin hacer nada
 * 4. Si no está ordenada, ejecuta el algoritmo de ordenación
 * 5. Libera la memoria utilizada por las pilas antes de terminar
 * 
 * argc: Número de argumentos
 * argv: Array de strings con los argumentos
 * 
 * Retorna: 0 al finalizar correctamente
 */
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
