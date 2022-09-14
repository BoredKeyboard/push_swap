/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stackadd_back.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:31:48 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:31:48 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Adds the element new to the end of the list

#include "push_swap.h"

void	ps_stackadd_back(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ps_stacklast(*lst)->next = new;
}
