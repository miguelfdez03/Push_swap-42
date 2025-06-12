/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:16:04 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:18 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Función: reverse_rotate
 * -----------------------
 * Rota todos los elementos de la pila hacia abajo.
 * El último elemento se convierte en el primero (top),
 * mientras que los demás elementos se mueven una posición hacia abajo.
 * 
 * stack: Puntero a la pila que se va a rotar inversamente
 * 
 * Si la pila tiene menos de 2 elementos, la función no hace nada.
 */
static void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

/*
 * Función: rra
 * ------------
 * Rota todos los elementos de la pila A hacia abajo.
 * Usa la función reverse_rotate e imprime "rra" para indicar que
 * se ha realizado la operación.
 * 
 * a: Puntero a la pila A
 */
void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

/*
 * Función: rrb
 * ------------
 * Rota todos los elementos de la pila B hacia abajo.
 * Usa la función reverse_rotate e imprime "rrb" para indicar que
 * se ha realizado la operación.
 * 
 * b: Puntero a la pila B
 */
void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

/*
 * Función: rrr
 * ------------
 * Rota todos los elementos tanto de la pila A como de la pila B hacia abajo.
 * Usa la función reverse_rotate para ambas pilas e imprime "rrr" para indicar que
 * se ha realizado la operación doble.
 * 
 * a: Puntero a la pila A
 * b: Puntero a la pila B
 */
void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
