/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:45:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/06/29 15:45:19 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pour swap deux int

int		*ft_swap(int *a, int ind1, int ind2)
{
	int tmp;

	tmp = a[ind1];
	a[ind1] = a[ind2];
	a[ind2] = tmp;
	//ft_printf("\nswap = %d et swap+1 = %d", a[ind1], a[ind2]);
	return (a);
}
