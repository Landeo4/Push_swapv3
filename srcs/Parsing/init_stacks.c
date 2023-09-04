/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:35:11 by vsozonof          #+#    #+#             */
/*   Updated: 2023/09/04 07:16:28 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//!-----------------------------------------------------------------------------
//!							--- Stacks Initialization ---
//!-----------------------------------------------------------------------------

//* This function will simply initialize our stacks A and B so we can use
//* them once the arguments verification is done.

//!-----------------------------------------------------------------------------

void	init_stacks(t_struct *stacks)
{
	stacks->la = NULL;
	stacks->lb = NULL;
}
