/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:08:56 by anepali           #+#    #+#             */
/*   Updated: 2023/02/01 15:08:56 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It finds the next minimum value in the stack
 * 
 * @param stack the stack to be sorted
 * 
 * @return The next minimum value in the stack.
 */
static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

/**
 * It takes a stack and assigns each element an index value, starting at 0
 * 
 * @param stack the stack to index
 */
void	index_stack(t_list **stack)
{
	t_list	*head;
	int		i;

	i = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = i++;
		head = get_next_min(stack);
	}
}
