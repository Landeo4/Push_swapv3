/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:48:04 by landeo            #+#    #+#             */
/*   Updated: 2023/07/24 17:44:03 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//je fais un test avec le un nouveau opti manager

// cette fonctio nrenvois la pos du nombre du little interessant
int	ft_opti_manager(t_struct *data, int little)
{
	int		nb1;
	int		nb2;
	int		result;

	//ft_printf("je passe par la\n");
	nb1 = ft_trie_500_b_little(data, little);
	nb2 = ft_trie_500_b_biggest(data, little);
	//ft_printf("nb = %d, nb2 = %d\n", nb1, nb2);
	result = ft_checker(data, nb1, nb2, little);
	if (result > 150)
		return (-1);
	return (result);
}

int ft_checker(t_struct *data, int nb, int nb2, int little)
{
	int 		i;
	t_list_b 	*lb;

	lb = data->lb->next;
	i = 0;
	if (nb != -1 && nb2 != -1)
		i = ft_found_best_place500(data, lb, little);
	else if (nb == -1)
		i = ft_found_place_lower(data);
	else if (nb2 == -1)
		i = ft_found_big_lb_500(data);
	//ft_printf("i = %d\n", i);
	return (i);
}

int	ft_found_place_lower(t_struct *data)
{
	int			nb;
	t_list_b	*lb;

	lb = data->lb->next->next;
	nb = data->lb->next->num;
	while (lb->next)
	{
		if (nb > lb->num)
			nb = lb->num;
		lb = lb->next;
	}
	return (nb);
}

/*
**	This function takes as parameter: 
**
**	data
**	little
**
** =====================================================
** =====================================================
**
** ft_opti_manager will help to sort by
** calculate the numbers of actions requiered
** to achieved the sort by using the less possible
*/

/*
int	ft_opti_manager(t_struct *data, int little)
{
	int 		result;
	int			nb;
	int			nb2;
	t_list_b	*lb;

	lb = data->lb->next;
	ft_printf("%d\n", little);
	nb = ft_trie_500_b_little(data, little);
	nb2 = ft_trie_500_b_biggest(data, little);
	result = ft_checker(data, nb, nb2, little);
	if (result > 250)
		return (-1);
	nb = ft_found_best_place500(data, lb, data->la->next->num);
	ft_printf("le nb est de %d\n", nb);
	if (nb > 100)
		return (-1);
	return (0);
}
// cette fonction sert a savoir le nb d'action que la pos a besoin
// et donc si c'est worth
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
*/