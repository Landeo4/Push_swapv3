/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:27:25 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/29 18:41:47 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_500_manager(t_struct *data, int argc)
{
	int			moyennech1;
	int			token;
	int			i;
	int			first;

	i = 0;
	token = 1;
	first = 0;
	while (token != 13)
	{
		moyennech1 = ft_helper500man(token, moyennech1, data, argc);
		while (i < 45)
		{
			i++;
			ft_chunk(data, moyennech1, first);
			first++;
			//ft_print_listb(data);
			if (ft_len_lista(data) == 0)
				break ;
		}
		i = 0;
		token++;
	}
	ft_algo100manager_helper2(data);
}

int	ft_helper500man(int token, int moyennech1, t_struct *data, int argc)
{
	int			len;
	t_list_a	*la;

	la = data->la->next;
	len = ft_len_lista(data);
	moyennech1 = ft_somme_algo_500(la, argc, token, len);
	return (moyennech1);
}

int	ft_somme_algo_500(t_list_a *la, int argc, int token, int len)
{
	int			chiffre;
	double		last;

	if (token == 12)
	{
		chiffre = 2147483647;
		return (chiffre);
	}
	last = token * 0.09;
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
