/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:53:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/06 17:41:08 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lista(t_struct *data)
{
	t_list_a	*tmp;

	tmp = data->la;
	while (data->la)
	{
		tmp = data->la->next;
		free(data->la);
		data->la = tmp;
	}
	free(data->la);
}

void	ft_free_listb(t_struct *data)
{
	t_list_b	*tmp;

	tmp = data->lb;
	while (data->lb)
	{
		tmp = data->lb->next;
		free(data->lb);
		data->lb = tmp;
	}
	free(data->lb);
}
