/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:11:02 by miguel-f          #+#    #+#             */
/*   Updated: 2025/06/05 18:02:55 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprueba si una cadena es un número válido y está dentro del rango de int.
// Así se evita meter datos incorrectos en la pila.
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

// Recorre la pila y comprueba si hay algún valor repetido.
// Devuelve true si encuentra duplicados.
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

// Libera la memoria reservada por un array de strings (como el que devuelve ft_split).
// Es útil para evitar fugas de memoria cuando se usa split para separar argumentos.
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

// Recorre un array de strings, valida cada uno como número y lo añade a la pila.
// Si algún string no es válido, devuelve false.
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

// Lee los argumentos del programa, los valida y los añade a la pila A.
// Si algún argumento es inválido, devuelve false.
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
