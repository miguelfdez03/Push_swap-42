/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:18:02 by miguel-f          #+#    #+#             */
/*   Updated: 2025/05/30 13:24:03 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

/* Stack node structure */
typedef struct s_node
{
    int				value;
    int				index;
    struct s_node	*next;
}					t_node;

/* Stack structure */
typedef struct s_stack
{
    t_node	*top;
    int		size;
}			t_stack;

void				error_exit(char *message);
void				free_stack(t_stack *stack);
bool				parse_arguments(int argc, char **argv, t_stack *stack_a);
bool				has_duplicates(t_stack *stack);
bool				is_valid_number(char *str);
t_node				*create_node(int value);
void				add_to_bottom(t_stack *stack, t_node *node);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
#endif