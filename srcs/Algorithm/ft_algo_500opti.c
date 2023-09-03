/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500opti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:48:04 by landeo            #+#    #+#             */
/*   Updated: 2023/08/31 10:52:37 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//je fais un test avec le un nouveau opti manager

// cette fonction renvois la pos du nombre du little interessant

int	ft_opti_manager(t_struct *data, int little, t_list_b *lb, int moyenne)
{
	int			result;
	t_list_a	*la;
	(void)little;
	int			i;
	(void)moyenne;

	i = 0;
	la = data->la->next;
	result = -1;
	//ft_printf("je passe par la avec comme little %d\n", little);
	//ft_printf("nb = %d, nb2 = %d\n", nb1, nb2);
	while ((result == -1 || result > 20) && la->next)
	{
		result = ft_checker(data, la->num, lb);
		//ft_printf("nouvelle boucle et la moyenne est de %d\n", moyenne);
		//ft_printf("le result = %d\n", result);
		la = la->next;
		i++;
		//ft_printf("nb de boucle %d\n", i);
	}
	while (i > 1)
	{
		data->la = ra(data);
		i--;
	}
	//ft_printf("result = %d HEEE HOOOOO\n", result);
	return (result);
}

int ft_checker(t_struct *data, int little, t_list_b *lb)
{
	int 		i;
	int			nb1;
	int			nb2;

	nb1 = ft_trie_500_b_little(data, little);
	nb2 = ft_trie_500_b_biggest(data, little);
	lb = data->lb->next;
	i = 0;
	//ft_printf("nb1 = %d et nb2 = %d \nlittle = %d\n", nb1, nb2, little);
	if (nb1 != -1 && nb2 != -1)
		i = ft_found_best_place500(data, lb, little);
	else if (nb1 == -1)
		i = ft_found_lower_b500(data);
	else if (nb2 == -1)
		i = ft_found_big_lb_500_count(data, little);
	//ft_printf("i = %d\n", i);
	return (i);
}

int	ft_found_big_lb_500_count(t_struct *data, int little)
{
	int			i;
	t_list_b	*tab;
	int			len;
	int			len2;

	len2 = 0;
	len = ft_len_lista(data);
	len = len / 2;
	i = len / 5;
	tab = data->lb->next;
	while (len2++ < len && tab->next)
		tab = tab->next;
	while (len2 < (len * 2) && tab->next)
	{
		if (tab->num < little && little > tab->next->num)
			return (i);
		tab = tab->next;
		len2++;
		i++;
	}
	return (-1);
}

int	ft_found_place_lower_new(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;

	i = 0;
	lb = data->lb->next->next;
	while (lb->next)
	{
		if (lb->num > little && little > lb->next->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
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
