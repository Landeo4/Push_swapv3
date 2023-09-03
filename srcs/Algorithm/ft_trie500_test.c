/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie500_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:06:08 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/01 14:42:42 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_trie_manager500(t_struct *data, int chunk)
{
	t_list_a	*la;
	int			*tab;
	int			i;
	int			j;
	int			nb;

	la = data->la->next;
	i = 0;
	j = 50;
	tab = ft_pre_trie(data, chunk);
	while (j > 0)
	{
		nb = tab[i];
		ft_printf("%d\n", nb);
		while (nb >= 0)
		{
			la = la->next;
			nb--;
		}
		ft_printf("====================\n----------\nla %d la->next %d\n", la->num, la->next->num);
		la = sa(la, data);
		j--;
	}
	return (0);
}

int *ft_pre_trie(t_struct *data, int chunk)
{
	int			*tab;
	t_list_a	*la;
	int			i;
	int			j;

	tab = malloc(sizeof(int) * 500);
	j = 0;
	i = 0;
	la = data->la->next;
	while (la->next)
	{
		if (chunk > la->num)
			tab[i] = j++;
		la = la->next;
		i++;
	}
	return (tab);
}

/*
void ft_pre_trie(t_struct *data)
{
	int			cpt;
	t_list_a 	*la;
	int			len;
	int			len2;

	len = ft_len_lista(data);
	la = data->la->next;
	cpt = 0;
	while (len > 2)
	{
		if (la->num < la->next->num)
			cpt++;
		len--;
		la = la->next;
	}
	len = ft_len_lista(data);
	ft_printf("cpt = %d\n", cpt);
	la = data->la->next;
	len2 = len / 2;
	ft_printf("len = %d\n", len2);
	if (cpt > len2)
	{
		while (len > 2)
		{
			//ft_printf("la-num %d, la->next %d\n", la->num, la->next->num);
			if (la->num < la->next->num)
			{
				la = sa(la, data);
				data->la = ra(data);
			}
			data->la = rra(data);
			len--;
		}
	}
	//ft_print_lista(data);
}
*/