/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 15:31:48 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/21 15:53:35 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h> //tmp

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

typedef enum e_operation {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_operation;

typedef bool	(*t_op_function)(t_stack **a, t_stack **b);

t_stack	*ps_stack_secondlast(t_stack *lst);
void	ps_stackadd_back(t_stack **lst, t_stack *new_stack);
void	ps_stackadd_front(t_stack **lst, t_stack *new_stack);
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

int		*initialize_array(int argc, char *argv[]);
int		check_if_sorted(int argc, int **arr);
int		bubble_sort_array(int argc, int **arr);
int		initialize_stack(t_data *data, char *argv[]);
void	set_stack_index(t_data *data, int argc, int *arr);

void	radix_sort(int argc, t_data *data);

void	exec_op(t_operation op, t_stack **a, t_stack **b);

void	ps_hc_three(t_stack **a, t_stack **b);
void	ps_hc_four(t_stack **a, t_stack **b);
void	ps_hc_five(t_stack **a, t_stack **b);

void	ps_choose_sort(int argc, t_data *data);

//TEMPORARY
void	debug_print_stacks(t_stack *a, t_stack *b);

#endif
