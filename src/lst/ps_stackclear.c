/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stackclear.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:15:27 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:15:31 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Deletes and frees the given element and every successor of that element
// Uses the function del and free

#include "push_swap.h"

void	ps_stackclear(t_stack **lst)
{
	t_stack	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
