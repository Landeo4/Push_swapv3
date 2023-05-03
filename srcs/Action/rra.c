/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:03:36 by tpotilli          #+#    #+#             */
/*   Updated: 2023/04/26 18:08:43 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	t_list_a the name of the struct
**
**	la : name of the list a
** =====================================================
** =====================================================
**
** every element of a will go down
** the first become the last
*/

void	rra(t_struct *data)
{
	t_list_a	*tmp;
	int			i;
	int			recup;

	tmp = data->la->next;
	i = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	recup = tmp->num;
	tmp = data->la;
	ft_freeata(data, i);
	ft_addata(data, recup, 1);
	ft_printf("\nrra");
}
