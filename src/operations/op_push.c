/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:04:04 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 17:16:52 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ps_stacksize(*b) < 1)
		return (false);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	return (true);
}

bool	pb(t_stack **a, t_stack **b)
{
	return (pa(b, a));
}
