/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:28:44 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/23 16:14:57 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_500_swap_manager(t_struct *data, int lit1, int lit2)
{
	int			cpt;
	t_list_b	*lb;
	int			len;

	cpt = 0;
	len = ft_len_listb(data);
	lb = data->lb->next;
	if (lit1 != -1 && lit2 != -1)
	{
		cpt = ft_found_best_place500(data, lb);
		ft_take_best_place500(data, cpt);
		data->la = pb(data);
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = sb(data->lb, data);
		return ;
	}
	else if (lit1 == -1)
		ft_500_lit1(lb, data, cpt);
	else if (lit2 == -1)
		ft_500_swap_help(data, len, lb);
}

void	ft_500_lit1(t_list_b *lb, t_struct *data, int cpt)
{
	while (lb->next)
		lb = lb->next;
	cpt = ft_found_lower_b(data);
	if (cpt == lb->num)
	{
		data->la = pb(data);
		return ;
	}
	lb = data->lb->next;
	if (cpt == lb->num && data->la->next->num < cpt)
	{
		data->la = pb(data);
		data->lb = sb(data->lb, data);
		return ;
	}
	ft_take_best_place502(data, cpt);
	data->la = pb(data);
	return ;
}

void	ft_500_swap_help( t_struct *data, int len, t_list_b *lb)
{
	ft_make_best_place_alg500(data, lb);
	data->la = pb(data);
	return ;
	lb = data->lb->next;
	if (len > 4)
	{
		if (data->lb->next->num < data->lb->next->next->num)
		{
			while (lb->next)
				lb = lb->next;
			if (lb->num > data->lb->next->num)
				data->lb = rrb(data);
			else
				data->lb = sb(data->lb, data);
			if (data->lb->next->num < data->lb->next->next->num
				&& data->lb->next->next->num > data->lb->next->next->next->num)
				data->lb = sb(data->lb, data);
		}
	}
	else
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = sb(data->lb, data);
}

void	ft_make_best_place_alg500(t_struct *data, t_list_b *lb)
{
	int			nb;
	int			len;
	int			i;

	i = 0;
	len = ft_len_listb(data);
	nb = data->lb->next->num;
	while (lb)
	{
		if (nb < lb->num)
			nb = lb->num;
		lb = lb->next;
		i++;
	}
	ft_bp_alg500help(len, i, data, nb);
}

void	ft_bp_alg500help(int len, int i, t_struct *data, int nb)
{
	len = len / 2;
	if (i > len)
	{
		len = len * 2;
		while (len > 0)
		{
			if (data->lb->next->num == nb)
				return ;
			data->lb = rrb(data);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			if (data->lb->next->num == nb)
				return ;
			data->lb = rb(data);
			len--;
		}
	}
}
