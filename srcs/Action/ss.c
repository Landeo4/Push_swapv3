/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:29:56 by tpotilli          #+#    #+#             */
/*   Updated: 2023/04/24 09:41:15 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	t_list_a the name of the struct
**	t_list_b the name of the second struct
**
**	t_list_ba : name of the list a
**	t_list_bb : name of the list a
** =====================================================
** =====================================================
**
** It will do sa and sb at the same time
*/

void	ss(t_struct *data)
{
	t_list_a	*a;
	t_list_b	*b;

	sa(a);
	sb(b);
	ft_printf("\nss");
}
