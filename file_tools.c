/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 15:40:08 by vame              #+#    #+#             */
/*   Updated: 2015/03/04 16:51:54 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neural_network_1.h"

float			**create_array(int x, int y)
{
	int			i;
	float		**new;

	if (!(new = (float **)malloc(sizeof(float *) * y)))
		exit(print_error(MAL_ERR));
	i = 0;
	while (i < y)
		if (!(new[i++] = (float *)malloc(sizeof(float) * x)))
			exit(print_error(MAL_ERR));
	return (new);
}

char			**join_line(char **line, char ***read)
{
	int			i;
	int			len;
	char		**new;

	i = 0;
	len = 0;
	while (*read && (*read)[len])
		len++;
	if (!(new = (char **)malloc(sizeof(char *) * (len + 2))))
		exit(print_error(MAL_ERR));
	new[len + 1] = NULL;
	while (i++ < len)
		new[i - 1] = (*read)[i - 1];
	new[len] = *line;
	if (*read)
		free(*read);
	return (new);
}

char			**read_file(char *path)
{
	int			fd;
	int			res;
	char		*tmp;
	char		*line;
	char		**read;

	tmp = NULL;
	read = NULL;
	if (path[0] != '.')
	{
		if (path[0] != '/' && !(tmp = ft_strjoin("./", path)))
			exit(print_error(MAL_ERR));
		if (path[0] == '/' && !(tmp = ft_strjoin("/", path)))
			exit(print_error(MAL_ERR));
		path = tmp;
	}
	if (access(path, F_OK))
		return (NULL);
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(print_error(OPN_ERR));
	while ((res = get_next_line_2(fd, &line)) == 1)
		read = join_line(&line, &read);
	if (res == -1)
		exit(print_error(GNL_ERR));
	if (close(fd) == -1)
		exit(print_error(CLS_ERR));
	if (tmp)
		ft_strdel(&tmp);
	return (read);
}
