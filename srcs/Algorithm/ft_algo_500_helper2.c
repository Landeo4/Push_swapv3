/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500_helper2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:17:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/02 07:55:39 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_somme_algo_500(t_struct *data, int argc, int token, int len)
{
	int				chiffre;
	//double		last;
	t_list_a		*la;

	la = data->la->next;
	ft_printf("token %d\n", token);
	if (token >= 12)
	{
		chiffre = 2147483647;
		return (chiffre);
	}
	//last = token * 2;
	chiffre = ft_somme_500helper(len, argc, la, data);
	chiffre = chiffre * token;
	chiffre = chiffre / 2;
	ft_printf("la moyenne est de %d et mon token est de %d\n", chiffre, token);
	if (token < 4)
		chiffre = ft_negative(data, argc);
	return (chiffre);
}

int ft_negative(t_struct *data, int argc)
{
	static int	chiffre;
	int			len;
	t_list_a	*la;

	len = ft_len_lista(data);
	la = data->la->next;
	chiffre = 0;
	while (len > 0 && la)
	{
		if (la->num < 0)
			chiffre = chiffre + la->num;
		la = la->next;
		len--;
	}
	chiffre = chiffre / argc;
	chiffre = chiffre * 2;
	return (chiffre);
}

int	ft_somme_500helper(int len, int argc, t_list_a *la, t_struct *data)
{
	static int	chiffre;
	(void)data;

	chiffre = 0;
	//ft_print_lista(data);
	while (len > 0 && la)
	{
		chiffre = chiffre + la->num;
		la = la->next;
		len--;
	}
	chiffre = chiffre / argc;
	//chiffre = chiffre * 2;
	return (chiffre);
}

void	ft_take_25_algo500(t_struct *data, int compare, int little, int chunk)
{
	int		nb;
	int		len;
	(void)chunk;
	(void)nb;
	len = ft_len_listb(data);
	len = len / 2;
	//nb = best_place_manager(data, little);
	//ft_printf("nb %d, little %d, len %d, nb2 %d\n", nb, little, len);
	ft_take_25_helper500(data, little, compare);
	//lit1 = ft_trie_500_b_little(data, little);
	//lit2 = ft_trie_500_b_biggest(data, little);
	data->la = pb(data);
	//ft_printf("checkpoint la placer\n");
	//ft_printf("%d dasdasdasd\n", data->la->next->num);
	//ft_500_swap_manager(data, lit1, lit2, chunk);
}

/*void	ft_take_25_algo500(t_struct *data, int compare, int little, int chunk)
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
	ft_printf("%d dasdasdasd\n", data->la->next->num);
	ft_500_swap_manager(data, lit1, lit2, chunk);
}*/

void	ft_take_25_helper500(t_struct *data, int little, int compare)
{
	int	nb2;
	int	len;
	(void)nb2;
	len = ft_len_listb(data);
	len = len / 2;
	//nb2 = ft_best_place_b_mang500(data, little);
	//ft_printf("nb2 = %d\n", nb2);
	if (compare == 1)
	{
		while (data->la->next->num != little)
		{
			data->la = rra(data);
			//nb--;
		}
		return ;
	}
	else
	while (data->la->next->num != little)
	{
		data->la = ra(data);
	//	nb++;
	}
}

/*
int	ft_check_nb2(t_struct *data, int little, int nb2)
{
	
}
*/

int ft_nb_sup_moyenne(t_struct *data, int moyennech1)
{
	t_list_a	*la;
	int			nb;

	nb = 0;
	la = data->la->next;
	while (la->next)
	{
		if (la->num < moyennech1)
			nb++;
		la = la->next;
	}
	return (nb);
}