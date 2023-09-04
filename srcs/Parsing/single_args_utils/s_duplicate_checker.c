/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_duplicate_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:56:43 by vsozonof          #+#    #+#             */
/*   Updated: 2023/08/04 18:23:42 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//!-----------------------------------------------------------------------------
//!							--- Duplicates Checker ---
//!-----------------------------------------------------------------------------

//* The duplicate checker function will detect if a duplicate of an integer was
//* passed as arguments.

//!-----------------------------------------------------------------------------

int	s_duplicate_checker(char **stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stash[i])
	{
		while (stash[j])
		{
			if (ft_atoi(stash[i]) == ft_atoi(stash[j]) && (j != i))
				return (pr_error("A duplicate has been detected."));
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
