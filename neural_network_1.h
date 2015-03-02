#ifndef NEURAL_NETWORK_1
# define NEURAL_NETWORK_1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAL_ERR 1

typedef struct 		s_data
{
	int				fd;
	int				tng_mode;
	char			*nnw;
	char			*tng;
	float			**weight;
}					t_data;

/*
**	fonctions de gestion des poids
*/

float				weight_init(float **weight);

/*
**	fonctions du menu
*/

int					menu(t_data *data);

/*
**	fonctions de gestion du fichier .nnw
*/

int					open_nnw_file(t_data *data);

/*
**	outils pour les fichiers
*/

float				**create_array(int x, int y);
char				**join_line(char **line, char ***read);
char				**read_file(int fd);

#endif