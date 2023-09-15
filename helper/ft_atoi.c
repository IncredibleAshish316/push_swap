/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:36:37 by anepali           #+#    #+#             */
/*   Updated: 2023/03/06 16:00:07 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_whitespace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\t' || c == ' '
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_isdigit(int d)
{
	if (d >= 48 && d <= 57)
		return (1);
	else
	{
		return (0);
	}
}

long	ft_atoi(const char *nptr)
{
	long	j;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	j = 0;
	while (ft_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign = -sign;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0')
	{
		if (ft_isdigit(nptr[i]))
			j = j * 10 + (nptr[i] - '0');
		else
			break ;
		i++;
	}
	return (j * sign);
}
