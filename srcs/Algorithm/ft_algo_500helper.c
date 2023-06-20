/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:27:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/18 17:49:09 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_take_first_second_algo500(t_struct *data, int compare, int little)
{
	if (compare == 1)
	{
		while (data->la->next->num != little)
			data->la = rra(data);
		data->la = pb(data);
	}
	else if (compare == 0)
	{
		while (data->la->next->num != little)
			data->la = ra(data);
		data->la = pb(data);
	}
}

void	ft_make_list_right500(t_struct *data, int len)
{
	int		big;
	int		i;

	big = ft_found_big_lb_100(data);
	i = ft_trie_500_b_biggest(data, big);
	len = ft_len_listb(data);
	len = len / 2;
	if (i > len)
	{
		len = ft_len_listb(data);
		while (i < len)
		{
			data->lb = rrb(data);
			i++;
		}
	}
	else if (i < len)
	{
		while (i < len)
		{
			data->lb = rb(data);
			i++;
		}
	}
}

int	ft_trie_500_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;

	i = 0;
	lb = data->lb->next;
	while (lb)
	{
		if (little <= lb->num)
			return (i);
		lb = lb->next;
		i++;
	}
	return (-1);
}

int	ft_trie_500_b_little(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;

	i = 0;
	lb = data->lb->next;
	while (lb)
	{
		if (little >= lb->num)
			return (i);
		lb = lb->next;
		i++;
	}
	return (-1);
}

int	ft_found_lower_b500(t_struct *data)
{
	t_list_b	*lb;
	int			nb;

	lb = data->lb->next;
	nb = data->lb->next->num;
	while (lb && lb->next)
	{
		if (nb > lb->num)
			nb = lb->num;
		lb = lb->next;
	}
	if (lb->num < nb)
		nb = lb->num;
	return (nb);
}
