/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:29:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/04/24 09:39:13 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	t_list_b the name of the struct
**
**	t_list_b : name of the list b
** =====================================================
** =====================================================
**
** It will swap the first and the second number in the list b
*/

t_list_b	*sb(t_list_b *lb)
{
	int			tmp1;
	t_list_b	*first;

	first = lb->next;
	tmp1 = first->num;
	first->num = first->next->num;
	first->next->num = tmp1;
	ft_printf("\nsb");
	return (first);
}
