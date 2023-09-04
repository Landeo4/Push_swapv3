/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_digits_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:55:19 by vsozonof          #+#    #+#             */
/*   Updated: 2023/08/04 18:30:31 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//!-----------------------------------------------------------------------------
//!						--- Digits and Duplicates Checker ---
//!-----------------------------------------------------------------------------

//* The digits_dupes_checker function will call two other functions to check if:
//*
//? 1. The integer passed as arguments will overflow or not.
//? 2. Any duplicate of an integer are detected.

//!-----------------------------------------------------------------------------

int	s_digits_dupes_checker(char **stash)
{
	if (!s_overflow_checker(stash))
	{
		ft_split_free(stash);
		return (0);
	}
	else if (!s_duplicate_checker(stash))
	{
		ft_split_free(stash);
		return (0);
	}
	return (1);
}

int	s_overflow_checker(char **stash)
{
	int		i;

	i = 0;
	while (stash[i])
	{
		if (!ft_int_overflow_checker(stash[i]))
			return (0);
		else
			i++;
	}
	return (1);
}
