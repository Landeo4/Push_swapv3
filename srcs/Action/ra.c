/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:12:31 by tpotilli          #+#    #+#             */
/*   Updated: 2023/04/26 18:08:32 by tpotilli         ###   ########.fr       */
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
** take the first element on the top of b and put it in top a
** prend le premier element en haut de b et le met en haut de a
**
** Décale d’une position vers le haut tous les élements de la pile a.
** Le premier élément devient le dernier.
*/

void	ra(t_struct *data)
{
	int			i;
	int			recup;
	t_list_a	*tmp;

	i = 0;
	tmp = data->la;
	recup = data->la->next->num;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = data->la;
	ft_freeata(data, 1);
	ft_addata(data, recup, i);
	ft_printf("\nra");
}
