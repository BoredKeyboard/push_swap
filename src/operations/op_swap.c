/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 15:53:15 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:26:53 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	(void)b;
	if (ps_stacksize(*a) <= 1)
		return (false);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	return (true);
}

bool	sb(t_stack **a, t_stack **b)
{
	return (sa(b, a));
}

bool	ss(t_stack **a, t_stack **b)
{
	if (sa(a, b) == false)
		return (sb(a, b));
	sb(a, b);
	return (true);
}
