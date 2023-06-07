/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:16:43 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/07 15:09:32 by landeo           ###   ########.fr       */
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
	while (la)
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

void	ft_10_action(t_list_a *tmp, t_struct *data)
{
	int	len;
	int	pos;
	int	num;

	pos = ft_found_pos_little(data);
	num = ft_found_little(data);
	len = ft_len_lista(data);
	len = len / 2;
	if (pos < len)
	{
		while (tmp)
		{
			if (tmp->num == num)
				break ;
			data->la = ra(data);
			tmp = data->la->next;
		}
		data->la = pb(data);
	}
	else
	{
		while (tmp)
		{
			if (tmp->num == num)
				break ;
			data->la = rra(data);
			tmp = data->la->next;
		}
		data->la = pb(data);
	}
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

	i = 1;
	tab = data->la->next;
	nb = data->la->next->num;
	while (tab)
	{
		if (nb > tab->num)
			nb = tab->num;
		tab = tab->next;
		i++;
		if (i > 10)
			break ;
	}
	return (nb);
}
