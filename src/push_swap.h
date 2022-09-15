/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:31:48 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/15 15:16:32 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include "libft.h"

typedef struct s_stack
{
	int				content;
	unsigned int	final_index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

typedef enum e_error {
	NO_ERROR,
}	t_error;

typedef enum e_status {
	OK = 0,
	ERROR,
}	t_status;

t_stack	*ps_stack_secondlast(t_stack *lst);
void	ps_stackadd_back(t_stack **lst, t_stack *new);
void	ps_stackadd_front(t_stack **lst, t_stack *new);
void	ps_stackclear(t_stack **lst);
t_stack	*ps_stacklast(t_stack *lst);
t_stack	*ps_stacknew_back(t_stack **lst, int data);
t_stack	*ps_stacknew(int data);
int		ps_stacksize(t_stack *lst);

bool	sa(t_stack **a, t_stack **b);
bool	sb(t_stack **a, t_stack **b);
bool	ss(t_stack **a, t_stack **b);

bool	pa(t_stack **a, t_stack **b);
bool	pb(t_stack **a, t_stack **b);

bool	ra(t_stack **a, t_stack **b);
bool	rb(t_stack **a, t_stack **b);
bool	rr(t_stack **a, t_stack **b);

bool	rra(t_stack **a, t_stack **b);
bool	rrb(t_stack **a, t_stack **b);
bool	rrr(t_stack **a, t_stack **b);


//TEMPORARY
void	debug_print_stacks(t_stack *a, t_stack *b);

#endif
