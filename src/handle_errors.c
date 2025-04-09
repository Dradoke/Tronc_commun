/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:03:12 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/09 17:28:58 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	if (!stack && !(*stack))
		return ;
	if ((*stack)->next)
		free_stack(&(*stack)->next);
	free(*stack);
}

void	free_argv(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_errors(t_stack_node **a, char **argv, bool allocated)
{
	free_stack(a);
	if (allocated)
		free_argv(argv);
	ft_printf("Error\n");
	exit(1);
}
