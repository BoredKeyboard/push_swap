/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort_test.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 14:37:53 by mforstho      #+#    #+#                 */
/*   Updated: 2022/09/15 14:58:12 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	tmp;
	// int	arr[] = {5, 1, 4, 2, 8};
	int	sorted;
	int	*arr;

	i = 0;
	tmp = 0;
	arr = malloc((argc - 1) * sizeof(int));

	while (i < argc - 1)
	{
		ft_atoi(argv[i + 1], &tmp);
		printf("%s  ", argv[i + 1]);
		arr[i] = tmp;
		printf("%i\n", arr[i]);
		i++;
	}




	// i = 1;
	// tmp = 0;
	// sorted = 0;
	// printf("%i, %i, %i, %i, %i\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	// while (sorted != argc - 1)
	// {
	// 	sorted = 0;
	// 	i = 1;
	// 	while (i < argc)
	// 	{
	// 		if (arr[i] > arr[i + 1])
	// 		{
	// 			tmp = arr[i];
	// 			arr[i] = arr[i + 1];
	// 			arr[i + 1] = tmp;
	// 		}
	// 		else
	// 			sorted++;
	// 		printf("%i, %i, %i, %i, %i\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// }
	return (0);
}