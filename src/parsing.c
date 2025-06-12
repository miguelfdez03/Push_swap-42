/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:11:02 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/10 13:48:41 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Función: is_valid_number
 * ------------------------
 * Verifica si una cadena representa un número entero válido.
 * 
 * 1. Comprueba si la cadena está vacía
 * 2. Permite un signo opcional (+ o -) al principio
 * 3. Verifica que todos los caracteres sean dígitos
 * 4. Comprueba que el número esté dentro del rango de un entero (INT_MIN a INT_MAX)
 * 
 * str: Cadena que se va a verificar
 * 
 * Retorna: true si la cadena representa un número entero válido, false en caso contrario
 */
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
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}

/*
 * Función: has_duplicates
 * -----------------------
 * Verifica si hay números duplicados en una pila.
 * 
 * 1. Compara cada elemento con todos los elementos siguientes
 * 2. Si encuentra un par de elementos con el mismo valor, hay duplicados
 * 
 * stack: Puntero a la pila que se va a verificar
 * 
 * Retorna: true si hay duplicados, false en caso contrario
 */
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

/*
 * Función: free_split
 * -------------------
 * Libera la memoria asignada por la función ft_split.
 * 
 * 1. Recorre el array de cadenas y libera cada una individualmente
 * 2. Finalmente libera el array principal
 * 
 * split: Array de cadenas que se va a liberar
 * 
 * Retorna: false, para facilitar su uso en retornos de error
 */
bool	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (false);
}

/*
 * Función: parse_and_add
 * ----------------------
 * Analiza un array de cadenas y añade los números válidos a la pila.
 * 
 * 1. Recorre el array de cadenas
 * 2. Verifica que cada cadena sea un número válido
 * 3. Convierte cada cadena a un número y lo añade a la pila
 * 
 * args: Array de cadenas con los números a analizar
 * stack_a: Puntero a la pila donde se añadirán los números
 * 
 * Retorna: true si todos los números son válidos, false si hay algún error
 */
static bool	parse_and_add(char **args, t_stack *stack_a)
{
	int	j;

	j = 0;
	while (args[j])
	{
		if (!is_valid_number(args[j]))
			return (false);
		add_to_bottom(stack_a, create_node(ft_atoi(args[j])));
		j++;
	}
	return (true);
}

/*
 * Función: parse_arguments
 * ------------------------
 * Analiza los argumentos de entrada del programa y llena la pila A.
 * 
 * 1. Si hay un solo argumento (argc == 2), lo divide por espacios con ft_split
 * 2. Si hay múltiples argumentos, los procesa directamente
 * 3. Verifica que todos los argumentos sean números válidos
 * 
 * argc: Número de argumentos
 * argv: Array de cadenas con los argumentos
 * stack_a: Puntero a la pila A donde se añadirán los números
 * 
 * Retorna: true si todos los argumentos son válidos, false si hay algún error
 */
bool	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !split[0])
			return (free_split(split));
		if (!parse_and_add(split, stack_a))
			return (free_split(split));
		free_split(split);
	}
	else
	{
		if (!parse_and_add(&argv[1], stack_a))
			return (false);
	}
	return (true);
}
