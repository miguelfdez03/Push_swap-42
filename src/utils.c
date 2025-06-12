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

/*
 * Función: error_exit
 * -------------------
 * Muestra un mensaje de error en la salida de error estándar y termina el programa.
 * Si no se proporciona un mensaje específico, muestra "Error" por defecto.
 * 
 * message: Mensaje de error a mostrar (puede ser NULL)
 * 
 * Esta función nunca retorna, ya que termina la ejecución del programa con código 1.
 */
void	error_exit(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	else
		ft_putendl_fd("Error", 2);
	exit(1);
}

/*
 * Función: create_node
 * --------------------
 * Crea un nuevo nodo para una pila con el valor especificado.
 * 
 * 1. Asigna memoria para el nuevo nodo
 * 2. Inicializa sus campos: valor, índice (-1 por defecto) y puntero siguiente (NULL)
 * 
 * value: Valor entero a almacenar en el nodo
 * 
 * Retorna: Puntero al nuevo nodo creado, o NULL si falló la asignación de memoria
 */
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

/*
 * Función: add_to_bottom
 * ----------------------
 * Añade un nodo al final (parte inferior) de una pila.
 * 
 * 1. Si la pila está vacía, el nodo se convierte en el primero
 * 2. Si no, recorre la pila hasta el último nodo y añade el nuevo nodo después
 * 3. Incrementa el contador de tamaño de la pila
 * 
 * stack: Puntero a la pila donde se añadirá el nodo
 * node: Puntero al nodo que se va a añadir
 */
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

/*
 * Función: free_stack
 * -------------------
 * Libera toda la memoria ocupada por una pila.
 * 
 * 1. Recorre todos los nodos de la pila
 * 2. Libera la memoria de cada nodo uno por uno
 * 3. Reinicia los valores de la pila (top = NULL, size = 0)
 * 
 * stack: Puntero a la pila que se va a liberar
 */
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
