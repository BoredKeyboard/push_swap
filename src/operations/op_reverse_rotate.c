/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_reverse_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:29:47 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:51:45 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*second_last;

	(void)b;
	if (ps_stacksize(*a) <= 1)
		return (false);
	second_last = ps_stack_secondlast(*a);
	tmp = second_last->next;
	tmp->next = *a;
	second_last->next = NULL;
	*a = tmp;
	return (true);
}

bool	rrb(t_stack **a, t_stack **b)
{
	return (rra(b, a));
}

bool	rrr(t_stack **a, t_stack **b)
{
	if (rra(a, b) == false)
		return (rrb(a, b));
	rrb(a, b);
	return (true);
}
