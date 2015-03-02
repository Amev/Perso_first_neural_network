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
		line = ft_nbrsplit_db(read[j - 1]);
		while (line && line[i++])
			data->weight[j - 1][i - 1] = ft_atodb(line[i - 1]);
		if (i != 31)
			exit(print_error(FMT_ERR));
	}
	if (j != 11)
		exit(print_error(FMT_ERR));
	return (1);
}