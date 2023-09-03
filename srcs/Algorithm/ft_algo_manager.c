/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotillion <tpotillion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:17:46 by tpotilli          #+#    #+#             */
/*   Updated: 2023/09/02 07:32:19 by tpotillion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_manager(t_struct *data, int len)
{
	if (len == 3)
		ft_algo_3(data);
	if (len > 3 && len <= 10)
		ft_algo_10_manager(data);
	if (len > 10 && len <= 100)
		ft_algo_100_manager(data, len);
	if (len > 100 && len <= 500)
		ft_algo_500_manager(data, len);
	/*ft_printf("%d\n", data->la->next->num);
	ft_printf("%d  %d  %d %d\n", la->num, la->next->num, la->next->next->num, la->next->next->next->num);
	la = sa(la, data);
	ft_printf("%d  %d  %d %d\n", la->num, la->next->num, la->next->next->num, la->next->next->next->num);
	la = sa(la, data);
	ft_printf("%d  %d  %d %d\n", la->num, la->next->num, la->next->next->num, la->next->next->next->num);
	la = sa(la, data);
	ft_printf("%d  %d  %d %d\n\n", la->num, la->next->num, la->next->next->num, la->next->next->next->num);
*/}

void	ft_algo_10_manager(t_struct *data)
{
	ft_algo_10(data);
}
