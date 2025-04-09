/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:12:07 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/04/09 15:28:19 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "push_swap.h"
# include "struct.h"

/*-----INIT_A_TO_B-----*/
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);

/*-----INIT_B_TO_A-----*/
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

/*-----PUSH_SWAP-----*/
int				main(int argc, char **argv);

/*-----ROTATE-----*/
void			rr(t_stack_node **a, t_stack_node **b, bool print);

/*-----SORT_STACKS-----*/
void			sort_stacks(t_stack_node **a, t_stack_node **b);

/*-----SORT_STACKS_UTILS-----*/
void			min_on_top(t_stack_node **a);

/*-----SORT_THREE-----*/
void			sort_three(t_stack_node **a);

/*-----STACK_INIT-----*/
void			init_stack_a(t_stack_node **a, char **argv, bool allocated);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack,
					t_stack_node *top_node,
					char stack_name);

/*-----STACK_UTILS-----*/
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/*-----HANDLE_ERRORS-----*/
int				error_syntax(char *str);
int				have_duplicates(char **av);
int				nbstr_cmp(const char *s1, const char *s2);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a, char **argv, bool allocated);
void			free_argv(char **argv);

/*-----COMMANDS-----*/
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

char			**split(char *s, char c);
/*-----ALGORITHMS-----*/
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

int	arg_is_number(char *av);

#endif