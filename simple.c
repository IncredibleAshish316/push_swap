/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/27 12:02:32 by anepali           #+#    #+#             */
/*   Updated: 2023/02/27 12:02:32 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It finds the minimum value in the stack.
 * 
 * @param stack the stack that we're working with
 * @param val the index of the node that we want to find the minimum value of
 * 
 * @return The index of the smallest value in the stack.
 */
static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

/**
 * If the first element is the smallest, rotate 
 * the stack until the smallest is in the second position,
 * swap the first two elements, then rotate the stack back 
 * to its original position. If the second
 * element is the smallest, swap the first two elements. 
 * If the third element is the smallest, rotate
 * the stack until the smallest is in the second position, 
 * then swap the first two elements
 * 
 * @param stack_a the stack to be sorted
 * 
 * @return the index of the minimum value in the stack.
 */
static void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
		option1(stack_a);
	else if (head->index == next_min)
		option2(head, stack_a, min);
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}
/**
 * If the stack is sorted, return. If the stack is not sorted,
	rotate the stack until the smallest
 * element is at the top, push the smallest element to the second stack,
	sort the second stack, and
 * push the smallest element back to the first stack
 * 
 * @param stack_a the stack that contains the numbers to be sorted
 * @param stack_b the stack that holds the values that are not sorted
 * 
 * @return the distance between the min value and the top of the stack.
 */

static	void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

/**
 * It sorts a stack of 5 elements.
 * 
 * @param stack_a the stack that needs to be sorted
 * @param stack_b the stack that holds the sorted elements
 * 
 * @return the distance between the min value and the top of the stack.
 */
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/**
* It sorts the stack by calling the appropriate function based 
   on the size of the stack
 * @param stack_a the first stack
 * @param stack_b a pointer to a pointer to a linked list
 * 
 * @return the size of the list.
 */
void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
