/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_args_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:30:06 by vsozonof          #+#    #+#             */
/*   Updated: 2023/09/04 07:04:34 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//!-----------------------------------------------------------------------------
//!								--- Single Args Format ---
//!-----------------------------------------------------------------------------

//* This function will execute multiple function calls that will check if the
//* arguments we received are valid or not.

//! 				⚠️ Arguments Rules ⚠️
//? ➡️ The only allowed characters passed as arguments are :
//? ➡️ Digits (0 - 9) - Whitespaces ( ) - Minus sign (-)
//? ➡️ The string must either start with a digit or a minus sign.
//? ➡️ Every digits must be separed with a single whitespace.
//? ➡️ No duplicates of a number will be tolerated.
//? ➡️ Every numbers must be between INT MAX and INT MIN.

//* If the given arguments respects every rule, the digits will be
//* converted to an integer and will all be sent to our stack A.
//* If the given arguments do not respect the rules, the program will end.

//!-----------------------------------------------------------------------------

int	single_args_handler(char *str, t_struct *stacks)
{
	char	**stash;

	stash = ft_split(str, ' ');
	if (!s_charset_checker(str))
		return (ft_split_free(stash));
	else if (!head_and_end_checker(str))
		return (ft_split_free(stash));
	else if (!s_str_checker(str))
		return (ft_split_free(stash));
	else if (!s_digits_dupes_checker(stash))
		return (0);
	else if (!s_put_to_lst(stash, stacks))
		return (0);
	ft_split_free(stash);
	return (1);
}
