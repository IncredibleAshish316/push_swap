/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/27 12:02:58 by anepali           #+#    #+#             */
/*   Updated: 2023/02/27 12:02:58 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
* It takes the arguments from the command line and puts them into a linked list
 * 
 * @param stack a pointer to a pointer to a t_list.
 * @param argc number of arguments
 * @param argv the arguments passed to the program
 */
static void	initstack(t_list **stack, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 1;
	args = argv;
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
}

/**
 * It sorts the stack
 * 
 * @param stack_a The stack that needs to be sorted.
 * @param stack_b The stack that will be used to store the sorted values.
 */
static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

/**
 * It checks if the arguments are valid, initializes the stacks, 
 * checks if the stack is already sorted,
 * and if not, sorts it
 * 
 * @param argc the number of arguments passed to the program
 * @param argv the array of strings passed to the program
 * 
 * @return The return value is the exit status of the program.
 */
int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_args(argv);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	initstack(stack_a, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
