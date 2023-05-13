/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:29:41 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/14 00:18:04 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_trie_100(t_struct *data, int little)
{
	t_list_b	*lb;
//	int			i;
	int			lit1;
	int			lit2;

	//i = 1;
	lb = data->lb;
	ft_printf("================on passe a l'algo dans B================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	lit1 = ft_trie_100_b_little(data, little);
	lit2 = ft_trie_100_b_biggest(data, little);
	/*if (lit1 == -1 && lit2 == -1)
		ft_found_best_place100(data, little);*/
	if (lit1 == -1)
		ft_take_b_100(data, lit2, 1);
	else if (lit2 == -1)
		ft_take_b_100(data, lit1, 0);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_little(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre inferieur================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	while (lb)
	{
		if (nb < lb->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

//trouver si il y a des chiffres superieur
int		ft_trie_100_b_biggest(t_struct *data, int little)
{
	t_list_b	*lb;
	int			i;
	int			nb;

	i = 1;
	lb = data->lb->next;
	nb = data->la->next->num;
	ft_printf("================on passe a la partie des chiffre inferieur================\ndata->lb->next = %d et mon little est de -> %d\n", lb->num, little);
	while (lb)
	{
		if (nb > lb->num)
			return (i);
		i++;
		lb = lb->next;
	}
	return (-1);
}

int		ft_take_b_100(t_struct *data, int lit, int token)
{
	t_list_b	*lb;
	(void)lb;

	lb = data->lb->next;
	if (token == 1)
	{
		while (lit > 0)
		{
			rrb(data);
			lit--;
		}
	}
	else if (token == 0)
	{
		while (lit > 0)
		{
			rb(data);
			lit--;
		}
	}
	return (0);
}
