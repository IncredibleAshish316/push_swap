/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/01 14:51:46 by anepali           #+#    #+#             */
/*   Updated: 2023/02/01 14:51:46 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It checks if the number is already in the array
 * 
 * @param num the number to check for
 * @param argv the array of strings passed to the program
 * @param i the index of the current number in the array
 * 
 * @return 1 if the number is found in the array, and 0 if it is not.
 */
static int	ft_chkduplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * This function checks the arguments passed to the program 
 * to make sure they are valid
 * @param argc number of arguments
 * @param argv the array of arguments passed to the program
 */
void	ft_check_args(char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 1;
	args = argv;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (ft_chkduplicate(tmp, args, i))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
}
