/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:17:46 by tpotilli          #+#    #+#             */
/*   Updated: 2023/05/04 20:00:14 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_manager(t_struct *data, int len)
{
	if (len == 3)
		ft_algo_3(data);
	if (len == 4)
		ft_algo_4_manager(data);
	if (len > 4 && len <= 10)
		ft_algo_10_manager(data);
	if (len > 10 && len <= 100)
		ft_algo_100_manager(data, len);
}

void	ft_algo_4_manager(t_struct *data)
{
	int	token;
	int	n1;
	int	n2;
	int	n3;
	int	n4;

	n1 = data->la->next->num;
	n2 = data->la->next->next->num;
	n3 = data->la->next->next->next->num;
	n4 = data->la->next->next->next->next->num;
	if (n1 < n2 && n1 < n3 && n1 < n4)
		token = 1;
	else if ((n1 > n2 && n1 < n3 && n1 < n4)
		|| (n1 < n2 && n1 < n3 && n1 > n4)
		|| (n1 < n2 && n1 > n3 && n1 < n4))
		token = 2;
	else if (n1 < n2 || n1 < n3 || n1 < n4)
		token = 3;
	else
		token = 4;
	ft_algo_4(data, token);
}

void	ft_algo_10_manager(t_struct *data)
{
	ft_algo_10(data);
}

/*
void ft_algo_5_manager(t_struct *data)
{
	int token;
	int n1;
	int n2;
	int n3;
	int n4;
	int n5;

	n1 = data->la->next->num;
	n2 = data->la->next->next->num;
	n3 = data->la->next->next->next->num;
	n4 = data->la->next->next->next->next->num;
	n5 = data->la->next->next->next->next->next->num;
	token = ft_algo_5_manager_sup(n1, n2, n3, n4, n5);
	ft_algo_5(data, token);
}

int ft_algo_5_manager_sup(int n1, int n2, int n3, int n4, int n5)
{
	int token;
	if (n1 < n2 && n1 < n3 && n1 < n4 && n1 < n5)
		token = 1;
	else if ((n1 > n2 && n1 < n3 && n1 < n4 && n1 < n5) 
			|| (n1 < n2 && n1 < n3 && n1 > n4 && n1 < n5)
			|| (n1 < n2 && n1 > n3 && n1 < n4 && n1 < n5)
			|| (n1 < n2 && n1 < n3 && n1 < n4 && n1 > n5))
		token = 2;
	else if (n1 < n2 || n1 < n3 || n1 < n4)
		token = 3;
	else if (n1 > n2 && n1 > n3 && n1 > n4 && n1 < n5)
		token = 4;
	else
		token = 5;
	return (token);
}

void ft_algo_5(t_struct *data, int token)
{
	if (token == 1)
		ft_algo_5_1(data);
	else if (token == 2)
		ft_algo_5_2(data);
	else if (token == 3)
		ft_algo_5_3(data);
	else if (token == 4)
		ft_algo_5_4(data);
	else if (token == 5)
		ft_algo_5_5(data);
}
*/
