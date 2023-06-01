/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:29:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/01 16:06:49 by tpotilli         ###   ########.fr       */
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

t_list_b	*sb(t_list_b *lb, t_struct *data)
{
	int			tmp1;
	t_list_b	*first;
	int			tmp2;
	(void)data;
	(void)tmp1;

	first = lb;
	tmp2 = first->next->num;
	tmp1 = first->num;
	data->lb = ft_freeatb(data, 1);
	data->lb = ft_addatb(data, tmp2, 1);
	data->lb = ft_freeatb(data, 2);
	data->lb = ft_addatb(data, tmp1, 2);
	ft_printf("sb\n");
	ft_printf("voici a quoi ressemble mes valeurs %i %i\n", first->num, first->next->num);
	return (first);
}
