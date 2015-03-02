/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nnw_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:39:47 by vame              #+#    #+#             */
/*   Updated: 2015/03/02 16:12:47 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neural_network_1.h"

/*
**	revoir les flags d'ouverture
**	revoir le man de access pour vérifier l'existance du chier
**	revoir création de fichier si non existant
*/

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
		line = ft_nbrsplit(read[j - 1]); // faire ft_nbrsplit_db
		while (line && line[i++])
			data->weight[j - 1][i - 1] = ft_atoi(line[i - 1]); // faire ft_atodb
		if (i != 31)
			exit(print_error(FMT_ERR));
	}
	if (j != 11)
		exit(print_error(FMT_ERR));
	return (1);
}
