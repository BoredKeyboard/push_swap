/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stacklast.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:31:31 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:31:34 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Returns the last element of the list

#include "push_swap.h"

t_stack	*ps_stacklast(t_stack *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
