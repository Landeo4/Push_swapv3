/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:22:38 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/03 10:24:56 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_3(t_struct *data)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = data->la->next->num;
	num2 = data->la->next->next->num;
	num3 = data->la->next->next->next->num;
	if (num1 > num2 && num2 < num3 && num1 > num3)
		data->la = ra(data);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{	
		data->la = rra(data);
		data->la = sa(data->la, data);
	}
	else if (num1 > num2 && num2 < num3 && num1 > num3)
	{
		data->la = sa(data->la, data);
		data->la = rra(data);
	}
	else
		ft_algo_3sup(data, num1, num2, num3);
}

void	ft_algo_3sup(t_struct *data, int num1, int num2, int num3)
{
	if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		data->la = ra(data);
		data->la = sa(data->la, data);
	}
	else if (num1 < num2 && num2 > num3 && num3 < num1)
		data->la = rra(data);
	else if (num1 > num2 && num2 < num3 && num3 > num1)
		data->la = sa(data->la, data);
}
