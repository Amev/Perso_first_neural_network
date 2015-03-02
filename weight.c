 #include "neural_network_1.h"

void			weight_init(float ***weight)
{
	int 		i;
	int 		j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 30)
			(*weight)[i++][j] = (float)(rand()%100 - 50);
		j++;
	}
}

float			weight_calc(float value, int wanted_v, int out_v, int in_v)
{
	return (value + (wanted_v - out_v) * in_v * 10.00);
}

