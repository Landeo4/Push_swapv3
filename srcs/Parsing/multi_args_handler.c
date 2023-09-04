/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_args_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:30:09 by vsozonof          #+#    #+#             */
/*   Updated: 2023/09/04 07:04:48 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//!-----------------------------------------------------------------------------
//!								--- Multi Args Format ---
//!-----------------------------------------------------------------------------

//* This function will execute multiple function calls that will check if the
//* arguments we received are valid or not.

//! 				⚠️ Arguments Rules ⚠️
//? ➡️ The only allowed characters passed as arguments are :
//? ➡️ Digits (0 - 9) - Minus sign (-)
//? ➡️ The string must either start with a digit or a minus sign.
//? ➡️ The string must end with a digit.
//? ➡️ No duplicates of a number will be tolerated.
//? ➡️ Every numbers must be between INT MAX and INT MIN.

//* If the given arguments respects every rule, the digits will be
//* converted to an integer and will all be sent to our stack A.
//* If the given arguments do not respect the rules, the program will end.

//!-----------------------------------------------------------------------------

int	multi_args_handler(char **stash, t_struct *stacks)
{
	int	i;

	i = 1;
	while (stash[i])
	{
		if (!head_and_end_checker(stash[i]))
			return (pr_error("Argument starts/ends with an invalid character"));
		else
			i++;
	}
	if (!m_str_checker(stash))
		return (0);
	else if (!m_digits_dupes_checker(stash))
		return (0);
	else if (!m_put_to_lst(stash, stacks))
		return (0);
	return (1);
}
