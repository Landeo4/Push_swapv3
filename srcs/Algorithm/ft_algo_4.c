/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:23:21 by tpotilli          #+#    #+#             */
/*   Updated: 2023/04/18 11:53:57 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_4(t_struct *data, int token)
{
	if (token == 1)
		ft_algo_4_1(data);
	else if (token == 2)
		ft_algo_4_2(data);
	else if (token == 3)
		ft_algo_4_3(data);
	else if (token == 4)
		ft_algo_4_4(data);
}

/*
1 2 3 4 good
1 2 4 3 good
1 3 2 4 good
1 3 4 2 good
1 4 2 3 good
1 4 3 2 good
*/

void	ft_algo_4_1(t_struct *data)
{
	pb(data);
	ft_algo_3(data);
	pa(data);
}

void	ft_algo_4_2(t_struct *data)
{
	pb(data);
	ft_algo_3(data);
	pa(data);
	if (data->la->next->num > data->la->next->next->num)
		sa(data->la);
}

void	ft_algo_4_3(t_struct *data)
{
	pb(data);
	ft_algo_3(data);
	pa(data);
	rra(data);
	sa(data->la);
	ra(data);
	ra(data);
}

/*
4 1 2 3 good
4 1 3 2 good
4 2 3 1 good
4 2 1 3 good
4 3 2 1 good
4 3 1 2 good
*/

void	ft_algo_4_4(t_struct *data)
{
	printf("hey");
	pb(data);
	ft_algo_3(data);
	pa(data);
	ra(data);
}
