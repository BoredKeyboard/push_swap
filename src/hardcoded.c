/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hardcoded.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 15:52:19 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/21 15:52:51 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_hc_three(t_stack **a, t_stack **b)
{
	const unsigned int	arr[3] = {
		(*a)->final_index,
		(*a)->next->final_index,
		(*a)->next->next->final_index
	};

	if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		exec_op(RRA, a, b);
		exec_op(SA, a, b);
	}
	if (arr[1] < arr[0] && arr[0] < arr[2])
		exec_op(SA, a, b);
	if (arr[2] < arr[0] && arr[0] < arr[1])
		exec_op(RRA, a, b);
	if (arr[1] < arr[2] && arr[2] < arr[0])
		exec_op(RA, a, b);
	if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		exec_op(RA, a, b);
		exec_op(SA, a, b);
	}
}

void	ps_hc_four(t_stack **a, t_stack **b)
{
	exec_op(PB, a, b);
	ps_hc_three(a, b);
	if ((*a)->next->final_index < (*b)->final_index
		&& (*b)->final_index < (*a)->next->next->final_index)
	{
		exec_op(RA, a, b);
		exec_op(PA, a, b);
		exec_op(SA, a, b);
		exec_op(RRA, a, b);
		return ;
	}
	exec_op(PA, a, b);
	if ((*a)->final_index < (*a)->next->final_index)
		return ;
	else if ((*a)->final_index < (*a)->next->next->final_index)
		exec_op(SA, a, b);
	else
		exec_op(RA, a, b);
}

void	ps_hc_five(t_stack **a, t_stack **b)
{
	exec_op(PB, a, b);
	ps_hc_four(a, b);
	if ((*a)->next->final_index < (*b)->final_index
		&& (*b)->final_index < (*a)->next->next->final_index)
	{
		exec_op(RA, a, b);
		exec_op(PA, a, b);
		exec_op(SA, a, b);
		exec_op(RRA, a, b);
		return ;
	}
	if ((*a)->next->next->final_index < (*b)->final_index
		&& (*b)->final_index < (*a)->next->next->next->final_index)
	{
		exec_op(RRA, a, b);
		exec_op(PA, a, b);
		exec_op(RA, a, b);
		exec_op(RA, a, b);
		return ;
	}
	exec_op(PA, a, b);
	if ((*a)->final_index > (*a)->next->next->next->next->final_index)
		exec_op(RA, a, b);
	else if ((*a)->final_index > (*a)->next->final_index)
		exec_op(SA, a, b);
}
