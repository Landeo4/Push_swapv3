/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:48:04 by landeo            #+#    #+#             */
/*   Updated: 2023/07/01 14:44:46 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_opti_manager(t_struct *data, int little)
{
	int result;
	int	nb;
	int	nb2;
	t_list_b *lb;

	lb = data->lb->next;
	nb = ft_trie_500_b_little(data, little);
	nb2 = ft_trie_500_b_biggest(data, little);
	result = ft_checker(data, nb, nb2, little);
	if (result > 250)
		return (-1);
	nb = ft_found_best_place500(data, lb, data->la->next->num);
	ft_printf("le nb est de %d\n", nb);
	if (nb > 250)
		return (-1);
	return (0);
}

int ft_checker(t_struct *data, int nb, int nb2, int little)
{
	int 		i;
	t_list_b 	*lb;

	lb = data->lb->next;
	i = 0;
	if (nb != -1 && nb2 != -1)
		i = ft_found_best_place500(data, lb, little);
	else if (nb == -1 || nb2 == -1)
		i = ft_found_place_lower(data);
	return (i);
}

int	ft_found_place_lower(t_struct *data)
{
	int			i;
	t_list_b	*lb;
	int			lit;
	int			big;

	i = 0;
	lb = data->lb->next;
	lit = ft_found_lower_b(data);
	big = ft_found_big_lb_500(data);
	while (lb->next)
	{
		if (lb->num == big && lb->next->num == lit)
			return (i);
		else if (lb->num == lit && lb->next->num == big)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}
