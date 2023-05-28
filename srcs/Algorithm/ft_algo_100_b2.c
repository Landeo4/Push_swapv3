/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:19 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/28 16:04:42 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_100_swap_manager(t_struct *data, int lit1, int lit2)
{
	int			i;
	t_list_b	*lb;

	i = 0;
	lb = data->lb->next;
	ft_printf("salut je passe par le swap manager et mes lit sont lit1 %s, lit2 %s\n", lit1, lit2);
	if (lit1 == -1 && lit2 == -1)
	{
		i = ft_found_best_place100(data, lb);
		ft_take_best_place100(data, i);
		data->la = pb(data);
	}
	if (lit1 == -1) // s'il y aucune occurence inferieur
	{
		data->la = pb(data);
	}
	else if (lit2 == -1) // s'il y aucune occurence superieur
	{
		data->la = pb(data);
		data->lb = rrb(data);
	}
}


//void	ft_take100(t_struct *data, int token)