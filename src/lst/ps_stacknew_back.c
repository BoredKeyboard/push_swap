/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stacknew_back.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 16:31:40 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 16:31:41 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_stacknew_back(t_stack **lst, int data)
{
	t_stack	*new_lst;

	new_lst = ps_stacknew(data);
	if (new_lst == NULL)
		return (NULL);
	ps_stackadd_back(lst, new_lst);
	return (new_lst);
}
