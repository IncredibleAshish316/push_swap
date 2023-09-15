/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/01 12:45:31 by anepali           #+#    #+#             */
/*   Updated: 2023/02/01 12:45:31 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It finds the maximum value in the stack and then finds the number 
 * of bits needed to represent that value
 * 
 * @param stack the stack to be sorted
 * 
 * @return The max_bits is being returned.
 */
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/**
 * It takes a stack, sorts it, and returns a sorted stack
 * 
 * @param stack_a the stack to be sorted
 * @param stack_b a pointer to the head of the stack_b linked list
 */
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		j;
	int		i;
	int		size;
	int		max_bits;

	head_a = (*stack_a);
	i = 0;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize((*stack_b)) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
