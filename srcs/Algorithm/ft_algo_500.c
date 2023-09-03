/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:27:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/02 08:00:45 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if i loose it all sleep and fall 17 569
void	ft_algo_500_manager(t_struct *data, int argc)
{
	int			moyennech1;
	int			token;
	int			i;
	int			first;
	int			nombre;
	int			len;

	i = 0;
	token = 1;
	first = 0;
	while (ft_len_lista(data) != 0)
	{
		//ft_printf("===============================\n===============================\n===============================\n\n===============================");
		moyennech1 = ft_helper500man(token, moyennech1, data, argc);
		nombre = ft_nb_sup_moyenne(data, moyennech1);
		//ft_trie_manager500(data, moyennech1);
		while (nombre >= 0)
		{
			i++;
			len = ft_len_lista(data);
			first++;
			if (ft_len_lista(data) == 0)
				break;
			if (ft_chunk500(data, moyennech1, first) != -1)
				nombre--;
			//ft_printf("moyenne %d et token %d et nombre %d\n", moyennech1, token, nombre);
			//ft_printf("\n");
			//ft_print_listb(data);
			//ft_printf("\n");
			ft_printf("len %d , nb %d\n", len, nombre);
		}
		if (ft_len_lista(data) == 0)
			break ;
		i = 0;
		token++;
	}
	ft_printf("yoo\n");
	ft_algo500manager_helper2(data);
}

int	ft_chunk500(t_struct *data, int moyenne, int token)
{
	int			littlech1;
	int			littlech2;
	int			compare;
	int			little;
	//t_list_b	*lb;
	(void)token;
	(void)little;
	//int			pos_little;

	//pos_little = 0;
	//ft_printf("ma moyenne est de %d\n", moyenne);
	//lb = data->lb->next;
	//ft_printf("la->num %d\n", data->la->next->num);
	littlech1 = ft_found_pos_little_first_part500(data, moyenne);
	littlech2 = ft_found_pos_little_last_part500(data, moyenne);
	if (littlech1 <= littlech2 && littlech1 != -1)
		compare = 0;
	else
		compare = 1;
	if (compare == 1)
	{
		while (littlech2 > 0)
		{
			rra(data);
			littlech2--;
		}
	}
	else if (compare == 0)
	{
		while (littlech1 > 0)
		{
			ra(data);
			littlech1++;
		}
	}
	data->la = pb(data);
	//ft_printf("little %d, compare %d, \nlittlech1 %d, littlech2 %d,\nmoyenne %d\n", little, compare, littlech1, littlech2, moyenne);
	//ft_printf("%d\n", little);
	//if (token < 3)
	//	return (ft_chunk_helper500(data, compare, little), 0);
	/*if ((compare == 1 && littlech2 >= 80) || (compare == 0 && littlech1 >= 80))
		return (-1);*/
	//ft_printf("token = %d\n", token);
	/*if (token >= 6)
	{
		little = ft_opti_manager(data, little, lb, moyenne);
		littlech1 = ft_trie_500_b_little(data, little);
		littlech2 = ft_trie_500_b_biggest(data, little);
		ft_printf("YOOOOOOOOOO\n");
		ft_500_swap_manager(data, littlech1, littlech2, moyenne);
		return (0);
	}*/
	//ft_printf("little %d\n", little);
	//ft_take_25_algo500(data, compare, little, moyenne);
	return (0);
}


/*
void	ft_algo_500_manager(t_struct *data, int argc)
{
	int			moyennech1;
	int			token;
	int			i;
	int			first;
	int			nombre;

	i = 0;
	token = 1;
	first = 0;
	while (ft_len_lista(data) != 0)
	{
		//ft_printf("===============================\n===============================\n===============================\n\n===============================");
		moyennech1 = ft_helper500man(token, moyennech1, data, argc);
		nombre = ft_nb_sup_moyenne(data, moyennech1);
		ft_trie_manager500(data, moyennech1);
		while (nombre >= 0)
		{
			i++;
			first++;
			if (token == 1 && moyennech1 == -480)
				ft_print_lista(data);
			if (ft_len_lista(data) == 0)
				break;
			if (ft_chunk500(data, moyennech1, first) != -1)
				nombre--;
			ft_printf("moyenne %d et token %d et nombre %d\n", moyennech1, token, nombre);
			//ft_printf("\n");
			//ft_print_listb(data);
			//ft_printf("\n");
		}
		if (ft_len_lista(data) == 0)
			break ;
		i = 0;
		token++;
	}
	ft_algo500manager_helper2(data);
}
*/
int	ft_algo500manager_helper2(t_struct *data)
{
	int	len;

	len = ft_len_listb(data);
	/*if (ft_len_lista(data) != 0)
	{
		ft_printf("HAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
		ft_print_lista(data);
	}*/
	ft_make_list_right100(data, len);
	while (len > 0)
	{
		data->lb = pa(data);
		len--;
	}
	return (0);
}

int	ft_helper500man(int token, int moyennech1, t_struct *data, int argc)
{
	int			len;
	//t_list_a	*la;

	//la = data->la->next;
	len = ft_len_lista(data);
	moyennech1 = ft_somme_algo_500(data, argc, token, len);
	return (moyennech1);
}
//voir cas a 14 853
/*
int	ft_chunk500(t_struct *data, int moyenne, int token)
{
	int			littlech1;
	int			littlech2;
	int			compare;
	int			little;
	//t_list_b	*lb;
	//int			pos_little;

	//pos_little = 0;
	//ft_printf("ma moyenne est de %d\n", moyenne);
	//lb = data->lb->next;
	//ft_printf("la->num %d\n", data->la->next->num);
	littlech1 = ft_found_pos_little_first_part500(data, moyenne);
	littlech2 = ft_found_pos_little_last_part500(data, moyenne);
	if (littlech1 <= littlech2 && littlech1 != -1)
		compare = 0;
	else
		compare = 1;
	if (compare == 1)
		little = ft_found_little_500_75(data, littlech2);
	else if (compare == 0)
		little = ft_found_little_500_25(data, littlech1, moyenne);
	ft_printf("little %d, compare %d, \nlittlech1 %d, littlech2 %d,\nmoyenne %d\n", little, compare, littlech1, littlech2, moyenne);
	//ft_printf("%d\n", little);
	if (token < 3)
		return (ft_chunk_helper500(data, compare, little), 0);
	if ((compare == 1 && littlech2 >= 80) || (compare == 0 && littlech1 >= 80))
		return (-1);
	//ft_printf("token = %d\n", token);
	if (token >= 6)
	{
		little = ft_opti_manager(data, little, lb, moyenne);
		littlech1 = ft_trie_500_b_little(data, little);
		littlech2 = ft_trie_500_b_biggest(data, little);
		ft_printf("YOOOOOOOOOO\n");
		ft_500_swap_manager(data, littlech1, littlech2, moyenne);
		return (0);
	}
	ft_printf("little %d\n", little);
	ft_take_25_algo500(data, compare, little, moyenne);
	return (0);
}*/

int	ft_chunk_helper500(t_struct *data, int compare, int little)
{
	ft_take_first_second_algo500(data, compare, little);
	if (ft_len_listb(data) == 2)
		if (data->lb->next->num < data->lb->next->next->num)
			data->lb = rrb(data);
	return (0);
}
