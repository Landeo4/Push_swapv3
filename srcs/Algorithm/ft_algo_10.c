/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:16:43 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/03 10:25:50 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function takes as parameter: 
**
**	data
**	len
**
** =====================================================
** =====================================================
**
** ft_algo_10 will sort all input under 10 except 3
*/

void	ft_algo_10(t_struct *data)
{
	t_list_a	*la;
	int			num;
	int			i;
	int			pos;

	i = 0;
	pos = ft_found_pos_little(data);
	num = ft_found_little(data);
	la = data->la->next;
	while (i < pos)
	{
		i++;
		if (la->num == num)
			break ;
		la = la->next;
	}
	la = data->la->next;
	ft_tri_10(la, data);
}

void	ft_tri_10(t_list_a *la, t_struct *data)
{
	while (ft_len_lista(data) > 2)
	{
		if (ft_len_lista(data) == 3)
		{
			ft_algo_3(data);
			break ;
		}
		ft_10_action(la, data);
		la = data->la->next;
	}
	while (ft_len_listb(data))
		data->lb = pa(data);
}

int	ft_found_pos_little(t_struct *data)
{
	int			i;
	t_list_a	*tab;
	int			nb;

	i = 1;
	tab = data->la->next;
	nb = ft_found_little(data);
	while (tab)
	{
		if (nb != tab->num)
			tab = tab->next;
		else
			break ;
		i++;
	}
	return (i);
}

int	ft_found_little(t_struct *data)
{
	int			i;
	int			nb;
	t_list_a	*tab;

	i = 0;
	tab = data->la->next;
	nb = data->la->next->num;
	while (tab)
	{
		if (nb > tab->num)
			nb = tab->num;
		tab = tab->next;
		i++;
	}
	return (nb);
}
