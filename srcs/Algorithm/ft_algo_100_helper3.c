/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_helper3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 06:09:33 by landeo            #+#    #+#             */
/*   Updated: 2023/09/02 07:42:46 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_best_place_b_mang(t_struct *data, int little)
{
	int	nb;
	int	j;
	/*int	len;

	len = ft_len_listb(data);
	len = len / 2;*/
	j = ft_trie_100_b_biggest(data, little);
	nb = 1;
	//ft_printf("j = %d\n", j);
	if (j == -1)
		nb = ft_found_pos_big_lb(data);
	else
		nb = ft_found_best_place100(data, data->lb->next, little);
	//ft_printf("nb = %d\n", nb);
	/*if (nb > len)
		nb = nb - len;*/
	return (nb);
}

int	ft_found_pos_big_lb(t_struct *data)
{
	t_list_b	*lb;
	int			nb;
	int			nb2;

	//ft_printf("je passe par la car il est le plus grand\n");
	nb = ft_found_big_lb_100(data);
	lb = data->lb->next;
	nb2 = 1;
	while (lb->next && lb->num != nb)
	{
		nb2++;
		lb = lb->next;
	}
	return (nb2);
}

int	best_place_manager(t_struct *data, int little)
{
	t_list_b	*lb;
	int			token;
	int			nb;

	token = 0;
	lb = data->lb->next;
	while (lb)
	{
		if (little < lb->num)
			token = 1;
		lb = lb->next;
	}
	lb = data->lb->next;
	//ft_printf("token %d\n", token);
	if (token == 1)
		nb = ft_found_best_place500(data, data->lb->next, little);
	else
	{
		nb = ft_found_big_lb_500(data);
		while (lb->num != nb)
			lb = lb->next;
	}
	return (nb);
}

int	ft_verif_lb(t_struct *data)
{
	t_list_b	*lb;
	int			nb;

	lb = data->lb;
	if (data->lb->next->num < data->lb->next->next->num)
	{
		lb = sb(lb, data);
	}
	nb = data->lb->next->num;
	lb = data->lb->next;
	while (lb)
	{
		if (nb < lb->num)
			return (0);
		lb = lb->next;
	}
	return (-1);
}

int	ft_found_big_lb_100(t_struct *data)
{
	int			nb;
	t_list_b	*lb;

	lb = data->lb->next->next;
	nb = data->lb->next->num;
	while (lb)
	{
		if (nb < lb->num)
			nb = lb->num;
		lb = lb->next;
	}
	return (nb);
}
