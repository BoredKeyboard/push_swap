/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stackadd_front.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:31:54 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:31:55 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Adds the element new to the front of the list

#include "push_swap.h"

void	ps_stackadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
