/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_atoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/14 13:56:20 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/14 14:33:25 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	new_atoi(const char *str, int *result)
{
	int		i;
	long	converted;
	int		min;

	i = 0;
	converted = 0;
	min = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		min = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
	{
		converted = converted * 10;
		converted = converted + str[i] - '0';
		if (converted * min > INT_MAX || converted * min < INT_MIN)
			return (false);
		i++;
	}
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] != '\0')
		return (false);
	*result = converted * min;
	return (true);
}
