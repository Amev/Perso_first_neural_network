/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:39:31 by vame              #+#    #+#             */
/*   Updated: 2015/03/06 09:55:29 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "neural_network_1.h"

int				calcul(int j, int k, t_data *data)
{
	float		result;
	int			i;

	i = 0;
	result = 0;
	while (i++ < 30)
		if (data->tng_array[j][i - 1] == 1)
			result += data->weight[k][i - 1];
	return (result > 0 ? 1 : 0);
}

void			weight_init(t_data *data)
{
	int 		i;
	int 		j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 30)
			data->weight[j][i++] = (float)(rand() % 100 - 50);
		j++;
	}
}

float			weight_calc(float value, int wanted_v, int out_v, int in_v)
{
	return (value + (wanted_v - out_v) * in_v * 10);
}
