/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_lista.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:58:16 by tpotilli          #+#    #+#             */
/*   Updated: 2023/07/01 11:35:26 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_lista(t_struct *data)
{
	int			len;
	t_list_a	*lan;

	len = 0;
	lan = data->la->next;
	while (lan)
	{
		len++;
		lan = lan->next;
	}
	return (len);
}

int	ft_len_listb(t_struct *data)
{
	int			len;
	t_list_b	*lan;

	len = 0;
	lan = data->lb->next;
	while (lan)
	{
		len++;
		lan = lan->next;
	}
	return (len);
}
