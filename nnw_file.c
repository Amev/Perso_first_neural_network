/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nnw_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:39:47 by vame              #+#    #+#             */
/*   Updated: 2015/03/06 09:38:48 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neural_network_1.h"

int				open_tng_file(t_data *data)
{
	int			i;
	int			j;
	char		**line;
	char		**read;

	if (!(read = read_file(data->tng)))
		exit(print_error(TNG_ERR));
	i = 0;
	while (read[i])
		i++;
	if (!(data->tng_array = (int **)malloc(sizeof(int *) * i)))
		exit(print_error(MAL_ERR));
	j = 0;
	while (read && read[j++])
	{
		i = 0;
		line = ft_nbrsplit(read[j - 1]);
		if (!(data->tng_array[j - 1] = (int *)malloc(sizeof(int) * (data->tng_mode == 1 ? 31 : 30))))
			exit(print_error(MAL_ERR));
		while (line && line[i++])
			data->tng_array[j - 1][i - 1] = ft_atoi(line[i - 1]);
		if (i != (data->tng_mode == 1 ? 32 : 31) || data->tng_array[j - 1][i - 2] > 9
				|| data->tng_array[j - 1][i - 2] < 0)
			exit(print_error(FMT_ERR));
		ft_strdel_double(&line);
	}
	ft_strdel_double(&read);
	data->tng_nb = j - 1;
	return (1);
}

int				open_nnw_file(t_data *data)
{
	int			i;
	int			j;
	char		**line;
	char		**read;

	data->weight = create_array(30, 10);
	if (!(read = read_file(data->nnw)))
	{
		data->tng_mode = 1;
		return (0);
	}
	j = 0;
	while (read && read[j++])
	{
		i = 0;
		line = ft_nbrsplit_db(read[j - 1]);
		while (line && line[i++])
			data->weight[j - 1][i - 1] = ft_atodb(line[i - 1]);
		if (i != 31)
			exit(print_error(FMT_ERR));
		ft_strdel_double(&line);
	}
	if (j != 11)
		exit(print_error(FMT_ERR));
	ft_strdel_double(&read);
	return (1);
}

int				update_nnw_file(t_data *data)
{
	int			i;
	int			j;
	FILE		*fd;

	j = 0;
	if (!access(data->nnw, F_OK))
		if (remove(data->nnw))
			exit(print_error(RMV_ERR));
	if (!(fd = fopen(data->nnw, "w+")))
		exit(print_error(OPN_ERR));
	while (j < 10)
	{
		i = 0;
		while (i++ < 30)
			fprintf(fd, i == 1 ? "%f" : " %f", data->weight[j][i - 1]);
		fprintf(fd, "\n");
		j++;
	}
	if (fclose(fd))
		exit(print_error(CLS_ERR));
	return (1);
}
