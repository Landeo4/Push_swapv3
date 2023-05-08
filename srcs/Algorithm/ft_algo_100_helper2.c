/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_helper2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:17:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/08 22:40:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_100_helper(t_struct *data)
{
	t_list_b	*lb;
	int			num;
	int			i;
	int			pos;

	i = 0;
	pos = ft_found_pos_little(data);
	num = ft_found_little(data);
	lb = data->lb->next;
	while (i < pos)
	{
		i++;
		if (lb->num == num)
			break ;
		lb = lb->next;
	}
	lb = data->lb->next;
	ft_tri_100(lb, data);
}

void	ft_tri_100(t_list_b *lb, t_struct *data)
{
	while (lb)
	{
		ft_100_action(lb, data);
		lb = data->lb->next;
	}
}

void	ft_100_action(t_list_b *tmp, t_struct *data)
{
	int	len;
	int	pos;
	int	num;

	pos = ft_found_pos_little(data);
	num = ft_found_little(data);
	len = ft_len_listb(data);
	len = len / 2;
	if (pos < len)
	{
		while (tmp)
		{
			if (tmp->num == num)
				break ;
			data->lb = rb(data);
			tmp = data->lb->next;
		}
	}
	else
	{
		while (tmp)
		{
			if (tmp->num == num)
				break ;
			data->lb = rrb(data);
			tmp = data->lb->next;
		}
	}
}

int	ft_found_pos_little_100(t_struct *data)
{
	int			i;
	t_list_b	*tab;
	int			nb;

	i = 1;
	tab = data->lb->next;
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

int	ft_found_little_100(t_struct *data)
{
	int			i;
	int			nb;
	t_list_b	*tab;

	i = 1;
	tab = data->lb->next;
	nb = data->lb->next->num;
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
