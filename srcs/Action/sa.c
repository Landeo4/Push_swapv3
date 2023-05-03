/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:26:04 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/04/24 09:39:49 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	t_list_a the name of the struct
**
**	t_list_ba : name of the list a
** =====================================================
** =====================================================
**
** It will swap the first and the second number in the list a
*/

t_list_a	*sa(t_list_a *la)
{
	int			tmp1;
	t_list_a	*first;

	first = la->next;
	tmp1 = first->num;
	first->num = first->next->num;
	first->next->num = tmp1;
	ft_printf("\nsa");
	return (first);
}
