/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500_helper3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 06:09:33 by landeo            #+#    #+#             */
/*   Updated: 2023/09/01 01:46:25 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	ft_best_place_b_mang500(t_struct *data, int little)
{
	int	nb;
	int	j;
	int	len;

	len = ft_len_listb(data);
	len = len / 2;
	j = ft_trie_500_b_biggest(data, little);
	nb = 1;
	//ft_printf("j = %d\n", j);
	if (j == -1)
		nb = ft_found_pos_big_lb500(data);
	else
		nb = ft_found_best_place500(data, data->lb->next, little);
	//ft_printf("nb = %d\n", nb);
	if (nb > len)
		nb = nb - len;
	return (nb);
}
*/

int	ft_best_place_b_mang500(t_struct *data, int little)
{
	int			lit1;
	int			lit2;
	int			i;
	t_list_b 	*lb;

	lb = data->lb->next;
	lit1 = ft_trie_500_b_little(data, little);
	lit2 = ft_trie_500_b_biggest(data, little);
	//ft_printf("mon lit1 %d mon lit2 %d\n", lit1, lit2);
	if (lit1 != -1 && lit2 != -1)
		lit2 = ft_found_best_place500(data, lb, little);
	else if (lit1 == -1 )
		lit2 = ft_found_lower_b500(data);
	else if (lit2 == -1)
	{
		i = 0;
		lit1 = ft_len_listb(data);
		lit2 = ft_found_big_lb_500(data);
		while (lb->num != lit2)
		{
			lb = lb->next;
			i++;
		}
	}
	//ft_printf("mon resultat est %d\n", lit2);
	return (lit2);
}

int	ft_found_pos_big_lb500(t_struct *data)
{
	t_list_b	*lb;
	int			nb;
	int			nb2;

	//ft_printf("je passe par la car il est le plus grand\n");
	nb = ft_found_big_lb_500(data);
	lb = data->lb->next;
	nb2 = 1;
	while (lb->next && lb->num != nb)
	{
		nb2++;
		lb = lb->next;
	}
	return (nb2);
}

int	best_place_manager500(t_struct *data, int little)
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

int	ft_verif_lb500(t_struct *data)
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

int	ft_found_big_lb_500(t_struct *data)
{
	int			nb;
	t_list_b	*lb;

	lb = data->lb->next->next;
	nb = data->lb->next->num;
	while (lb->next)
	{
		if (nb < lb->num)
			nb = lb->num;
		lb = lb->next;
		//ft_printf("mon nombre a %d\n", nb);
	}
	if (lb->num > nb)
		nb = lb->num;
	//ft_printf("mon nombre a %d\n", nb);
	return (nb);
}
