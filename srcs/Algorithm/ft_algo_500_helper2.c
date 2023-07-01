/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500_helper2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:17:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/07/01 11:33:21 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_somme_algo_500(t_list_a *la, int argc, int token, int len)
{
	static	int	chiffre;
	double		last;

	if (token == 12)
	{
		chiffre = 2147483647;
		return (chiffre);
	}
	last = token * 0.2;
	chiffre = 0;
	chiffre = ft_somme_500helper(len, argc, la, token);
	chiffre = chiffre * last;
	return (chiffre);
}

int	ft_somme_500helper(int len, int argc, t_list_a *la, int token)
{
	static int	chiffre;

	if (token > 1)
	{
		return (chiffre);
	}
	chiffre = 0;
	while (len > 0 && la)
	{
		chiffre = chiffre + la->num;
		la = la->next;
		len--;
	}
	chiffre = chiffre / argc;
	chiffre = chiffre * 2;
	return (chiffre);
}

void	ft_take_25_algo500(t_struct *data, int compare, int little, int chunk)
{
	int		lit1;
	int		lit2;
	int		nb;
	int		len;

	len = ft_len_listb(data);
	len = len / 2;
	nb = best_place_manager(data, little);
	//ft_printf("nb %d, little %d, len %d, nb2 %d\n", nb, little, len);
	if (ft_len_lista(data) == 1)
		lit1 = 0;
	ft_take_25_helper500(data, little, nb, compare);
	lit1 = ft_trie_500_b_little(data, little);
	lit2 = ft_trie_500_b_biggest(data, little);
	//ft_printf("checkpoint la placer\n");
	ft_500_swap_manager(data, lit1, lit2, chunk);
}

void	ft_take_25_helper500(t_struct *data, int little, int nb, int compare)
{
	int	nb2;
	int	len;

	len = ft_len_listb(data);
	nb2 = ft_best_place_b_mang500(data, little);
	if (compare == 1)
	{
		while (data->la->next->num != little)
		{
			if (nb > 0 && nb2++ < ft_len_listb(data) && nb2 > len)
				data = rrr(data);
			else
				data->la = rra(data);
			nb--;
		}
		return ;
	}
	while (data->la->next->num != little)
	{
		if (nb > 0 && nb2++ < ft_len_listb(data))
			data = rr(data);
		else
			data->la = ra(data);
		nb--;
	}
}
