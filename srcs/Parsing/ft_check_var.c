/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:41:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/04/25 16:49:07 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	char **argv
**
** =====================================================
** =====================================================
**
** It will 
*/


bool ft_check_var(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] > argv[i + 1])
			return (0);
		i++;
	}
	return (1);
}
