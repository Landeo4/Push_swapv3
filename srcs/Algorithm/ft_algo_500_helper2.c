/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500_helper2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:17:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/03 11:22:34 by ceatgie          ###   ########.fr       */
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

int	ft_negative(t_struct *data, int argc)
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

/*
int	ft_check_nb2(t_struct *data, int little, int nb2)
{
	
}
*/

int	ft_nb_sup_moyenne(t_struct *data, int moyennech1)
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
