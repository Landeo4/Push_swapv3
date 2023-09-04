/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_put_to_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:23:57 by vsozonof          #+#    #+#             */
/*   Updated: 2023/09/04 07:31:21 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//!-----------------------------------------------------------------------------
//!						-⛓️- Creating Stack A -⛓️-
//!-----------------------------------------------------------------------------

//* This function will convert all the arguments to an integer and place them
//* in the stack A, represented by a linked list.

//!-----------------------------------------------------------------------------

int	m_put_to_lst(char **stash, t_struct *stacks)
{
	int			i;
	t_list_a	*stack_a;

	stack_a = stacks->la;
	i = 1;
	while (stash[i])
	{
		stack_a = ft_add_at_a(stack_a, ft_atoi(stash[i]), i - 1);
		i++;
	}
	stacks->la = stack_a;
	return (1);
}
