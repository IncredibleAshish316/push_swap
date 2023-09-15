/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortinglist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:54:31 by anepali           #+#    #+#             */
/*   Updated: 2023/03/06 14:28:22 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	option1(t_list **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

void	option2(t_list *head, t_list **stack_a, int min)
{
	if (head->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}
