/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:38:50 by vame              #+#    #+#             */
/*   Updated: 2015/03/04 17:05:01 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neural_network_1.h"

void			print_tab(int *tab)
{
	int			i;
	int			j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		printf("\t");
		while (j++ < 5)
			printf(j == 1 ? "%d" : " %d", tab[5 * i + j - 1]);
		printf("\n");
		i++;
	}
}

void			learn(t_data *data, int j, int k, int res)
{
	int			i;
	int			in_v;
	int			out_v;
	float		value;
	int			wanted_v;

	i = 0;
	out_v = res;
	wanted_v = k == data->tng_array[j][30] ? 1 : 0;
	while (i++ < 30)
	{
		in_v = data->tng_array[j][i];
		value = data->weight[k][i - 1];
		data->weight[k][i - 1] = weight_calc(value, wanted_v, out_v, in_v);
	}
}

void			work(t_data *data)
{
	int			j;
	int			k;
	int			res[3];

	j = 0;
	while (j < data->tng_nb)
	{
		k = 0;
		res[1] = 0;
		printf("----------------------\n");
		print_tab(data->tng_array[j]);
		while (k < 10)
		{
			res[0] = calcul(j, k, data);
			if (data->tng_mode == 1)
				learn(data, j, k, res);
			if (res[0] == 1)
			{
				res[2] = k;
				res[1] += 1;
			}
			k++;
		}
		if (res[1] == 1)
			printf("------ Res = %d. ------\n", res[2]);
		else
			printf("-- No or many result --\n");
		free(data->tng_array[j]);
		data->tng_array[j] = NULL;
		j++;
	}
	free(data->tng_array);
	data->tng_array = NULL;
}