/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:17:45 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 17:20:39 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)b;
	if (ps_stacksize(*a) <= 1)
		return (false);
	tmp = (*a)->next;
	ps_stacklast(*a)->next = *a;
	(*a)->next = NULL;
	*a = tmp;
	return (true);
}

bool	rb(t_stack **a, t_stack **b)
{
	return (ra(b, a));
}

bool	rr(t_stack **a, t_stack **b)
{
	if (ra(a, b) == false)
		return (rb(a, b));
	rb(a, b);
	return (true);
}
