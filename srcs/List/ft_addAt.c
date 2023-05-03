/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addAt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:20:00 by tpotilli          #+#    #+#             */
/*   Updated: 2023/04/26 18:06:10 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addata(t_struct *data, int nb, int pos)
{
	t_list_a	*prec;
	t_list_a	*cur;
	int			i;
	t_list_a	*cell;

	cell = ft_createcell_a(nb);
	prec = data->la;
	cur = data->la;
	if (data->la == NULL)
	{
		data->la = cell;
		free(cell);
	}
	if (pos == 0)
	{
		cell->next = data->la;
		data->la = cell;
		free(cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
}

void	ft_addatb(t_struct *data, int nb, int pos)
{
	t_list_b	*prec;
	t_list_b	*cur;
	int			i;
	t_list_b	*cell;

	cell = ft_createcell_b(nb);
	prec = data->lb;
	cur = data->lb;
	if (data->lb == NULL)
	{
		data->lb = cell;
		free(cell);
	}
	if (pos == 0)
	{
		cell->next = data->lb;
		data->lb = cell;
		free(cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
}
