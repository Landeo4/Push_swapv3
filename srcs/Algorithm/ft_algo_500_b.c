/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:28:28 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/18 17:49:49 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_best_place500(t_struct *data, t_list_b *lb)
{
	int			nb;
	int			cpt;

	nb = data->la->next->num;
	cpt = 1;
	lb = data->lb->next;
	while (lb && lb->next)
	{
		if (lb->num > nb && nb > lb->next->num)
			return (cpt);
		cpt++;
		lb = lb->next;
	}
	return (-1);
}

int	ft_take_best_place500(t_struct *data, int cpt)
{
	int			len;

	len = ft_len_listb(data);
	len = len / 2;
	if (cpt == len)
	{
		while (len > 0)
		{
			len--;
			data->lb = rb(data);
		}
		return (0);
	}
	ft_best_place_helper500(cpt, len, data);
	return (0);
}

void	ft_best_place_helper500(int cpt, int len, t_struct *data)
{
	if (cpt > len)
	{
		len = ft_len_listb(data);
		while (len > cpt)
		{
			data->lb = rrb(data);
			cpt++;
		}
	}
	else if (cpt < len)
	{
		while (cpt > 0)
		{
			data->lb = rb(data);
			cpt--;
		}
	}
}

void	ft_take_best_place502(t_struct *data, int nb)
{
	int			len;
	t_list_b	*lb;
	int			i;
	int			len2;

	i = 1;
	lb = data->lb->next;
	len2 = ft_len_listb(data);
	len = ft_len_listb(data);
	len = len / 2;
	if (len * 2 != len2)
		len++;
	while (lb->num != nb)
	{
		i++;
		lb = lb->next;
	}
	lb = data->lb->next;
	if (i == 0)
		data->lb = rb(data);
	else
		ft_best_place_502_helper(i, len, data);
}

void	ft_best_place_502_helper(int i, int len, t_struct *data)
{
	if (i == len)
	{
		len = ft_len_listb(data);
		while (i > 0)
		{
			data->lb = rb(data);
			i--;
		}
	}
	else if (i > len)
	{
		len = ft_len_listb(data);
		if (i == len)
		{
			data->lb = rrb(data);
			return ;
		}
		while (i++ < len)
			data->lb = rrb(data);
	}
	else if (i < len)
	{
		while (i++ < len)
			data->lb = rb(data);
	}
}
