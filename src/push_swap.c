/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:35:00 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/09 17:26:55 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_stack_sorted(t_stack_node	*a, t_stack_node	*b)
{
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*first;
	bool			allocated;

	a = NULL;
	b = NULL;
	allocated = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		allocated = true;
	}
	init_stack_a(&a, argv, allocated);
	check_stack_sorted(a, b);
	first = a;
	while (first->prev)
		first = first->prev;
	free_stack(&first);
	if (allocated)
		free_argv(argv);
	return (0);
}
