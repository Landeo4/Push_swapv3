/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo500helper4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:19 by tpotilli          #+#    #+#             */
/*   Updated: 2023/08/31 10:36:54 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_500_swap_manager(t_struct *data, int lit1, int lit2, int chunk)
{
	int			cpt;
	t_list_b	*lb;

	cpt = 0;
	lb = data->lb->next;
	//ft_printf("lit1 %d lit2 %d , little %d\n", lit1, lit2, data->la->next->num);
	if (lit1 != -1 && lit2 != -1)
	{
		ft_trie_500_manager(data, chunk, 1);
		data->la = pb(data);
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = sb(data->lb, data);
		return ;
	}
	else if (lit1 == -1)
		ft_500_lit1(lb, data, cpt);
	else if (lit2 == -1)
		ft_500_swap_help(data, lb);
}

void	ft_500_lit1(t_list_b *lb, t_struct *data, int cpt)
{
	while (lb->next)
		lb = lb->next;
	cpt = ft_found_lower_b500(data);
	//ft_printf("cpt %d\n", cpt);
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

void	ft_500_swap_help(t_struct *data, t_list_b *lb)
{
	ft_make_best_place_alg500(data, lb);
	data->la = pb(data);
	return ;
}

void	ft_make_best_place_alg500(t_struct *data, t_list_b *lb)
{
	int			nb;
	int			len;
	int			i;

	i = 0;
	len = ft_len_listb(data);
	nb = ft_found_big_lb_500(data);
	while (lb->num != nb)
	{
		lb = lb->next;
		i++;
	}
	if (i == len)
		return ;
	ft_bp_alg500help(len, i, data, nb);
}

void	ft_bp_alg500help(int len, int i, t_struct *data, int nb)
{
	(void)nb;
	len = len / 2;
	//ft_printf("len %d i %i\n", len, i);
	if (i > len)
	{
		len = ft_len_listb(data);
		while (len > 0)
		{
			if (data->lb->next->num == nb)
				return ;
			data->lb = rrb(data);
			len++;
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
